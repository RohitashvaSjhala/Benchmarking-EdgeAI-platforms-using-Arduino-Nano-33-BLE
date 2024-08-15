#include <Profiler.h>

/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <Arduino_LSM9DS1.h>
#include <TensorFlowLite.h>

#include "constants.h"
#include "main_functions.h"
#include "model.h"
//#include "output_handler.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_log.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"

// Globals, used for compatibility with Arduino-style sketches.
namespace {
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

constexpr int kTensorArenaSize = 20 * 1024;
// Keep aligned to 16 bytes for CMSIS
alignas(16) uint8_t tensor_arena[kTensorArenaSize];
}  // namespace

// The name of this function is important for Arduino compatibility.
void setup() {
  tflite::InitializeTarget();

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  model = tflite::GetModel(g_model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    MicroPrintf(
        "Model provided is schema version %d not equal "
        "to supported version %d.",
        model->version(), TFLITE_SCHEMA_VERSION);
    return;
  }

  // This pulls in all the operation implementations we need.
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::AllOpsResolver resolver;

  // Build an interpreter to run the model with.
  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensor_arena, kTensorArenaSize);
  interpreter = &static_interpreter;
  
  //how much memory your tensors are expected to use
  //Serial.println(input->bytes);
  
  // Allocate memory from the tensor_arena for the model's tensors.
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk) {
    MicroPrintf("AllocateTensors() failed");
    return;
  }

  // Obtain pointers to the model's input and output tensors.
  input = interpreter->input(0);
  output = interpreter->output(0);

  // Keep track of how many inferences we have performed.
  inference_count = 0;
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  MicroPrintf("Setup Fininshed!");
}

// The name of this function is important for Arduino compatibility.
void loop() {
  // Calculate an x value to feed into the model. We compare the current
  // inference_count to the number of inferences per cycle to determine
  // our position within the range of possible x values the model was
  // trained on, and use this to calculate a value.
  // float position = static_cast<float>(inference_count) /
  //                  static_cast<float>(kInferencesPerCycle);
  // float x = position * kXrange;

  // Quantize the input from floating-point to integer
  // int8_t x_quantized = x / input->params.scale + input->params.zero_point;
  // Place the quantized input in the model's input tensor
  // input->data.int8[0] = x_quantized;
  // Check input tensor size and dimensions
  // Serial.print("Input tensor size: ");
  // Serial.println(input->bytes / sizeof(float));  // Total number of floats the input tensor can hold


  // float x, y, z;
  // int index = 0;
  // for(int i=0; i<125; ++i) {
  //   if (IMU.accelerationAvailable()) {
  //     IMU.readAcceleration(x, y, z);
  //     if(index < 375) {
  //       int8_t x_quantized = x / input->params.scale + input->params.zero_point;
  //       int8_t y_quantized = y / input->params.scale + input->params.zero_point;
  //       int8_t z_quantized = z / input->params.scale + input->params.zero_point;
  //       input->data.int8[index++] = x_quantized;
  //       input->data.int8[index++] = y_quantized;
  //       input->data.int8[index++] = z_quantized;
  //     }
  //   }
  // }
  // Serial.print(input->dims->size);
  // Serial.print("  ");
  // Serial.print(input->dims->data[0]);
  // Serial.print("  ");
  // Serial.print(input->dims->data[1]);
  // Serial.print("  ");
  // Serial.print(input->dims->data[2]);
  // Serial.print("  ");
  // Serial.println(input->type);
  
  float x, y, z;
int index = 0;
while(index < 375) {  // Ensure we gather enough data
    if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(x, y, z);

        // Quantize each component
        int8_t x_quantized = (x / input->params.scale) + input->params.zero_point;
        int8_t y_quantized = (y / input->params.scale) + input->params.zero_point;
        int8_t z_quantized = (z / input->params.scale) + input->params.zero_point;

        // Store quantized values if there is space
        if(index + 2 < 375) { // Check to ensure we don't write out of bounds
            input->data.int8[index++] = x_quantized;
            input->data.int8[index++] = y_quantized;
            input->data.int8[index++] = z_quantized;
        }
    } else {
        delay(10); // Optionally delay if data not available yet
    }
}
  {
    profiler_t profiler;
  // Run inference, and report any error
  TfLiteStatus invoke_status = interpreter->Invoke();
  if (invoke_status != kTfLiteOk) {
    MicroPrintf("Invoke failed"); //on x: %f\n", static_cast<double>(x));
    return;
  }
  }
  // Obtain the quantized output from model's output tensor
  // int8_t y_quantized = output->data.int8[0];
  // Dequantize the output from integer to floating-point
  // float y = (y_quantized - output->params.zero_point) * output->params.scale;
  int number_of_classes = output->dims->data[1];
  // Serial.println(number_of_classes);

  float out[number_of_classes];
  for(int i=0; i<number_of_classes; i++) {
    out[i] = (output->data.int8[i] - output->params.zero_point) * output->params.scale;
    Serial.print(out[i]);
    //Serial.print(output->data.int8[i]);
    Serial.print("  ");
  }

  // Serial.print(output->dims->size);
  // Serial.print("  ");
  // Serial.print(output->dims->data[0]);
  // Serial.print("  ");
  // Serial.print(output->dims->data[1]);
  // Serial.print("  ");
  // Serial.println(output->type);
  // Output the results. A custom HandleOutput function can be implemented
  // for each supported hardware target.
  // HandleOutput(x, y);
  // Serial.print("Output tensor size: ");
  // Serial.println(output->bytes / sizeof(float));  // Total number of floats the input tensor can hold
  int predicted_class_index = 0;
  float max_value = out[0];
  for (int i = 1; i < number_of_classes; i++) {
    if (out[i] > max_value) {
        max_value = out[i];
        predicted_class_index = i;
    }
}
  // Serial.print(out[0]);
  // Serial.print('\t');
  // Serial.print(output->data.int8[1]);
  // Serial.print('\t');
  // Serial.print(output->data.int8[2]);
  // Serial.print('\t');
  // Serial.print(output->data.int8[3]);
  // Serial.print('\t');
  // Serial.print(output->data.int8[4]);
  // Serial.print('\t');
  // Serial.println(output->data.int8[5]);
  // Serial.print("Predicted Class Index: ");
  // Serial.println(predicted_class_index);

  // Map the index to class label
  const char* class_labels[] = {"Walking", "Jogging", "Sitting", "Upstairs", "Downstairs", "Standing"};
  Serial.print("Predicted Class Label: ");
  Serial.println(class_labels[predicted_class_index]);
  // Increment the inference_counter, and reset it if we have reached
  // the total number per cycle
  // inference_count += 1;
  // if (inference_count >= kInferencesPerCycle) inference_count = 0;
  // MicroPrintf("Final stage finished!");
  Serial.println();
  //delay(3000);
}

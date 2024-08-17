extern "C" {
  #include <CodeGenFullDataset.h>
}

#include <Arduino_LSM9DS1.h> 

#define INPUT_LENGTH 3        
#define TIME_WINDOW_SIZE 125   
#define INTERVAL_MS 10        

#define IMAI_API_QUEUE_NO_TIMESTAMPS

void classifySensorData(float *data, int length);

float inputBuffer[TIME_WINDOW_SIZE][INPUT_LENGTH];
int inputIndex = 0;

// Setup function
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (true);
  }

  // IMAI_init();
  // Serial.println("Model and IMU initialized successfully.");
}

void loop() {
  float x, y, z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    
    inputBuffer[inputIndex][0] = x;
    inputBuffer[inputIndex][1] = y;
    inputBuffer[inputIndex][2] = z;
    inputIndex++; 
    if (inputIndex == TIME_WINDOW_SIZE) {
      inputIndex = 0;
      classifySensorData(&inputBuffer[0][0], TIME_WINDOW_SIZE*INPUT_LENGTH);
    }
  }
}


void classifySensorData(float *data, int length) {
  IMAI_init();
  float output[7]; 
  int result=10;
  Serial.println("Feeding data to Enqueue");
  for (int i = 0; i < length; i += INPUT_LENGTH) {
    float sample[INPUT_LENGTH] = { data[i], data[i + 1], data[i + 2] };
    result = IMAI_enqueue(sample);
    if (result != 0) {
      Serial.println("Error enqueuing data!");
      return;
    }
  }
  result = IMAI_dequeue(output);
  Serial.print(output[0]);
  Serial.print(", ");
  Serial.print(output[1]);
  Serial.print(", ");
  Serial.print(output[2]);
  Serial.print(", ");
  Serial.print(output[3]);
  Serial.print(", ");
  Serial.print(output[4]);
  Serial.print(", ");
  Serial.print(output[5]);
  Serial.print(", ");
  Serial.println(output[6]);
}

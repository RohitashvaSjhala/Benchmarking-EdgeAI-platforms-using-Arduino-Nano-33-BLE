#include <Net_predict.h>
#include <Net_predict_data.h>
#include <Net_predict_initialize.h>
#include <Net_predict_internal_types.h>
#include <Net_predict_terminate.h>
#include <Net_predict_types.h>
#include <SoftmaxLayer.h>
#include <callPredict.h>
#include <conv2dDirectOptimizedColMajor.h>
#include <predict.h>
#include <rtGetInf.h>
#include <rtGetNaN.h>
#include <rt_nonfinite.h>
#include <rtwtypes.h>

#include <Arduino_LSM9DS1.h>


float in[450];
dlarray out;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  // if (!IMU.begin()) {
  //   Serial.println("Failed to initialize IMU!");
  //   while (1);
  // }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (IMU.accelerationAvailable()) {
    float x, y, z;
    for(int i=0;i<450;i++) {
      IMU.readAcceleration(x, y, z);
      in[i] = x;
      //Serial.print(in[i]);
      in[i++] = y;
      //Serial.print(in[i]);
      in[i++] = z;
      //Serial.print(in[i]);
    }
  }

  Net_predict(in, &out);


  // Serial.print(out.Data[0]);
  // Serial.print('\t');
  // Serial.print(out.Data[1]);
  // Serial.print('\t');
  // Serial.print(out.Data[2]);
  // Serial.print('\t');
  // Serial.print(out.Data[3]);
  // Serial.print('\t');
  // Serial.print(out.Data[4]);
  // Serial.print('\t');
  // Serial.println(out.Data[5]);
  // Serial.print(id_class);
  // Serial.print('\t');
  // Serial.println(id2class[id_class]);
  delay(1000);

}
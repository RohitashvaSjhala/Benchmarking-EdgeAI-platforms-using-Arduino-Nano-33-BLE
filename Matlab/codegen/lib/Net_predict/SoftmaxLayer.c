/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SoftmaxLayer.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "SoftmaxLayer.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const float X1_Data[6]
 *                float Z1_Data[6]
 * Return Type  : void
 */
void SoftmaxLayer_predict(const float X1_Data[6], float Z1_Data[6])
{
  float maxVal;
  float sumX;
  int idx;
  int k;
  if (!rtIsNaNF(X1_Data[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!rtIsNaNF(X1_Data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    maxVal = X1_Data[0];
  } else {
    maxVal = X1_Data[idx - 1];
    idx++;
    for (k = idx; k < 7; k++) {
      sumX = X1_Data[k - 1];
      if (maxVal < sumX) {
        maxVal = sumX;
      }
    }
  }
  for (idx = 0; idx < 6; idx++) {
    Z1_Data[idx] = expf(X1_Data[idx] - maxVal);
  }
  sumX = Z1_Data[0];
  for (k = 0; k < 5; k++) {
    sumX += Z1_Data[k + 1];
  }
  for (idx = 0; idx < 6; idx++) {
    Z1_Data[idx] /= sumX;
  }
}

/*
 * File trailer for SoftmaxLayer.c
 *
 * [EOF]
 */

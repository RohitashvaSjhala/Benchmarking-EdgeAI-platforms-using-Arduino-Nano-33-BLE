/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SoftmaxLayer.c
 *
 * Code generation for function 'SoftmaxLayer'
 *
 */

/* Include files */
#include "SoftmaxLayer.h"
#include "Net_predict_data.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <xmmintrin.h>

/* Function Definitions */
void SoftmaxLayer_predict(const real32_T X1_Data[6], real32_T Z1_Data[6])
{
  int32_T idx;
  int32_T k;
  real32_T maxVal;
  real32_T y;
  if (!muSingleScalarIsNaN(X1_Data[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!muSingleScalarIsNaN(X1_Data[k - 1])) {
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
      y = X1_Data[k - 1];
      if (maxVal < y) {
        maxVal = y;
      }
    }
  }
  _mm_storeu_ps(&Z1_Data[0],
                _mm_sub_ps(_mm_loadu_ps(&X1_Data[0]), _mm_set1_ps(maxVal)));
  Z1_Data[4] = X1_Data[4] - maxVal;
  Z1_Data[5] = X1_Data[5] - maxVal;
  for (idx = 0; idx < 6; idx++) {
    Z1_Data[idx] = muSingleScalarExp(Z1_Data[idx]);
  }
  __m128 r;
  y = sumColumnB(Z1_Data);
  r = _mm_loadu_ps(&Z1_Data[0]);
  _mm_storeu_ps(&Z1_Data[0], _mm_div_ps(r, _mm_set1_ps(y)));
  Z1_Data[4] /= y;
  Z1_Data[5] /= y;
}

/* End of code generation (SoftmaxLayer.c) */

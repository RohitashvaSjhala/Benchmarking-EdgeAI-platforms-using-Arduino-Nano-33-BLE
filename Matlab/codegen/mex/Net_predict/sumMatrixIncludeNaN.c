/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "Net_predict_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real32_T sumColumnB(const real32_T x[6])
{
  int32_T k;
  real32_T y;
  y = x[0];
  for (k = 0; k < 5; k++) {
    y += x[k + 1];
  }
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */

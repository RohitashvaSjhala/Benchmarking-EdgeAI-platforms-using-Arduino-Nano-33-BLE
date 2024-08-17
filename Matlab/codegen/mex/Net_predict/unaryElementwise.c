/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unaryElementwise.c
 *
 * Code generation for function 'unaryElementwise'
 *
 */

/* Include files */
#include "unaryElementwise.h"
#include "Net_predict_data.h"
#include "rt_nonfinite.h"
#include <xmmintrin.h>

/* Function Declarations */
static void elementwise_relu(const emlrtStack *sp, const real32_T *inputTensor,
                             real32_T *outputTensor);

/* Function Definitions */
static void elementwise_relu(const emlrtStack *sp, const real32_T *inputTensor,
                             real32_T *outputTensor)
{
  __m128 reluZero;
  int32_T simdBlockIdx;
  reluZero = _mm_set1_ps(0.0F);
  for (simdBlockIdx = 0; simdBlockIdx < 8; simdBlockIdx++) {
    __m128 reg_0;
    int32_T baseIdx;
    baseIdx = simdBlockIdx << 2;
    reg_0 = _mm_loadu_ps(&inputTensor[baseIdx]);
    reg_0 = _mm_max_ps(reg_0, reluZero);
    _mm_storeu_ps(&outputTensor[baseIdx], reg_0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

void unaryElementwise(const emlrtStack *sp, const real32_T X[32],
                      real32_T Z[32])
{
  elementwise_relu(sp, &X[0], &Z[0]);
}

/* End of code generation (unaryElementwise.c) */

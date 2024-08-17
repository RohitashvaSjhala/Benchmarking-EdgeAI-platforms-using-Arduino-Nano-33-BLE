/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * callPredict.h
 *
 * Code generation for function 'callPredict'
 *
 */

#pragma once

/* Include files */
#include "Net_predict_internal_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void dlnetwork_callPredict(const emlrtStack *sp,
                           c_coder_internal_ctarget_dlnetw *obj,
                           const real32_T inputsT_0_f1[450],
                           real32_T outputs_0_f1[6]);

/* End of code generation (callPredict.h) */

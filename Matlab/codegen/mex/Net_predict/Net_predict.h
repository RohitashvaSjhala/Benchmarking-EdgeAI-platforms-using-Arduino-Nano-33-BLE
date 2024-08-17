/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Net_predict.h
 *
 * Code generation for function 'Net_predict'
 *
 */

#pragma once

/* Include files */
#include "Net_predict_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Net_predict(const emlrtStack *sp, const real32_T in[450], dlarray *out);

void Net_predict_delete(void);

void Net_predict_init(void);

void Net_predict_new(void);

/* End of code generation (Net_predict.h) */

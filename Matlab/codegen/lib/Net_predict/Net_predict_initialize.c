/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Net_predict_initialize.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "Net_predict_initialize.h"
#include "Net_predict.h"
#include "Net_predict_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_initialize(void)
{
  Net_predict_new();
  Net_predict_init();
  isInitialized_Net_predict = true;
}

/*
 * File trailer for Net_predict_initialize.c
 *
 * [EOF]
 */

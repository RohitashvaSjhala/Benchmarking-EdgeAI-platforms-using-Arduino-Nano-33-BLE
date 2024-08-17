/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predict.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

#ifndef PREDICT_H
#define PREDICT_H

/* Include Files */
#include "Net_predict_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void dlnetwork_predict(c_coder_internal_ctarget_dlnetw *obj,
                       const float varargin_1_Data[450],
                       float varargout_1_Data[6]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for predict.h
 *
 * [EOF]
 */

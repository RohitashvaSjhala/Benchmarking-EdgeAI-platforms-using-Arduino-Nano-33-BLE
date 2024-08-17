/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predict.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "predict.h"
#include "Net_predict_internal_types.h"
#include "callPredict.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : c_coder_internal_ctarget_dlnetw *obj
 *                const float varargin_1_Data[450]
 *                float varargout_1_Data[6]
 * Return Type  : void
 */
void dlnetwork_predict(c_coder_internal_ctarget_dlnetw *obj,
                       const float varargin_1_Data[450],
                       float varargout_1_Data[6])
{
  dlnetwork_callPredict(obj, varargin_1_Data, varargout_1_Data);
}

/*
 * File trailer for predict.c
 *
 * [EOF]
 */

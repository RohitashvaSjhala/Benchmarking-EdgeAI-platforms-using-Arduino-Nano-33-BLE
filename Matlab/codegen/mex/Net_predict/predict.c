/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predict.c
 *
 * Code generation for function 'predict'
 *
 */

/* Include files */
#include "predict.h"
#include "Net_predict_data.h"
#include "Net_predict_internal_types.h"
#include "callPredict.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = {
    1,                   /* lineNo */
    "dlnetwork/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@dlnetwork\\predict.p" /* pathName */
};

/* Function Definitions */
void dlnetwork_predict(const emlrtStack *sp,
                       c_coder_internal_ctarget_dlnetw *obj,
                       const real32_T varargin_1_Data[450],
                       real32_T varargout_1_Data[6])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &i_emlrtRSI;
  dlnetwork_callPredict(&st, obj, varargin_1_Data, varargout_1_Data);
}

/* End of code generation (predict.c) */

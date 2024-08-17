/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Net_predict.c
 *
 * Code generation for function 'Net_predict'
 *
 */

/* Include files */
#include "Net_predict.h"
#include "Net_predict_data.h"
#include "Net_predict_internal_types.h"
#include "Net_predict_types.h"
#include "predict.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static c_coder_internal_ctarget_dlnetw mydlnet;

static boolean_T mydlnet_not_empty;

static emlrtRSInfo emlrtRSI = {
    14,                                                /* lineNo */
    "Net_predict",                                     /* fcnName */
    "C:\\Users\\metal\\Desktop\\MATLAB\\Net_predict.m" /* pathName */
};

/* Function Definitions */
void Net_predict(const emlrtStack *sp, const real32_T in[450], dlarray *out)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  /* global quantizedNet */
  /* mynet = coder.loadDeepLearningNetwork('matlab_trainnet_object.mat'); */
  /* mynet = quantizedNet; */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, !mydlnet_not_empty)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
    /*  Load the network only if it has not been loaded before */
    mydlnet.IsNetworkInitialized = false;
    mydlnet.matlabCodegenIsDeleted = false;
    mydlnet_not_empty = true;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
  st.site = &emlrtRSI;
  dlnetwork_predict(&st, &mydlnet, in, out->Data);
}

void Net_predict_delete(void)
{
  if (!mydlnet.matlabCodegenIsDeleted) {
    mydlnet.matlabCodegenIsDeleted = true;
  }
}

void Net_predict_init(void)
{
  mydlnet_not_empty = false;
}

void Net_predict_new(void)
{
  mydlnet.matlabCodegenIsDeleted = true;
}

/* End of code generation (Net_predict.c) */

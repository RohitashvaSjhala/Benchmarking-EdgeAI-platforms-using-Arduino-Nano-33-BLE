/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Net_predict_mex.c
 *
 * Code generation for function '_coder_Net_predict_mex'
 *
 */

/* Include files */
#include "_coder_Net_predict_mex.h"
#include "Net_predict_data.h"
#include "Net_predict_initialize.h"
#include "Net_predict_terminate.h"
#include "_coder_Net_predict_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Net_predict_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                             const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        11, "Net_predict");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "Net_predict");
  }
  /* Call the function. */
  Net_predict_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Net_predict_atexit);
  /* Module initialization. */
  Net_predict_initialize();
  /* Dispatch the entry-point. */
  Net_predict_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  Net_predict_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Net_predict_mex.c) */

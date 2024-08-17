/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Net_predict_initialize.c
 *
 * Code generation for function 'Net_predict_initialize'
 *
 */

/* Include files */
#include "Net_predict_initialize.h"
#include "Net_predict.h"
#include "Net_predict_data.h"
#include "_coder_Net_predict_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Net_predict_once(void);

/* Function Definitions */
static void Net_predict_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\metal\\Desktop\\MATLAB\\Net_predict.m", 0U, 1U,
                  2U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "Net_predict", 0, -1, 433);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 326, -1, 429);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 250, -1, 320);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 165, 184, -1, 324);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  Net_predict_new();
  Net_predict_init();
}

void Net_predict_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "neural_network_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Net_predict_once();
  }
}

/* End of code generation (Net_predict_initialize.c) */

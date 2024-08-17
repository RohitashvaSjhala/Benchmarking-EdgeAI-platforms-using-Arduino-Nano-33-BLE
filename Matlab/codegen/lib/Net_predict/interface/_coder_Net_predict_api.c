/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Net_predict_api.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "_coder_Net_predict_api.h"
#include "_coder_Net_predict_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "Net_predict",                                        /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                     const emlrtMsgIdentifier *parentId))[450];

static real32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId))[450];

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static real32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[450];

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const dlarray u);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T (*)[450]
 */
static real32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                     const emlrtMsgIdentifier *parentId))[450]
{
  real32_T(*y)[450];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T (*)[450]
 */
static real32_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId))[450]
{
  static const int32_T dims[2] = {150, 3};
  int32_T iv[2];
  real32_T(*ret)[450];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real32_T(*)[450])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const void *r
 * Return Type  : void
 */
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real32_T (*)[450]
 */
static real32_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[450]
{
  emlrtMsgIdentifier thisId;
  real32_T(*y)[450];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const dlarray u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const dlarray u)
{
  static const int32_T iv[2] = {1, 2};
  static const int32_T iv1[2] = {1, 0};
  static const int32_T iv2[2] = {1, 0};
  static const int32_T iv3[2] = {1, 24};
  static const int32_T i = 6;
  static const char_T c_u[24] = {'(', 'C', ')', ' ', 'x', ' ', '(', 'B',
                                 ')', ' ', 's', 'i', 'n', 'g', 'l', 'e',
                                 ' ', 'd', 'l', 'a', 'r', 'r', 'a', 'y'};
  static const char_T b_u[2] = {'C', 'B'};
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T b_i;
  real32_T *pData;
  const char_T *propClasses[5] = {
      "deep.internal.coder.dlarray", "deep.internal.coder.dlarray",
      "deep.internal.coder.dlarray", "deep.internal.coder.dlarray",
      "deep.internal.coder.dlarray"};
  const char_T *propNames[5] = {"Data", "DimensionMetadata", "ViewToDataMap",
                                "DataToViewMap",
                                "matlabCodegenUserReadableName"};
  y = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance2022a((emlrtCTX)sp,
                                                "deep.internal.coder.dlarray"));
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m1);
  for (b_i = 0; b_i < 6; b_i++) {
    pData[b_i] = u.Data[b_i];
  }
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m2 = NULL;
  c_y = NULL;
  m1 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 2, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtAssign(&m2, c_y);
  propValues[1] = m2;
  m3 = NULL;
  d_y = NULL;
  m1 =
      emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&d_y, m1);
  emlrtAssign(&m3, d_y);
  propValues[2] = m3;
  m4 = NULL;
  e_y = NULL;
  m1 =
      emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&e_y, m1);
  emlrtAssign(&m4, e_y);
  propValues[3] = m4;
  m5 = NULL;
  f_y = NULL;
  m1 = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 24, m1, &c_u[0]);
  emlrtAssign(&f_y, m1);
  emlrtAssign(&m5, f_y);
  propValues[4] = m5;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 5, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0, "deep.internal.coder.dlarray"));
  return y;
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void Net_predict_api(const mxArray *prhs, const mxArray **plhs)
{
  dlarray out;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real32_T(*in)[450];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  in = emlrt_marshallIn(&st, emlrtAlias(prhs), "in");
  /* Invoke the target function */
  Net_predict(*in, &out);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, out);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Net_predict_xil_terminate();
  Net_predict_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_Net_predict_api.c
 *
 * [EOF]
 */

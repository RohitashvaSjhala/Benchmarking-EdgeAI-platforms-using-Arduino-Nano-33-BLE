/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Net_predict_api.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

#ifndef _CODER_NET_PREDICT_API_H
#define _CODER_NET_PREDICT_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_dlarray
#define typedef_dlarray
typedef struct {
  real32_T Data[6];
} dlarray;
#endif /* typedef_dlarray */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Net_predict(real32_T in[450], dlarray *out);

void Net_predict_api(const mxArray *prhs, const mxArray **plhs);

void Net_predict_atexit(void);

void Net_predict_initialize(void);

void Net_predict_terminate(void);

void Net_predict_xil_shutdown(void);

void Net_predict_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Net_predict_api.h
 *
 * [EOF]
 */

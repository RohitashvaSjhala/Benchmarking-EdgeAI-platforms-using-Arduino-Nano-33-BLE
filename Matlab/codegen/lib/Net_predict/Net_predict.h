/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Net_predict.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

#ifndef NET_PREDICT_H
#define NET_PREDICT_H

/* Include Files */
#include "Net_predict_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Net_predict(const float in[450], dlarray *out);

void Net_predict_delete(void);

void Net_predict_init(void);

void Net_predict_new(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Net_predict.h
 *
 * [EOF]
 */

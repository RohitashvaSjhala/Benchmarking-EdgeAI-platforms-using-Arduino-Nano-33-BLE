/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: callPredict.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

#ifndef CALLPREDICT_H
#define CALLPREDICT_H

/* Include Files */
#include "Net_predict_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void dlnetwork_callPredict(c_coder_internal_ctarget_dlnetw *obj,
                           const float inputsT_0_f1[450],
                           float outputs_0_f1[6]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for callPredict.h
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Net_predict.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "Net_predict.h"
#include "Net_predict_data.h"
#include "Net_predict_initialize.h"
#include "Net_predict_internal_types.h"
#include "Net_predict_types.h"
#include "predict.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static c_coder_internal_ctarget_dlnetw mydlnet;

static bool mydlnet_not_empty;

/* Function Definitions */
/*
 * Arguments    : const float in[450]
 *                dlarray *out
 * Return Type  : void
 */
void Net_predict(const float in[450], dlarray *out)
{
  if (!isInitialized_Net_predict) {
    Net_predict_initialize();
  }
  /* global quantizedNet */
  /* mynet = coder.loadDeepLearningNetwork('matlab_trainnet_object.mat'); */
  /* mynet = quantizedNet; */
  if (!mydlnet_not_empty) {
    /*  Load the network only if it has not been loaded before */
    mydlnet.IsNetworkInitialized = false;
    mydlnet.matlabCodegenIsDeleted = false;
    mydlnet_not_empty = true;
  }
  dlnetwork_predict(&mydlnet, in, out->Data);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_delete(void)
{
  if (!mydlnet.matlabCodegenIsDeleted) {
    mydlnet.matlabCodegenIsDeleted = true;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_init(void)
{
  mydlnet_not_empty = false;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Net_predict_new(void)
{
  mydlnet.matlabCodegenIsDeleted = true;
}

/*
 * File trailer for Net_predict.c
 *
 * [EOF]
 */

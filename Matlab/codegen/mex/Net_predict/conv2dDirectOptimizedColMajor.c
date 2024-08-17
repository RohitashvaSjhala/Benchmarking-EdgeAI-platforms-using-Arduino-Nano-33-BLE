/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * conv2dDirectOptimizedColMajor.c
 *
 * Code generation for function 'conv2dDirectOptimizedColMajor'
 *
 */

/* Include files */
#include "conv2dDirectOptimizedColMajor.h"
#include "Net_predict_data.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <xmmintrin.h>

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    1,                               /* lineNo */
    "conv2dDirectOptimizedColMajor", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\conv2dDirectOptimizedColMajor.p" /* pathName */
};

/* Function Declarations */
static void convolution(const emlrtStack *sp, const real32_T *inputTensor,
                        real32_T *outputTensor, const real32_T *weightsTensor,
                        const real32_T *biasTensor);

static void convolutionKernel(const emlrtStack *sp,
                              const real32_T *inputBufferPtr,
                              real32_T *outputBufferPtr,
                              const real32_T *weightsBufferPtr,
                              const real32_T *biasBufferPtr);

/* Function Definitions */
static void convolution(const emlrtStack *sp, const real32_T *inputTensor,
                        real32_T *outputTensor, const real32_T *weightsTensor,
                        const real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[456];
  static boolean_T bufferInitialized;
  int32_T c_inputChannelMiniblockBaseIdxS;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 1824U);
    bufferInitialized = true;
  }
  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 150;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 150;
    c_inputChannelMiniblockBaseIdxS = fusedInputWidthAndHeightIdx * 3 + 3;
    inputScratchpadBuffer[c_inputChannelMiniblockBaseIdxS] =
        inputTensor[fusedInputWidthAndHeightIdx];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    inputScratchpadBuffer[c_inputChannelMiniblockBaseIdxS + 1] =
        inputTensor[fusedInputWidthAndHeightIdx + 150];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    inputScratchpadBuffer[c_inputChannelMiniblockBaseIdxS + 2] =
        inputTensor[fusedInputWidthAndHeightIdx + 300];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 300;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx / 150;
    c_inputChannelMiniblockBaseIdxS = fusedInputChannelMiniBlockIdx % 150;
    convolutionKernel(
        sp, &inputScratchpadBuffer[c_inputChannelMiniblockBaseIdxS * 3],
        &outputTensor[(c_inputChannelMiniblockBaseIdxS << 2) +
                      fusedInputWidthAndHeightIdx * 2400],
        &weightsTensor[fusedInputWidthAndHeightIdx * 144],
        &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
}

static void convolutionKernel(const emlrtStack *sp,
                              const real32_T *inputBufferPtr,
                              real32_T *outputBufferPtr,
                              const real32_T *weightsBufferPtr,
                              const real32_T *biasBufferPtr)
{
  __m128 b_outputRegister;
  __m128 c_outputRegister;
  __m128 d_outputRegister;
  __m128 outputRegister;
  __m128 reluZero;
  int32_T c_idxToStrideInputBufferAlongWi;
  int32_T kernelWidthIdx;
  int32_T weightsIdx;
  reluZero = _mm_set1_ps(0.0F);
  outputRegister = _mm_loadu_ps(&biasBufferPtr[0]);
  b_outputRegister = _mm_loadu_ps(&biasBufferPtr[4]);
  c_outputRegister = _mm_loadu_ps(&biasBufferPtr[8]);
  d_outputRegister = _mm_loadu_ps(&biasBufferPtr[12]);
  c_idxToStrideInputBufferAlongWi = 0;
  weightsIdx = 0;
  for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
    __m128 inputRegister;
    __m128 weightsRegister;
    inputRegister =
        _mm_set1_ps(inputBufferPtr[c_idxToStrideInputBufferAlongWi]);
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx]);
    outputRegister =
        _mm_add_ps(outputRegister, _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 36]);
    b_outputRegister = _mm_add_ps(b_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 72]);
    c_outputRegister = _mm_add_ps(c_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 108]);
    d_outputRegister = _mm_add_ps(d_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    inputRegister =
        _mm_set1_ps(inputBufferPtr[c_idxToStrideInputBufferAlongWi + 1]);
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 4]);
    outputRegister =
        _mm_add_ps(outputRegister, _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 40]);
    b_outputRegister = _mm_add_ps(b_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 76]);
    c_outputRegister = _mm_add_ps(c_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 112]);
    d_outputRegister = _mm_add_ps(d_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    inputRegister =
        _mm_set1_ps(inputBufferPtr[c_idxToStrideInputBufferAlongWi + 2]);
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 8]);
    outputRegister =
        _mm_add_ps(outputRegister, _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 44]);
    b_outputRegister = _mm_add_ps(b_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 80]);
    c_outputRegister = _mm_add_ps(c_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    weightsRegister = _mm_loadu_ps(&weightsBufferPtr[weightsIdx + 116]);
    d_outputRegister = _mm_add_ps(d_outputRegister,
                                  _mm_mul_ps(inputRegister, weightsRegister));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    weightsIdx += 12;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    c_idxToStrideInputBufferAlongWi += 3;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  _mm_storeu_ps(&outputBufferPtr[0], _mm_max_ps(outputRegister, reluZero));
  _mm_storeu_ps(&outputBufferPtr[600], _mm_max_ps(b_outputRegister, reluZero));
  _mm_storeu_ps(&outputBufferPtr[1200], _mm_max_ps(c_outputRegister, reluZero));
  _mm_storeu_ps(&outputBufferPtr[1800], _mm_max_ps(d_outputRegister, reluZero));
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
}

void conv2dDirectOptimizedColMajor(const emlrtStack *sp, const real32_T X[450],
                                   real32_T Z[4800])
{
  static const real32_T reformattedAndTruncatedWeights[288] = {
      0.0637785569F,   -0.131001309F,  0.00121307885F,  -0.0624183528F,
      -0.563906431F,   -0.542498887F,  -0.408594638F,   0.48346132F,
      -0.0958373F,     -0.15610522F,   0.110167F,       0.0645236894F,
      -0.0296062138F,  -0.038164027F,  0.211496577F,    -0.152819455F,
      -0.289553761F,   -0.0330030099F, -0.490069389F,   0.237924188F,
      -0.248624519F,   -0.0780485943F, -0.203453019F,   0.195322901F,
      -0.140499011F,   -0.145787582F,  0.163850725F,    0.221031055F,
      -0.516254604F,   0.499182165F,   -0.662330568F,   0.267524838F,
      -0.524572968F,   0.137854919F,   -0.0604426078F,  -0.182004765F,
      -0.2080248F,     0.228562072F,   0.0636672303F,   0.208032772F,
      -0.841564775F,   0.0871117115F,  0.0587204695F,   -0.45298034F,
      -0.114126936F,   0.207344845F,   -0.684722543F,   -0.136455417F,
      -0.0413517803F,  0.188458592F,   -0.194215283F,   -0.14890635F,
      0.260177672F,    -0.0397148579F, 0.0498750471F,   -0.235547528F,
      0.0510602146F,   0.113952219F,   -0.542811275F,   -0.175497085F,
      -0.21767585F,    0.255012184F,   0.0677830279F,   -0.0809694529F,
      0.497708023F,    0.00622011721F, 0.244300961F,    -0.468265951F,
      0.0237407889F,   0.0481836572F,  -0.525181592F,   -0.348924756F,
      0.0454810634F,   0.303278536F,   -0.325301379F,   -0.151387677F,
      0.0365071781F,   0.30499655F,    0.206562161F,    -0.202316061F,
      -0.136149123F,   -0.0741604418F, -0.288601726F,   0.200619414F,
      -0.0260297917F,  0.0640409291F,  -0.183496296F,   0.36531347F,
      -0.105686575F,   0.163126767F,   0.182297111F,    0.0929691121F,
      0.0181551855F,   0.21085839F,    0.0849827528F,   0.230100259F,
      -0.00369047513F, 0.388505429F,   -0.32727465F,    0.0425914153F,
      0.0777171552F,   0.137291804F,   -0.0678673759F,  -0.241147846F,
      0.125224292F,    -0.339379549F,  -0.191299766F,   0.294261903F,
      0.121269323F,    0.254866928F,   -0.0164137501F,  0.0390450507F,
      0.0143160382F,   0.239306569F,   -0.0491735861F,  -0.485723555F,
      0.0025892125F,   0.492529124F,   -0.0355611071F,  0.242850482F,
      -0.0852608383F,  0.222625107F,   0.104257889F,    -0.0386930965F,
      -0.0241111238F,  -0.262665451F,  0.000567409385F, 0.152893618F,
      0.00402124319F,  -0.568381667F,  -0.0521773286F,  -0.37425679F,
      -0.0432765782F,  0.246492103F,   -0.0421705F,     0.310827076F,
      0.0117361154F,   -0.243051663F,  -0.0340505019F,  -0.273240209F,
      -0.00189253432F, -0.188262835F,  -0.0307621416F,  -0.473892599F,
      0.410376132F,    0.111143425F,   0.695494473F,    0.084587872F,
      -0.125322819F,   0.454164386F,   0.0863331854F,   0.0929473042F,
      -0.434080243F,   -0.0379340239F, -0.239356875F,   -0.612110078F,
      0.281004757F,    0.179695413F,   0.0534727834F,   0.0422138646F,
      -0.206242383F,   0.263151497F,   0.0877174586F,   0.0443140678F,
      0.0860620737F,   0.0461034887F,  0.234190509F,    -0.418593377F,
      0.390432F,       -0.341249704F,  -0.814361095F,   -0.19463551F,
      -0.272673458F,   0.405022889F,   0.250906259F,    -0.180163532F,
      0.267626762F,    0.00825182814F, 0.00980473589F,  -0.681699872F,
      -0.00460051186F, 0.319935381F,   0.0133243185F,   -0.0843303204F,
      -0.18206504F,    -0.215586081F,  -0.520647287F,   -0.438953131F,
      -0.41313234F,    0.287979513F,   -0.12204174F,    0.124009781F,
      0.156366348F,    0.162100047F,   0.291960269F,    -0.182519495F,
      -0.108588941F,   -0.106265515F,  -0.0406587273F,  -0.480290294F,
      -0.285540849F,   0.281566352F,   -0.399129748F,   0.123123728F,
      -0.112778075F,   -0.181543663F,  0.259425819F,    0.074644886F,
      -0.201347932F,   -0.295284808F,  -0.214023724F,   -0.373257697F,
      -0.00553782145F, 0.143595457F,   -0.630941808F,   0.206752434F,
      -0.0127554042F,  -0.159783632F,  0.0366597548F,   -0.0445589237F,
      0.194272205F,    -0.287713796F,  0.31531924F,     0.1585951F,
      0.463407189F,    -0.536908269F,  -0.462128907F,   0.0954655632F,
      0.105356328F,    -0.27194047F,   -0.236273304F,   0.222810894F,
      -0.0770945F,     -0.146267533F,  0.159604594F,    -0.133267328F,
      0.249216095F,    -0.313562602F,  -0.407728106F,   0.07256639F,
      -0.163526818F,   -0.216126889F,  -0.132319853F,   -0.0410321616F,
      -0.133840293F,   -0.301609397F,  0.193985075F,    0.163919374F,
      0.38043952F,     -0.351383835F,  -0.518574774F,   0.0706080645F,
      -0.370534122F,   0.321380883F,   0.358997434F,    0.086061433F,
      0.258236319F,    -0.506624F,     -0.420130372F,   -0.0229658503F,
      -0.0563877672F,  0.355574578F,   -0.0687757F,     -0.506815791F,
      0.289942026F,    0.142255321F,   -0.0960100144F,  0.0801132247F,
      -0.0299802441F,  0.27554971F,    -0.319609702F,   0.196994334F,
      0.0414674468F,   0.153675035F,   -0.322404F,      0.143223643F,
      0.240662649F,    -0.0975020453F, 0.0227326266F,   -0.0396945328F,
      0.280848503F,    -0.352336943F,  -0.336784631F,   -0.37575841F,
      0.145645618F,    0.363617688F,   -0.362825066F,   -0.368010432F};
  static const real32_T biasReformatted[32] = {
      -0.38452965F,   -0.0941114053F,  0.205353454F,    -0.209668353F,
      -0.126789555F,  0.0894418731F,   0.262929499F,    -0.182222188F,
      0.0181563515F,  -0.132646412F,   -0.00309059327F, -0.0341328308F,
      -0.042925477F,  -0.125559986F,   0.100246303F,    -0.0851229802F,
      -0.0155438734F, -0.216835514F,   -0.224941775F,   0.165393114F,
      0.13499406F,    -0.0592276976F,  -0.13546735F,    -0.170646444F,
      0.102507569F,   -0.00193023309F, -0.0731068179F,  0.0638988F,
      -0.127846345F,  -0.0312322509F,  -0.164012492F,   0.0649802387F};
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &r_emlrtRSI;
  convolution(&b_st, &X[0], &Z[0], &reformattedAndTruncatedWeights[0],
              &biasReformatted[0]);
}

/* End of code generation (conv2dDirectOptimizedColMajor.c) */

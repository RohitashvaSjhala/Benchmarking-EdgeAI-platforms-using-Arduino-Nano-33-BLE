/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * callPredict.c
 *
 * Code generation for function 'callPredict'
 *
 */

/* Include files */
#include "callPredict.h"
#include "Net_predict_data.h"
#include "Net_predict_internal_types.h"
#include "SoftmaxLayer.h"
#include "conv2dDirectOptimizedColMajor.h"
#include "rt_nonfinite.h"
#include "unaryElementwise.h"
#include "blas.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmmintrin.h>

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = {
    1,                              /* lineNo */
    "Network/setupAndResetNetwork", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\Network.p" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    1,                       /* lineNo */
    "dlnetwork/callPredict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@dlnetwork\\callPredict.p" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    1,                    /* lineNo */
    "profileRegionStart", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\gpucoder\\gpucoder\\+coder\\+"
    "gpu\\+internal\\profileRegionStart.p" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    1,                              /* lineNo */
    "dummyCodeRegionSim/regionEnd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\gpucoder\\gpucoder\\+coder\\+"
    "gpu\\+internal\\dummyCodeRegionSim.p" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    1,                        /* lineNo */
    "Network/getActivations", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\getActivations.p" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    1,                         /* lineNo */
    "iInvokeLayerPredictCall", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\getActivations.p" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    1,                           /* lineNo */
    "Network/invokePredictCall", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\invokePredictCall.p" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    1,                                 /* lineNo */
    "Convolution2DActivation/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\Convolution2DActivation.p" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    1,                    /* lineNo */
    "computeConvolution", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\+convUtils\\computeConvolution.p" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    1,                        /* lineNo */
    "Pooling2DLayer/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\Pooling2DLayer.p" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    1,                /* lineNo */
    "poolingForward", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\+poolingUtils\\poolingForward.p" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    1,                                /* lineNo */
    "FromBlockedLayoutLayer/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\FromBlockedLayoutLayer.p" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    1,                     /* lineNo */
    "doFromBlockedLayout", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\+layoutTransform\\doFromBlockedLayout.p" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    1,                             /* lineNo */
    "FullyConnectedLayer/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\FullyConnectedLayer.p" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    1,                       /* lineNo */
    "fullyConnectedForward", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\fullyConnectedForward.p" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    1,                        /* lineNo */
    "Network/callActivation", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\callActivation.p" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    1,                                      /* lineNo */
    "coderNetworkUtils/customLayerPredict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@coderNetworkUtils\\customLayerPredict.p" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    1,                    /* lineNo */
    "elementwiseForward", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\+elementwiseUtils\\elementwiseForward.p" /* pathName */
};

/* Function Declarations */
static char_T *
computeFilePathUsingEnvVariable(const char_T *unresolvedFilePath);

static char_T *extractCodegenFolderName(const char_T *filePath);

static void fromBlockedLayoutTransform(const emlrtStack *sp,
                                       const real32_T *inputTensor,
                                       real32_T *outputTensor);

static char_T *getCustomUserDataPathEnvVar(const char_T *unresolvedFilePath);

static int32_T getPositionOfLastFileSeparator(const char_T *filePath);

static char_T *getRelativePathToParentFolder(const char_T *filePath);

static char_T *getResolvedFilePath(const char_T *unresolvedFilePath);

static void maxPooling(const emlrtStack *sp, const real32_T *inputTensor,
                       real32_T *outputTensor);

static void maxPoolingKernel(const emlrtStack *sp,
                             const real32_T *inputBufferPtr,
                             real32_T *outputBufferPtr,
                             int32_T c_startIdxWithPaddingOffsetInpu);

static void readDnnConstants(real32_T *inputBufferPtr,
                             const char_T *unresolvedFilePath,
                             int32_T numElementsToRead);

static char_T *resolveBinaryFilePath(const char_T *unresolvedFilePath);

static char_T *sanitizeFilePathForHSP(const char_T *unSanitizedFilePath);

static void stringConcat(char_T *destinationString, const char_T *sourceString,
                         size_t destBufferSize);

static void throwFileNotFoundErrorMessage(const char_T *unresolvedFilePath,
                                          const char_T *sanitizedFilePath);

/* Function Definitions */
static char_T *computeFilePathUsingEnvVariable(const char_T *unresolvedFilePath)
{
  char_T *resolvedFilePath;
  char_T *stringDuplicate;
  size_t filePathLen;
  size_t sizeOfChar;
  filePathLen = strlen((char_T *)unresolvedFilePath) + 1;
  sizeOfChar = 1;
  stringDuplicate = (char_T *)calloc(filePathLen, sizeOfChar);
  stringConcat(stringDuplicate, unresolvedFilePath, filePathLen);
#if defined(MW_RUNTIME_DL_DATA_PATH) != 0
  extern char *mwGetRuntimeDLDataPath(const char *);
  resolvedFilePath = mwGetRuntimeDLDataPath((char_T *)unresolvedFilePath);
#elif defined(MW_DL_DATA_PATH) != 0
  resolvedFilePath = resolveBinaryFilePath(unresolvedFilePath);
#else
  char_T *coderDataPath;
  coderDataPath = getenv("CODER_DATA_PATH");
  if (coderDataPath != NULL) {
    resolvedFilePath = resolveBinaryFilePath(unresolvedFilePath);
  } else {
    resolvedFilePath = stringDuplicate;
  }
#endif
  return resolvedFilePath;
}

static char_T *extractCodegenFolderName(const char_T *filePath)
{
  int32_T posOfLastPathSeparator;
  char_T *codegenFolderName;
  size_t filePathLen;
  size_t sizeOfChar;
  /* this function allocates dynamic memory */
  filePathLen = strlen((char_T *)filePath) + 1;
  sizeOfChar = 1;
  codegenFolderName = (char_T *)calloc(filePathLen, sizeOfChar);
  posOfLastPathSeparator = getPositionOfLastFileSeparator(filePath);
  if (posOfLastPathSeparator != -1) {
    strncpy(codegenFolderName, (char_T *)filePath, posOfLastPathSeparator);
    codegenFolderName[posOfLastPathSeparator] = '\x00';
  } else {
    codegenFolderName[0] = '.';
    codegenFolderName[1] = '\x00';
  }
  return codegenFolderName;
}

static void fromBlockedLayoutTransform(const emlrtStack *sp,
                                       const real32_T *inputTensor,
                                       real32_T *outputTensor)
{
  int32_T fusedImageIdx;
  for (fusedImageIdx = 0; fusedImageIdx < 600; fusedImageIdx++) {
    int32_T blockIdx;
    int32_T fusedBlockIdx;
    int32_T outputTensorBaseIdx;
    fusedBlockIdx = fusedImageIdx % 600;
    blockIdx = fusedBlockIdx / 75;
    fusedBlockIdx %= 75;
    outputTensorBaseIdx = blockIdx * 300 + fusedBlockIdx;
    fusedBlockIdx = blockIdx * 300 + (fusedBlockIdx << 2);
    outputTensor[outputTensorBaseIdx] = inputTensor[fusedBlockIdx];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    outputTensor[outputTensorBaseIdx + 75] = inputTensor[fusedBlockIdx + 1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    outputTensor[outputTensorBaseIdx + 150] = inputTensor[fusedBlockIdx + 2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    outputTensor[outputTensorBaseIdx + 225] = inputTensor[fusedBlockIdx + 3];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

static char_T *getCustomUserDataPathEnvVar(const char_T *unresolvedFilePath)
{
  const char_T *fileName;
  char_T *coderDataPath;
  char_T *resolvedFilePath;
  coderDataPath = getenv("CODER_DATA_PATH");
  if (coderDataPath != NULL) {
    int32_T posOfLastPathSeparator;
    size_t filePathLength;
    size_t sizeOfChar;
    posOfLastPathSeparator = getPositionOfLastFileSeparator(unresolvedFilePath);
    fileName = &unresolvedFilePath[posOfLastPathSeparator];
    filePathLength = (strlen(coderDataPath) + strlen((char_T *)fileName)) + 1;
    sizeOfChar = 1;
    resolvedFilePath = (char_T *)calloc(filePathLength, sizeOfChar);
    stringConcat(resolvedFilePath, coderDataPath, filePathLength);
    stringConcat(resolvedFilePath, fileName, filePathLength);
  } else {
    resolvedFilePath = NULL;
  }
  return resolvedFilePath;
}

static int32_T getPositionOfLastFileSeparator(const char_T *filePath)
{
  int32_T lastPathSeparatorUnix;
  int32_T posOfLastPathSeparator;
  const char_T *ptrToLastPathSeparator;
  lastPathSeparatorUnix = '/';
  ptrToLastPathSeparator = strrchr((char_T *)filePath, lastPathSeparatorUnix);
  if (ptrToLastPathSeparator != NULL) {
    posOfLastPathSeparator = (int32_T)(ptrToLastPathSeparator - filePath);
  } else {
    int32_T lastPathSeparatorWindows;
    lastPathSeparatorWindows = '\\';
    ptrToLastPathSeparator =
        strrchr((char_T *)filePath, lastPathSeparatorWindows);
    if (ptrToLastPathSeparator != NULL) {
      posOfLastPathSeparator = (int32_T)(ptrToLastPathSeparator - filePath);
    } else {
      posOfLastPathSeparator = -1;
    }
  }
  return posOfLastPathSeparator;
}

static char_T *getRelativePathToParentFolder(const char_T *filePath)
{
  int32_T posOfLastPathSeparator;
  const char_T *fileName;
  const char_T *parentDir;
  char_T *resolvedFilePath;
  size_t filePathLength;
  size_t sizeOfChar;
  parentDir = "..";
  posOfLastPathSeparator = getPositionOfLastFileSeparator(filePath);
  fileName = &filePath[posOfLastPathSeparator];
  filePathLength =
      (strlen((char_T *)parentDir) + strlen((char_T *)fileName)) + 1;
  sizeOfChar = 1;
  resolvedFilePath = (char_T *)calloc(filePathLength, sizeOfChar);
  stringConcat(resolvedFilePath, parentDir, filePathLength);
  stringConcat(resolvedFilePath, fileName, filePathLength);
  return resolvedFilePath;
}

static char_T *getResolvedFilePath(const char_T *unresolvedFilePath)
{
  const char_T *fileOpenMode;
  char_T *computedPathUsingEnvVars;
  char_T *pathUsingEnvVarAndSanitizedPath;
  char_T *relativePathToParent;
  char_T *resolvedFilePath;
  char_T *sanitizedFilePath;
  char_T *stringDuplicate;
  FILE *filePtr;
  resolvedFilePath = NULL;
  fileOpenMode = "rb";
  filePtr = fopen((char_T *)unresolvedFilePath, (char_T *)fileOpenMode);
  if (filePtr) {
    size_t filePathLen;
    size_t sizeOfChar;
    filePathLen = strlen((char_T *)unresolvedFilePath) + 1;
    sizeOfChar = 1;
    stringDuplicate = (char_T *)calloc(filePathLen, sizeOfChar);
    stringConcat(stringDuplicate, unresolvedFilePath, filePathLen);
    resolvedFilePath = stringDuplicate;
    fclose(filePtr);
  } else {
    computedPathUsingEnvVars =
        computeFilePathUsingEnvVariable(unresolvedFilePath);
    filePtr = fopen(computedPathUsingEnvVars, (char_T *)fileOpenMode);
    if (filePtr) {
      resolvedFilePath = computedPathUsingEnvVars;
      fclose(filePtr);
    } else {
      free(computedPathUsingEnvVars);
      sanitizedFilePath = sanitizeFilePathForHSP(unresolvedFilePath);
      filePtr = fopen(sanitizedFilePath, (char_T *)fileOpenMode);
      if (filePtr) {
        resolvedFilePath = sanitizedFilePath;
        fclose(filePtr);
      } else {
        relativePathToParent =
            getRelativePathToParentFolder(unresolvedFilePath);
        filePtr = fopen(relativePathToParent, (char_T *)fileOpenMode);
        if (filePtr) {
          resolvedFilePath = relativePathToParent;
          fclose(filePtr);
        } else {
          free(relativePathToParent);
          pathUsingEnvVarAndSanitizedPath =
              computeFilePathUsingEnvVariable(sanitizedFilePath);
          filePtr =
              fopen(pathUsingEnvVarAndSanitizedPath, (char_T *)fileOpenMode);
          if (filePtr) {
            resolvedFilePath = pathUsingEnvVarAndSanitizedPath;
            fclose(filePtr);
          } else {
            free(pathUsingEnvVarAndSanitizedPath);
            throwFileNotFoundErrorMessage(unresolvedFilePath,
                                          sanitizedFilePath);
          }
        }
      }
    }
  }
  return resolvedFilePath;
}

static void maxPooling(const emlrtStack *sp, const real32_T *inputTensor,
                       real32_T *outputTensor)
{
  int32_T c_fusedOutputWidthAndChannelBlo;
  for (c_fusedOutputWidthAndChannelBlo = 0;
       c_fusedOutputWidthAndChannelBlo < 600;
       c_fusedOutputWidthAndChannelBlo++) {
    int32_T outputChannelBlockIdx;
    int32_T outputWidthIdx;
    outputChannelBlockIdx = c_fusedOutputWidthAndChannelBlo / 75;
    outputWidthIdx = c_fusedOutputWidthAndChannelBlo % 75;
    maxPoolingKernel(
        sp, &inputTensor[outputChannelBlockIdx * 600],
        &outputTensor[(outputWidthIdx << 2) + outputChannelBlockIdx * 300],
        outputWidthIdx << 3);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
}

static void maxPoolingKernel(const emlrtStack *sp,
                             const real32_T *inputBufferPtr,
                             real32_T *outputBufferPtr,
                             int32_T c_startIdxWithPaddingOffsetInpu)
{
  __m128 ipReg_opHeightIdx_0;
  __m128 opReg_opHeightIdx_0;
  ipReg_opHeightIdx_0 =
      _mm_loadu_ps(&inputBufferPtr[c_startIdxWithPaddingOffsetInpu]);
  opReg_opHeightIdx_0 = ipReg_opHeightIdx_0;
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
  ipReg_opHeightIdx_0 =
      _mm_loadu_ps(&inputBufferPtr[c_startIdxWithPaddingOffsetInpu + 4]);
  opReg_opHeightIdx_0 = _mm_max_ps(ipReg_opHeightIdx_0, opReg_opHeightIdx_0);
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
  _mm_storeu_ps(&outputBufferPtr[0], opReg_opHeightIdx_0);
  if (*emlrtBreakCheckR2012bFlagVar != 0) {
    emlrtBreakCheckR2012b((emlrtConstCTX)sp);
  }
}

static void readDnnConstants(real32_T *inputBufferPtr,
                             const char_T *unresolvedFilePath,
                             int32_T numElementsToRead)
{
  int32_T elementSizeInBytes;
  const char_T *fileOpenMode;
  char_T *resolvedFilePath;
  FILE *filePtr;
  void *dataBufferPtr;
  resolvedFilePath = getResolvedFilePath(unresolvedFilePath);
  fileOpenMode = "rb";
  filePtr = fopen(resolvedFilePath, (char_T *)fileOpenMode);
  dataBufferPtr = &inputBufferPtr[0];
  elementSizeInBytes = 4;
  fread(dataBufferPtr, elementSizeInBytes, numElementsToRead, filePtr);
  fclose(filePtr);
  free(resolvedFilePath);
}

static char_T *resolveBinaryFilePath(const char_T *unresolvedFilePath)
{
  const char_T *c_filePathAfterSlicingRelativeP;
  const char_T *c_leadingPathSeparatorUnixAndWi;
  const char_T *codegenDirStrInMWDLDataPath;
  const char_T *d_filePathAfterSlicingRelativeP;
  const char_T *mwDLDataPath;
  char_T *codegenDir;
  char_T *coderDataPath;
  char_T *resolvedFilePath;
  char_T *updatedStartDir;
  size_t sizeOfChar;
#define XSTR(x) #x
#define STR(x) XSTR(x)
  coderDataPath = getenv("CODER_DATA_PATH");
  sizeOfChar = 1;
  if (coderDataPath != NULL) {
    resolvedFilePath = getCustomUserDataPathEnvVar(unresolvedFilePath);
  } else {
    size_t filePathLen;
    size_t posOfCodegenDir;
    size_t posOfLeadingPathSeparator;
    mwDLDataPath = STR(MW_DL_DATA_PATH);
    c_filePathAfterSlicingRelativeP = &unresolvedFilePath[2];
    c_leadingPathSeparatorUnixAndWi = "/\\";
    posOfLeadingPathSeparator =
        strcspn((char_T *)c_filePathAfterSlicingRelativeP,
                (char_T *)c_leadingPathSeparatorUnixAndWi);
    filePathLen = posOfLeadingPathSeparator + 1;
    codegenDir = (char_T *)calloc(filePathLen, sizeOfChar);
    strncpy(codegenDir, (char_T *)c_filePathAfterSlicingRelativeP,
            posOfLeadingPathSeparator);
    codegenDirStrInMWDLDataPath = strstr((char_T *)mwDLDataPath, codegenDir);
    if (codegenDirStrInMWDLDataPath == NULL) {
      posOfCodegenDir = strlen((char_T *)mwDLDataPath);
    } else {
      posOfCodegenDir = codegenDirStrInMWDLDataPath - mwDLDataPath;
    }
    if (posOfCodegenDir == strlen((char_T *)mwDLDataPath)) {
      size_t b_filePathLen;
      d_filePathAfterSlicingRelativeP = &unresolvedFilePath[1];
      b_filePathLen = (strlen((char_T *)mwDLDataPath) +
                       strlen((char_T *)d_filePathAfterSlicingRelativeP)) +
                      1;
      resolvedFilePath = (char_T *)calloc(b_filePathLen, sizeOfChar);
      stringConcat(resolvedFilePath, mwDLDataPath, b_filePathLen);
      stringConcat(resolvedFilePath, d_filePathAfterSlicingRelativeP,
                   b_filePathLen);
    } else {
      size_t c_filePathLen;
      c_filePathLen = posOfCodegenDir + 1;
      updatedStartDir = (char_T *)calloc(c_filePathLen, sizeOfChar);
      strncpy(updatedStartDir, (char_T *)mwDLDataPath, posOfCodegenDir);
      c_filePathLen = (strlen(updatedStartDir) +
                       strlen((char_T *)c_filePathAfterSlicingRelativeP)) +
                      1;
      resolvedFilePath = (char_T *)calloc(c_filePathLen, sizeOfChar);
      stringConcat(resolvedFilePath, updatedStartDir, c_filePathLen);
      stringConcat(resolvedFilePath, c_filePathAfterSlicingRelativeP,
                   c_filePathLen);
      free(updatedStartDir);
    }
    free(codegenDir);
  }
#undef XSTR
#undef STR
  return resolvedFilePath;
}

static char_T *sanitizeFilePathForHSP(const char_T *unSanitizedFilePath)
{
  char_T *sanitizedFilePath;
  char_T *stringDuplicate;
  size_t charIdx;
  size_t filePathLen;
  size_t sizeOfChar;
  filePathLen = strlen((char_T *)unSanitizedFilePath) + 1;
  sizeOfChar = 1;
  stringDuplicate = (char_T *)calloc(filePathLen, sizeOfChar);
  stringConcat(stringDuplicate, unSanitizedFilePath, filePathLen);
  sanitizedFilePath = stringDuplicate;
  for (charIdx = 0; charIdx < strlen((char_T *)unSanitizedFilePath);
       charIdx++) {
    char_T charToCheckFor;
    charToCheckFor = unSanitizedFilePath[charIdx];
    if (isspace(charToCheckFor)) {
      sanitizedFilePath[charIdx] = '_';
    }
  }
  return sanitizedFilePath;
}

static void stringConcat(char_T *destinationString, const char_T *sourceString,
                         size_t destBufferSize)
{
  size_t dstStringLen;
  size_t srcBuffIdx;
  dstStringLen = strlen(destinationString);
  srcBuffIdx = 0;
  while ((sourceString[srcBuffIdx] != '\x00') &&
         (dstStringLen < destBufferSize - 1)) {
    destinationString[dstStringLen] = sourceString[srcBuffIdx];
    dstStringLen++;
    srcBuffIdx++;
  }
  destinationString[dstStringLen] = '\x00';
}

static void throwFileNotFoundErrorMessage(const char_T *unresolvedFilePath,
                                          const char_T *sanitizedFilePath)
{
  char_T errorMessage[4096];
  const char_T *stringToConcat1;
  const char_T *stringToConcat2;
  const char_T *stringToConcat3;
  const char_T *stringToConcat4;
  char_T *b_codegenFolderName;
  char_T *codegenFolderName;
  memset(&errorMessage[0], '\x00', 4096U);
  codegenFolderName = extractCodegenFolderName(unresolvedFilePath);
  stringToConcat1 = "Unable to find the ";
  stringConcat(errorMessage, stringToConcat1, 4096U);
  stringConcat(errorMessage, unresolvedFilePath, 4096U);
  stringToConcat2 = " binary file in ";
  stringConcat(errorMessage, stringToConcat2, 4096U);
  stringConcat(errorMessage, codegenFolderName, 4096U);
  if (strcmp((char_T *)unresolvedFilePath, (char_T *)sanitizedFilePath) != 0) {
    b_codegenFolderName = extractCodegenFolderName(sanitizedFilePath);
    stringToConcat3 = " or in ";
    stringConcat(errorMessage, stringToConcat3, 4096U);
    stringConcat(errorMessage, unresolvedFilePath, 4096U);
    free(b_codegenFolderName);
  }
  stringToConcat4 = ".";
  stringConcat(errorMessage, stringToConcat4, 4096U);
  free(codegenFolderName);
  mexErrMsgTxt(errorMessage);
}

void dlnetwork_callPredict(const emlrtStack *sp,
                           c_coder_internal_ctarget_dlnetw *obj,
                           const real32_T inputsT_0_f1[450],
                           real32_T outputs_0_f1[6])
{
  static const real32_T fv1[192] = {
      4.93832E-41F,     -4.92725E-41F,   4.92542E-41F,     -4.93425E-41F,
      -6.50202072E-33F, 4.91954E-41F,    4.91898E-41F,     -4.93061E-41F,
      -4.94154E-41F,    -4.93369E-41F,   -7.60134E-41F,    -4.94504E-41F,
      -0.0158684291F,   0.800691962F,    -0.61060065F,     0.408436269F,
      -0.199332759F,    -0.490154982F,   -0.245185375F,    0.109067976F,
      -1.34626615F,     0.131529808F,    0.28258276F,      0.110389888F,
      0.341359645F,     -0.51682204F,    0.39372167F,      0.295733035F,
      -0.512928128F,    -0.144118637F,   -2.05160744E-17F, 4.93187E-41F,
      5.74953E-42F,     -4.93762E-41F,   -4.67588127E-16F, 1.38759393E-19F,
      0.0745137557F,    0.0790664256F,   -0.627265215F,    -0.0728939697F,
      -0.337040126F,    -0.0630488321F,  0.116241872F,     0.201250106F,
      0.0587561689F,    -0.391887635F,   -0.364343435F,    -0.856722951F,
      0.131677091F,     0.0418755487F,   -0.580290794F,    -0.0859964266F,
      0.357163459F,     0.299151301F,    -4.90482E-41F,    -1.40679913E-5F,
      -4.93005E-41F,    -5.66023482E-6F, 8.59255776E-24F,  2.67593538E-8F,
      0.229282305F,     -0.461117089F,   0.197123408F,     -0.20853205F,
      0.0976400599F,    0.395300686F,    -0.446397513F,    0.545710862F,
      0.804525256F,     -1.24387205F,    -0.0136664715F,   -1.06960046F,
      -0.407749206F,    -0.0795929283F,  -0.860379636F,    0.241160303F,
      -0.25688687F,     0.203039661F,    -0.208857626F,    0.271284729F,
      -0.00242831791F,  -0.205145746F,   -0.727614F,       0.15631102F,
      0.0196617525F,    -0.521931589F,   -0.12908721F,     0.561679482F,
      0.241076007F,     -0.271613955F,   -0.03553598F,     -0.660132647F,
      -0.0726299807F,   -0.02987957F,    0.603543758F,     0.0291176718F,
      0.306957781F,     -0.69501096F,    0.47002238F,      -0.0444687046F,
      -0.119313851F,    0.642920852F,    -0.141906232F,    -0.288258165F,
      0.691795588F,     0.45476675F,     -0.25173533F,     -0.122555621F,
      -0.861177444F,    -0.177538708F,   0.135680646F,     -0.183392823F,
      -0.632463694F,    -0.00759967277F, 0.439419866F,     0.102071047F,
      0.394877166F,     0.41633147F,     -0.450404525F,    -0.882336915F,
      0.386651695F,     0.269021779F,    -0.00353720784F,  -0.485938132F,
      -0.141237885F,    -0.290487617F,   0.268149614F,     -0.00643413095F,
      -0.0210626163F,   0.495768189F,    0.207829937F,     -0.652159333F,
      -0.24146609F,     0.205764502F,    0.538541496F,     0.186851114F,
      0.0833082423F,    0.20360814F,     -0.353757083F,    -0.160068914F,
      -0.00943160057F,  -0.26626116F,    0.31146726F,      -0.069242008F,
      -0.127826452F,    0.56985116F,     -0.00413195603F,  -0.436410666F,
      0.285115093F,     -0.443057686F,   -0.365191132F,    0.482943058F,
      -0.00479991781F,  -0.408070654F,   0.0481100976F,    -0.463723421F,
      0.256750047F,     -0.461175472F,   0.223804608F,     -0.0245106183F,
      0.116659917F,     0.196993351F,    -0.117362767F,    -0.929613173F,
      -0.00199708017F,  0.00921723F,     0.438918382F,     -0.387580454F,
      0.595069468F,     -1.35718274F,    0.397969F,        -0.00697630504F,
      -0.0106136482F,   0.261895359F,    0.24879247F,      0.250296056F,
      -1.04651546F,     0.254258305F,    0.341516137F,     -0.00762110483F,
      0.0409385189F,    0.0427581966F,   -0.00333069614F,  -0.600594342F,
      -0.39095971F,     -0.390020847F,   0.0925052911F,    0.186796322F,
      0.0970058888F,    0.434680879F,    -0.494118601F,    -0.495410025F};
  static const real32_T t0_Bias[32] = {
      -0.0055989339F, -0.00964858569F, 0.00196798937F,  -0.20724465F,
      0.170035407F,   -0.00882798713F, 0.0145362737F,   -0.203619212F,
      -0.0564430095F, -0.0194707476F,  -0.017311573F,   0.206104591F,
      0.0666818F,     0.220999092F,    -0.00132372917F, -0.0585077852F,
      -0.0199731383F, 0.15618518F,     0.371311098F,    0.226526231F,
      -0.201489568F,  -0.0973544F,     0.230482787F,    -0.149059653F,
      -0.165560871F,  -0.125799149F,   -0.171630457F,   -0.106793314F,
      -0.0708716363F, -0.11809884F,    -0.208402172F,   0.0757342353F};
  static const real32_T t1_Bias[6] = {-0.208084226F, 0.0344054F,
                                      0.179120213F,  -0.00685805827F,
                                      -0.470739305F, 0.097508125F};
  static const real32_T fv[3] = {0.14628531F, 0.818803608F, -0.175789207F};
  static real32_T t0_Weights[76800];
  static boolean_T bufferInitialized;
  __m128 r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T inputsT_0_f1_tmp;
  real32_T outT_f2_0_f1[4800];
  real32_T outT_f3_0_f1[2400];
  real32_T outT_f4_0_f1[2400];
  real32_T b_inputsT_0_f1[450];
  real32_T outT_f6_0_f1[32];
  real32_T outT_f7_0_f1[32];
  real32_T layerOutput[6];
  real32_T alpha1;
  real32_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  if (!bufferInitialized) {
    readDnnConstants(&t0_Weights[0],
                     "C:\\Users\\metal\\Desktop\\MATLAB\\codegen\\mex\\Net_"
                     "predict/largeDnnConstants_1266080.bin",
                     76800);
  }
  bufferInitialized = true;
  st.site = &j_emlrtRSI;
  if (!obj->IsNetworkInitialized) {
    b_st.site = &eb_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    obj->IsNetworkInitialized = true;
  }
  b_st.site = &eb_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &p_emlrtRSI;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 <= 144; i1 += 4) {
      inputsT_0_f1_tmp = i1 + 150 * i;
      _mm_storeu_ps(&b_inputsT_0_f1[inputsT_0_f1_tmp],
                    _mm_sub_ps(_mm_loadu_ps(&inputsT_0_f1[inputsT_0_f1_tmp]),
                               _mm_set1_ps(fv[i])));
    }
    inputsT_0_f1_tmp = 150 * i + 148;
    alpha1 = fv[i];
    b_inputsT_0_f1[inputsT_0_f1_tmp] = inputsT_0_f1[inputsT_0_f1_tmp] - alpha1;
    inputsT_0_f1_tmp = 150 * i + 149;
    b_inputsT_0_f1[inputsT_0_f1_tmp] = inputsT_0_f1[inputsT_0_f1_tmp] - alpha1;
  }
  g_st.site = &q_emlrtRSI;
  conv2dDirectOptimizedColMajor(&g_st, b_inputsT_0_f1, outT_f2_0_f1);
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &t_emlrtRSI;
  g_st.site = &u_emlrtRSI;
  h_st.site = &u_emlrtRSI;
  maxPooling(&h_st, &outT_f2_0_f1[0], &outT_f3_0_f1[0]);
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  g_st.site = &w_emlrtRSI;
  h_st.site = &w_emlrtRSI;
  fromBlockedLayoutTransform(&h_st, &outT_f3_0_f1[0], &outT_f4_0_f1[0]);
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &x_emlrtRSI;
  g_st.site = &y_emlrtRSI;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0F;
  beta1 = 0.0F;
  m_t = (ptrdiff_t)32;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)2400;
  lda_t = (ptrdiff_t)32;
  ldb_t = (ptrdiff_t)2400;
  ldc_t = (ptrdiff_t)32;
  sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &t0_Weights[0], &lda_t,
        &outT_f4_0_f1[0], &ldb_t, &beta1, &outT_f6_0_f1[0], &ldc_t);
  for (inputsT_0_f1_tmp = 0; inputsT_0_f1_tmp <= 28; inputsT_0_f1_tmp += 4) {
    r = _mm_loadu_ps(&outT_f6_0_f1[inputsT_0_f1_tmp]);
    _mm_storeu_ps(&outT_f6_0_f1[inputsT_0_f1_tmp],
                  _mm_add_ps(r, _mm_loadu_ps(&t0_Bias[inputsT_0_f1_tmp])));
  }
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &xb_emlrtRSI;
  unaryElementwise(&d_st, outT_f6_0_f1, outT_f7_0_f1);
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &x_emlrtRSI;
  g_st.site = &y_emlrtRSI;
  for (i = 0; i < 6; i++) {
    alpha1 = 0.0F;
    for (i1 = 0; i1 < 32; i1++) {
      alpha1 += fv1[i + 6 * i1] * outT_f7_0_f1[i1];
    }
    layerOutput[i] = alpha1;
  }
  r = _mm_loadu_ps(&layerOutput[0]);
  _mm_storeu_ps(&layerOutput[0], _mm_add_ps(r, _mm_loadu_ps(&t1_Bias[0])));
  layerOutput[4] -= 0.470739305F;
  layerOutput[5] += 0.097508125F;
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &k_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  e_st.site = &o_emlrtRSI;
  f_st.site = &fb_emlrtRSI;
  g_st.site = &fb_emlrtRSI;
  SoftmaxLayer_predict(layerOutput, outputs_0_f1);
}

/* End of code generation (callPredict.c) */

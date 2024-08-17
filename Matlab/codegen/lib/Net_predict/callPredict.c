/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: callPredict.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 02-May-2024 17:38:02
 */

/* Include Files */
#include "callPredict.h"
#include "Net_predict_internal_types.h"
#include "SoftmaxLayer.h"
#include "conv2dDirectOptimizedColMajor.h"
#include "rt_nonfinite.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
static char *computeFilePathUsingEnvVariable(const char *unresolvedFilePath);

static int div_nde_s32_floor(int numerator);

static int div_s32_floor(int numerator, int denominator);

static char *getCustomUserDataPathEnvVar(const char *unresolvedFilePath);

static int getPositionOfLastFileSeparator(const char *filePath);

static char *getRelativePathToParentFolder(const char *filePath);

static char *getResolvedFilePath(const char *unresolvedFilePath);

static void macroKernel1(int M, int K, int N, const float *A, int LDA,
                         const float *B, int LDB, float *C, int LDC);

static void matrixMultiply1(int M, int K, int N, int blockSizeM, int blockSizeK,
                            int blockSizeN, const float *A, const float *B,
                            float *C);

static void microKernel11(int K, const float *A, int LDA, const float *B,
                          float *C);

static void microKernel12(int K, const float *A, int LDA, const float *B,
                          float *C);

static void readDnnConstants(float *inputBufferPtr,
                             const char *unresolvedFilePath,
                             int numElementsToRead);

static char *resolveBinaryFilePath(const char *unresolvedFilePath);

static char *sanitizeFilePathForHSP(const char *unSanitizedFilePath);

static void stringConcat(char *destinationString, const char *sourceString,
                         size_t destBufferSize);

/* Function Definitions */
/*
 * Arguments    : const char *unresolvedFilePath
 * Return Type  : char *
 */
static char *computeFilePathUsingEnvVariable(const char *unresolvedFilePath)
{
  char *resolvedFilePath;
  char *stringDuplicate;
  size_t filePathLen;
  size_t sizeOfChar;
  filePathLen = strlen((char *)unresolvedFilePath) + 1;
  sizeOfChar = 1;
  stringDuplicate = (char *)calloc(filePathLen, sizeOfChar);
  stringConcat(stringDuplicate, unresolvedFilePath, filePathLen);
#if defined(MW_RUNTIME_DL_DATA_PATH) != 0
  extern char *mwGetRuntimeDLDataPath(const char *);
  resolvedFilePath = mwGetRuntimeDLDataPath((char *)unresolvedFilePath);
#elif defined(MW_DL_DATA_PATH) != 0
  resolvedFilePath = resolveBinaryFilePath(unresolvedFilePath);
#else
  char *coderDataPath;
  coderDataPath = getenv("CODER_DATA_PATH");
  if (coderDataPath != NULL) {
    resolvedFilePath = resolveBinaryFilePath(unresolvedFilePath);
  } else {
    resolvedFilePath = stringDuplicate;
  }
#endif
  return resolvedFilePath;
}

/*
 * Arguments    : int numerator
 * Return Type  : int
 */
static int div_nde_s32_floor(int numerator)
{
  int i;
  if ((numerator < 0) && (numerator % 7 != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / 7 + i;
}

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    bool quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~(unsigned int)numerator + 1U;
    } else {
      absNumerator = (unsigned int)numerator;
    }
    if (denominator < 0) {
      absDenominator = ~(unsigned int)denominator + 1U;
    } else {
      absDenominator = (unsigned int)denominator;
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

/*
 * Arguments    : const char *unresolvedFilePath
 * Return Type  : char *
 */
static char *getCustomUserDataPathEnvVar(const char *unresolvedFilePath)
{
  const char *fileName;
  char *coderDataPath;
  char *resolvedFilePath;
  coderDataPath = getenv("CODER_DATA_PATH");
  if (coderDataPath != NULL) {
    int posOfLastPathSeparator;
    size_t filePathLength;
    size_t sizeOfChar;
    posOfLastPathSeparator = getPositionOfLastFileSeparator(unresolvedFilePath);
    fileName = &unresolvedFilePath[posOfLastPathSeparator];
    filePathLength = (strlen(coderDataPath) + strlen((char *)fileName)) + 1;
    sizeOfChar = 1;
    resolvedFilePath = (char *)calloc(filePathLength, sizeOfChar);
    stringConcat(resolvedFilePath, coderDataPath, filePathLength);
    stringConcat(resolvedFilePath, fileName, filePathLength);
  } else {
    resolvedFilePath = NULL;
  }
  return resolvedFilePath;
}

/*
 * Arguments    : const char *filePath
 * Return Type  : int
 */
static int getPositionOfLastFileSeparator(const char *filePath)
{
  int lastPathSeparatorUnix;
  int posOfLastPathSeparator;
  const char *ptrToLastPathSeparator;
  lastPathSeparatorUnix = '/';
  ptrToLastPathSeparator = strrchr((char *)filePath, lastPathSeparatorUnix);
  if (ptrToLastPathSeparator != NULL) {
    posOfLastPathSeparator = (int)(ptrToLastPathSeparator - filePath);
  } else {
    int lastPathSeparatorWindows;
    lastPathSeparatorWindows = '\\';
    ptrToLastPathSeparator =
        strrchr((char *)filePath, lastPathSeparatorWindows);
    if (ptrToLastPathSeparator != NULL) {
      posOfLastPathSeparator = (int)(ptrToLastPathSeparator - filePath);
    } else {
      posOfLastPathSeparator = -1;
    }
  }
  return posOfLastPathSeparator;
}

/*
 * Arguments    : const char *filePath
 * Return Type  : char *
 */
static char *getRelativePathToParentFolder(const char *filePath)
{
  int posOfLastPathSeparator;
  const char *fileName;
  const char *parentDir;
  char *resolvedFilePath;
  size_t filePathLength;
  size_t sizeOfChar;
  parentDir = "..";
  posOfLastPathSeparator = getPositionOfLastFileSeparator(filePath);
  fileName = &filePath[posOfLastPathSeparator];
  filePathLength = (strlen((char *)parentDir) + strlen((char *)fileName)) + 1;
  sizeOfChar = 1;
  resolvedFilePath = (char *)calloc(filePathLength, sizeOfChar);
  stringConcat(resolvedFilePath, parentDir, filePathLength);
  stringConcat(resolvedFilePath, fileName, filePathLength);
  return resolvedFilePath;
}

/*
 * Arguments    : const char *unresolvedFilePath
 * Return Type  : char *
 */
static char *getResolvedFilePath(const char *unresolvedFilePath)
{
  const char *fileOpenMode;
  char *computedPathUsingEnvVars;
  char *pathUsingEnvVarAndSanitizedPath;
  char *relativePathToParent;
  char *resolvedFilePath;
  char *sanitizedFilePath;
  char *stringDuplicate;
  FILE *filePtr;
  resolvedFilePath = NULL;
  fileOpenMode = "rb";
  filePtr = fopen((char *)unresolvedFilePath, (char *)fileOpenMode);
  if (filePtr) {
    size_t filePathLen;
    size_t sizeOfChar;
    filePathLen = strlen((char *)unresolvedFilePath) + 1;
    sizeOfChar = 1;
    stringDuplicate = (char *)calloc(filePathLen, sizeOfChar);
    stringConcat(stringDuplicate, unresolvedFilePath, filePathLen);
    resolvedFilePath = stringDuplicate;
    fclose(filePtr);
  } else {
    computedPathUsingEnvVars =
        computeFilePathUsingEnvVariable(unresolvedFilePath);
    filePtr = fopen(computedPathUsingEnvVars, (char *)fileOpenMode);
    if (filePtr) {
      resolvedFilePath = computedPathUsingEnvVars;
      fclose(filePtr);
    } else {
      free(computedPathUsingEnvVars);
      sanitizedFilePath = sanitizeFilePathForHSP(unresolvedFilePath);
      filePtr = fopen(sanitizedFilePath, (char *)fileOpenMode);
      if (filePtr) {
        resolvedFilePath = sanitizedFilePath;
        fclose(filePtr);
      } else {
        relativePathToParent =
            getRelativePathToParentFolder(unresolvedFilePath);
        filePtr = fopen(relativePathToParent, (char *)fileOpenMode);
        if (filePtr) {
          resolvedFilePath = relativePathToParent;
          fclose(filePtr);
        } else {
          free(relativePathToParent);
          pathUsingEnvVarAndSanitizedPath =
              computeFilePathUsingEnvVariable(sanitizedFilePath);
          filePtr =
              fopen(pathUsingEnvVarAndSanitizedPath, (char *)fileOpenMode);
          if (filePtr) {
            resolvedFilePath = pathUsingEnvVarAndSanitizedPath;
            fclose(filePtr);
          } else {
            free(pathUsingEnvVarAndSanitizedPath);
            exit(EXIT_FAILURE);
          }
        }
      }
    }
  }
  return resolvedFilePath;
}

/*
 * Arguments    : int M
 *                int K
 *                int N
 *                const float *A
 *                int LDA
 *                const float *B
 *                int LDB
 *                float *C
 *                int LDC
 * Return Type  : void
 */
static void macroKernel1(int M, int K, int N, const float *A, int LDA,
                         const float *B, int LDB, float *C, int LDC)
{
  int idxB;
  int j;
  j = 0;
  idxB = 0;
  while (j <= N - 1) {
    int i;
    int idxA;
    int idxC;
    idxC = LDC * j;
    i = 0;
    idxA = 0;
    while (i <= M - 7) {
      microKernel11(K, &A[idxA], LDA, &B[idxB], &C[idxC]);
      idxA += 7;
      idxC += 7;
      i += 7;
    }
    while (i <= M - 1) {
      microKernel12(K, &A[idxA], LDA, &B[idxB], &C[idxC]);
      idxA++;
      idxC++;
      i++;
    }
    idxB += LDB;
    j++;
  }
}

/*
 * Arguments    : int M
 *                int K
 *                int N
 *                int blockSizeM
 *                int blockSizeK
 *                int blockSizeN
 *                const float *A
 *                const float *B
 *                float *C
 * Return Type  : void
 */
static void matrixMultiply1(int M, int K, int N, int blockSizeM, int blockSizeK,
                            int blockSizeN, const float *A, const float *B,
                            float *C)
{
  int b_j1;
  int i0;
  int i0_ub;
  int k0;
  int k0_ub;
  memset(C, 0, (unsigned int)((M * N) << 2));
  if (blockSizeM >= M) {
    blockSizeM = M;
  } else {
    blockSizeM = div_nde_s32_floor(blockSizeM) * 7;
    if (blockSizeM <= 0) {
      blockSizeM = 1;
    }
  }
  if (blockSizeN >= N) {
    blockSizeN = N;
  } else if (blockSizeN <= 0) {
    blockSizeN = 1;
  }
  i0_ub = div_s32_floor(M - 1, blockSizeM) + 1;
  k0_ub = div_s32_floor(K - 1, blockSizeK) + 1;
  for (b_j1 = 0; b_j1 < N; b_j1 += blockSizeN) {
    int N2;
    if (b_j1 > N - blockSizeN) {
      N2 = N - b_j1;
    } else {
      N2 = blockSizeN;
    }
    for (k0 = 1; k0 <= k0_ub; k0++) {
      int K2;
      int k;
      k = (k0 - 1) * blockSizeK;
      if (k > K - blockSizeK) {
        K2 = K - k;
      } else {
        K2 = blockSizeK;
      }
      for (i0 = 1; i0 <= i0_ub; i0++) {
        int b_i;
        int i;
        i = (i0 - 1) * blockSizeM;
        if (i > M - blockSizeM) {
          b_i = M - i;
        } else {
          b_i = blockSizeM;
        }
        macroKernel1(b_i, K2, N2, &A[i + M * k], M, &B[k + K * b_j1], K,
                     &C[i + M * b_j1], M);
      }
    }
  }
}

/*
 * Arguments    : int K
 *                const float *A
 *                int LDA
 *                const float *B
 *                float *C
 * Return Type  : void
 */
static void microKernel11(int K, const float *A, int LDA, const float *B,
                          float *C)
{
  float b_c;
  float c;
  float c_c;
  float d_c;
  float e_c;
  float f_c;
  float g_c;
  int idxA;
  int idxB;
  int k;
  idxA = 0;
  idxB = 0;
  c = C[0];
  b_c = C[1];
  c_c = C[2];
  d_c = C[3];
  e_c = C[4];
  f_c = C[5];
  g_c = C[6];
  for (k = 0; k < K; k++) {
    float aFloat;
    float b;
    float b_aFloat;
    float c_aFloat;
    float d_aFloat;
    float e_aFloat;
    float f_aFloat;
    float g_aFloat;
    aFloat = A[idxA];
    b_aFloat = A[idxA + 1];
    c_aFloat = A[idxA + 2];
    d_aFloat = A[idxA + 3];
    e_aFloat = A[idxA + 4];
    f_aFloat = A[idxA + 5];
    g_aFloat = A[idxA + 6];
    b = B[idxB];
    c += aFloat * b;
    b_c += b_aFloat * b;
    c_c += c_aFloat * b;
    d_c += d_aFloat * b;
    e_c += e_aFloat * b;
    f_c += f_aFloat * b;
    g_c += g_aFloat * b;
    idxA += LDA;
    idxB++;
  }
  C[0] = c;
  C[1] = b_c;
  C[2] = c_c;
  C[3] = d_c;
  C[4] = e_c;
  C[5] = f_c;
  C[6] = g_c;
}

/*
 * Arguments    : int K
 *                const float *A
 *                int LDA
 *                const float *B
 *                float *C
 * Return Type  : void
 */
static void microKernel12(int K, const float *A, int LDA, const float *B,
                          float *C)
{
  float c;
  int idxA;
  int idxB;
  int k;
  idxA = 0;
  idxB = 0;
  c = C[0];
  for (k = 0; k < K; k++) {
    float aFloat;
    float b;
    aFloat = A[idxA];
    b = B[idxB];
    c += aFloat * b;
    idxA += LDA;
    idxB++;
  }
  C[0] = c;
}

/*
 * Arguments    : float *inputBufferPtr
 *                const char *unresolvedFilePath
 *                int numElementsToRead
 * Return Type  : void
 */
static void readDnnConstants(float *inputBufferPtr,
                             const char *unresolvedFilePath,
                             int numElementsToRead)
{
  int elementSizeInBytes;
  const char *fileOpenMode;
  char *resolvedFilePath;
  FILE *filePtr;
  void *dataBufferPtr;
  resolvedFilePath = getResolvedFilePath(unresolvedFilePath);
  fileOpenMode = "rb";
  filePtr = fopen(resolvedFilePath, (char *)fileOpenMode);
  dataBufferPtr = &inputBufferPtr[0];
  elementSizeInBytes = 4;
  fread(dataBufferPtr, elementSizeInBytes, numElementsToRead, filePtr);
  fclose(filePtr);
  free(resolvedFilePath);
}

/*
 * Arguments    : const char *unresolvedFilePath
 * Return Type  : char *
 */
static char *resolveBinaryFilePath(const char *unresolvedFilePath)
{
  const char *c_filePathAfterSlicingRelativeP;
  const char *c_leadingPathSeparatorUnixAndWi;
  const char *codegenDirStrInMWDLDataPath;
  const char *d_filePathAfterSlicingRelativeP;
  const char *mwDLDataPath;
  char *codegenDir;
  char *coderDataPath;
  char *resolvedFilePath;
  char *updatedStartDir;
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
        strcspn((char *)c_filePathAfterSlicingRelativeP,
                (char *)c_leadingPathSeparatorUnixAndWi);
    filePathLen = posOfLeadingPathSeparator + 1;
    codegenDir = (char *)calloc(filePathLen, sizeOfChar);
    strncpy(codegenDir, (char *)c_filePathAfterSlicingRelativeP,
            posOfLeadingPathSeparator);
    codegenDirStrInMWDLDataPath = strstr((char *)mwDLDataPath, codegenDir);
    if (codegenDirStrInMWDLDataPath == NULL) {
      posOfCodegenDir = strlen((char *)mwDLDataPath);
    } else {
      posOfCodegenDir = codegenDirStrInMWDLDataPath - mwDLDataPath;
    }
    if (posOfCodegenDir == strlen((char *)mwDLDataPath)) {
      size_t b_filePathLen;
      d_filePathAfterSlicingRelativeP = &unresolvedFilePath[1];
      b_filePathLen = (strlen((char *)mwDLDataPath) +
                       strlen((char *)d_filePathAfterSlicingRelativeP)) +
                      1;
      resolvedFilePath = (char *)calloc(b_filePathLen, sizeOfChar);
      stringConcat(resolvedFilePath, mwDLDataPath, b_filePathLen);
      stringConcat(resolvedFilePath, d_filePathAfterSlicingRelativeP,
                   b_filePathLen);
    } else {
      size_t c_filePathLen;
      c_filePathLen = posOfCodegenDir + 1;
      updatedStartDir = (char *)calloc(c_filePathLen, sizeOfChar);
      strncpy(updatedStartDir, (char *)mwDLDataPath, posOfCodegenDir);
      c_filePathLen = (strlen(updatedStartDir) +
                       strlen((char *)c_filePathAfterSlicingRelativeP)) +
                      1;
      resolvedFilePath = (char *)calloc(c_filePathLen, sizeOfChar);
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

/*
 * Arguments    : const char *unSanitizedFilePath
 * Return Type  : char *
 */
static char *sanitizeFilePathForHSP(const char *unSanitizedFilePath)
{
  char *sanitizedFilePath;
  char *stringDuplicate;
  size_t charIdx;
  size_t filePathLen;
  size_t sizeOfChar;
  filePathLen = strlen((char *)unSanitizedFilePath) + 1;
  sizeOfChar = 1;
  stringDuplicate = (char *)calloc(filePathLen, sizeOfChar);
  stringConcat(stringDuplicate, unSanitizedFilePath, filePathLen);
  sanitizedFilePath = stringDuplicate;
  for (charIdx = 0; charIdx < strlen((char *)unSanitizedFilePath); charIdx++) {
    char charToCheckFor;
    charToCheckFor = unSanitizedFilePath[charIdx];
    if (isspace(charToCheckFor)) {
      sanitizedFilePath[charIdx] = '_';
    }
  }
  return sanitizedFilePath;
}

/*
 * Arguments    : char *destinationString
 *                const char *sourceString
 *                size_t destBufferSize
 * Return Type  : void
 */
static void stringConcat(char *destinationString, const char *sourceString,
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

/*
 * Arguments    : c_coder_internal_ctarget_dlnetw *obj
 *                const float inputsT_0_f1[450]
 *                float outputs_0_f1[6]
 * Return Type  : void
 */
void dlnetwork_callPredict(c_coder_internal_ctarget_dlnetw *obj,
                           const float inputsT_0_f1[450], float outputs_0_f1[6])
{
  static const float A[192] = {
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
  static const float fv1[32] = {
      -0.0055989339F, -0.00964858569F, 0.00196798937F,  -0.20724465F,
      0.170035407F,   -0.00882798713F, 0.0145362737F,   -0.203619212F,
      -0.0564430095F, -0.0194707476F,  -0.017311573F,   0.206104591F,
      0.0666818F,     0.220999092F,    -0.00132372917F, -0.0585077852F,
      -0.0199731383F, 0.15618518F,     0.371311098F,    0.226526231F,
      -0.201489568F,  -0.0973544F,     0.230482787F,    -0.149059653F,
      -0.165560871F,  -0.125799149F,   -0.171630457F,   -0.106793314F,
      -0.0708716363F, -0.11809884F,    -0.208402172F,   0.0757342353F};
  static const float fv2[6] = {-0.208084226F,   0.0344054F,    0.179120213F,
                               -0.00685805827F, -0.470739305F, 0.097508125F};
  static const float fv[3] = {0.14628531F, 0.818803608F, -0.175789207F};
  static float t0_Weights[76800];
  static bool bufferInitialized;
  float outT_f2_0_f1[4800];
  float outT_f3_0_f1[2400];
  float b_inputsT_0_f1[450];
  float layerOutput[32];
  float b_layerOutput[6];
  int inputsT_0_f1_tmp;
  int outChannelIdx;
  int outWidthIdx;
  if (!bufferInitialized) {
    readDnnConstants(&t0_Weights[0],
                     "./codegen/lib/Net_predict/largeDnnConstants_1210616.bin",
                     76800);
  }
  bufferInitialized = true;
  if (!obj->IsNetworkInitialized) {
    obj->IsNetworkInitialized = true;
  }
  for (outChannelIdx = 0; outChannelIdx < 3; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 150; outWidthIdx++) {
      inputsT_0_f1_tmp = outWidthIdx + 150 * outChannelIdx;
      b_inputsT_0_f1[inputsT_0_f1_tmp] =
          inputsT_0_f1[inputsT_0_f1_tmp] - fv[outChannelIdx];
    }
  }
  conv2dDirectOptimizedColMajor(b_inputsT_0_f1, outT_f2_0_f1);
  for (outChannelIdx = 0; outChannelIdx < 32; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 75; outWidthIdx++) {
      inputsT_0_f1_tmp = (outWidthIdx << 1) + 150 * outChannelIdx;
      outT_f3_0_f1[outWidthIdx + 75 * outChannelIdx] =
          fmaxf(fmaxf(-3.402823466E+38F, outT_f2_0_f1[inputsT_0_f1_tmp]),
                outT_f2_0_f1[inputsT_0_f1_tmp + 1]);
    }
  }
  matrixMultiply1(32, 2400, 1, 64, 64, 64, &t0_Weights[0], &outT_f3_0_f1[0],
                  &layerOutput[0]);
  for (inputsT_0_f1_tmp = 0; inputsT_0_f1_tmp < 32; inputsT_0_f1_tmp++) {
    layerOutput[inputsT_0_f1_tmp] =
        fmaxf(0.0F, layerOutput[inputsT_0_f1_tmp] + fv1[inputsT_0_f1_tmp]);
  }
  matrixMultiply1(6, 32, 1, 64, 64, 64, &A[0], &layerOutput[0],
                  &b_layerOutput[0]);
  for (outChannelIdx = 0; outChannelIdx < 6; outChannelIdx++) {
    b_layerOutput[outChannelIdx] += fv2[outChannelIdx];
  }
  SoftmaxLayer_predict(b_layerOutput, outputs_0_f1);
}

/*
 * File trailer for callPredict.c
 *
 * [EOF]
 */

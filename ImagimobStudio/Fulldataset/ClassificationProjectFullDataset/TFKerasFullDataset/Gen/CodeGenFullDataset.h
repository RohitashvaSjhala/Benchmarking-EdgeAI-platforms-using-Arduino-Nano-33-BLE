/*
* Imagimob Studio 4.8.1397+ec7f68f457701b125b40ecb6a3e43a64ab83bbf6
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 05/31/2024 00:13:10 UTC. Any changes will be lost.
* 
* Model ID  588148d4-0762-4edd-a2bb-31ef7c859096
* 
* Memory    Size                      Efficiency
* Buffers   49500 bytes (RAM)         97 %
* State     1708 bytes (RAM)          100 %
* Readonly  769664 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   TFKerasFullDataset
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | Downstairs
* 2           | Jogging
* 3           | Sitting
* 4           | Standing
* 5           | Upstairs
* 6           | Walking
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [125,3]         float      dequeue
*    window_shape = [125,3]
*    stride = 3
*    buffer_multiplier = 1
* Input Layer                    [125,3]         float      dequeue
*    shape = [125,3]
* Reshape                        [125,3,1]       float      dequeue
*    shape = [125,3,1]
*    trainable = False
* Convolution 2D                 [125,3,16]      float      dequeue
*    filters = 16
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = relu
*    use_bias = True
*    trainable = True
*    weight = float[3,3,1,16]
*    bias = float[16]
* Max pooling 2D                 [125,3,16]      float      dequeue
*    pool_size = [3,3]
*    strides = [1,1]
*    padding = same
*    trainable = True
* Flatten                        [6000]          float      dequeue
* Dense                          [32]            float      dequeue
*    units = 32
*    use_bias = True
*    activation = relu
*    trainable = True
*    weight = float[6000,32]
*    bias = float[32]
* Dense                          [7]             float      dequeue
*    units = 7
*    use_bias = False
*    activation = softmax
*    trainable = True
*    weight = float[32,7]
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[7].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[3].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_CODEGENFULLDATASET_H_
#define _IMAI_CODEGENFULLDATASET_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 96.527 %
* (F1S) F1 Score 96.467 %
* 
* Name of class                                            (unlabelled)       Downstairs          Jogging          Sitting         Standing         Upstairs          Walking
* (TP) True Positive or Correct Positive Prediction                   0            19046            31704            67741            23790            14169            53970
* (FN) False Negative or Incorrect Negative Prediction                0             3782              395               36                0             2778              580
* (FP) False Positive or Incorrect Positive Prediction                0             1638               42                0               36             1810             4045
* (TN) True Negative or Correct Negative Prediction              217991           193525           185850           150214           194165           199234           159396
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          83.43 %          98.77 %          99.95 %         100.00 %          83.61 %          98.94 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.16 %          99.98 %         100.00 %          99.98 %          99.10 %          97.53 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          92.08 %          99.87 %         100.00 %          99.85 %          88.67 %          93.03 %
* (NPV) Negative Predictive Value                              100.00 %          98.08 %          99.79 %          99.98 %         100.00 %          98.62 %          99.64 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %          16.57 %           1.23 %           0.05 %           0.00 %          16.39 %           1.06 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.84 %           0.02 %           0.00 %           0.02 %           0.90 %           2.47 %
* (FDR) False Discovery Rate                                   100.00 %           7.92 %           0.13 %           0.00 %           0.15 %          11.33 %           6.97 %
* (FOR) False Omission Rate                                      0.00 %           1.92 %           0.21 %           0.02 %           0.00 %           1.38 %           0.36 %
* (F1S) F1 Score                                               100.00 %          87.54 %          99.32 %          99.97 %          99.92 %          86.07 %          95.89 %
*/


#define IMAI_TEST_AVG_ACC 0.9652692083618131 // Accuracy
#define IMAI_TEST_AVG_F1S 0.964668315708399 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 217991, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Downstairs", TP: 19046, FN: 3782, FP: 1638, TN: 193525, TPR: 0.8343262659891, TNR: 0.9916070156740, PPV: 0.9208083542835, NPV: 0.9808319015544, FNR: 0.1656737340108, FPR: 0.0083929843259, FDR: 0.0791916457164, FOR: 0.0191680984455, F1S: 0.8754366611509, }, \
 {name: "Jogging", TP: 31704, FN: 395, FP: 42, TN: 185850, TPR: 0.9876943206953, TNR: 0.9997740623587, PPV: 0.9986769986769, NPV: 0.9978791376949, FNR: 0.0123056793046, FPR: 0.0002259376412, FDR: 0.0013230013230, FOR: 0.0021208623050, F1S: 0.9931552979873, }, \
 {name: "Sitting", TP: 67741, FN: 36, FP: 0, TN: 150214, TPR: 0.9994688463638, TNR: 1, PPV: 1, NPV: 0.9997603993344, FNR: 0.0005311536361, FPR: 0, FDR: 0, FOR: 0.0002396006655, F1S: 0.9997343526321, }, \
 {name: "Standing", TP: 23790, FN: 0, FP: 36, TN: 194165, TPR: 1, TNR: 0.9998146250534, PPV: 0.9984890455804, NPV: 1, FNR: 0, FPR: 0.0001853749465, FDR: 0.0015109544195, FOR: 0, F1S: 0.9992439516129, }, \
 {name: "Upstairs", TP: 14169, FN: 2778, FP: 1810, TN: 199234, TPR: 0.8360771818020, TNR: 0.9909969956825, PPV: 0.8867263283059, NPV: 0.9862483416826, FNR: 0.1639228181979, FPR: 0.0090030043174, FDR: 0.1132736716940, FOR: 0.0137516583173, F1S: 0.8606572313673, }, \
 {name: "Walking", TP: 53970, FN: 580, FP: 4045, TN: 159396, TPR: 0.9893675527039, TNR: 0.9752510080090, PPV: 0.9302766525898, NPV: 0.9963744561684, FNR: 0.0106324472960, FPR: 0.0247489919909, FDR: 0.0697233474101, FOR: 0.0036255438315, F1S: 0.9589126282592, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 96.536 %
* (F1S) F1 Score 96.531 %
* 
* Name of class                                            (unlabelled)       Downstairs          Jogging          Sitting         Standing         Upstairs          Walking
* (TP) True Positive or Correct Positive Prediction                   0            70828            68602           199753           257740           105947           220401
* (FN) False Negative or Incorrect Negative Prediction                0            10231             1852               12              246            12271             8519
* (FP) False Positive or Incorrect Positive Prediction                0             9290             1393              213             1061            12596             8578
* (TN) True Negative or Correct Negative Prediction              956402           866053           884555           756424           697355           825588           718904
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          87.38 %          97.37 %          99.99 %          99.90 %          89.62 %          96.28 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.94 %          99.84 %          99.97 %          99.85 %          98.50 %          98.82 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          88.40 %          98.01 %          99.89 %          99.59 %          89.37 %          96.25 %
* (NPV) Negative Predictive Value                              100.00 %          98.83 %          99.79 %         100.00 %          99.96 %          98.54 %          98.83 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %          12.62 %           2.63 %           0.01 %           0.10 %          10.38 %           3.72 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.06 %           0.16 %           0.03 %           0.15 %           1.50 %           1.18 %
* (FDR) False Discovery Rate                                   100.00 %          11.60 %           1.99 %           0.11 %           0.41 %          10.63 %           3.75 %
* (FOR) False Omission Rate                                      0.00 %           1.17 %           0.21 %           0.00 %           0.04 %           1.46 %           1.17 %
* (F1S) F1 Score                                               100.00 %          87.89 %          97.69 %          99.94 %          99.75 %          89.50 %          96.27 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9653587089947533 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9653137161867003 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 956402, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Downstairs", TP: 70828, FN: 10231, FP: 9290, TN: 866053, TPR: 0.8737832936503, TNR: 0.9893870174320, PPV: 0.8840460321026, NPV: 0.9883245614435, FNR: 0.1262167063496, FPR: 0.0106129825679, FDR: 0.1159539678973, FOR: 0.0116754385564, F1S: 0.8788847043933, }, \
 {name: "Jogging", TP: 68602, FN: 1852, FP: 1393, TN: 884555, TPR: 0.9737133448775, TNR: 0.9984276729559, PPV: 0.9800985784698, NPV: 0.9979106663191, FNR: 0.0262866551224, FPR: 0.0015723270440, FDR: 0.0199014215301, FOR: 0.0020893336808, F1S: 0.9768955279140, }, \
 {name: "Sitting", TP: 199753, FN: 12, FP: 213, TN: 756424, TPR: 0.9999399294170, TNR: 0.9997184911655, PPV: 0.9989348189192, NPV: 0.9999841361331, FNR: 6.0070582934948, FPR: 0.0002815088344, FDR: 0.0010651810807, FOR: 1.5863866870429, F1S: 0.9994371214641, }, \
 {name: "Standing", TP: 257740, FN: 246, FP: 1061, TN: 697355, TPR: 0.9990464598854, TNR: 0.9984808480905, PPV: 0.9959003249601, NPV: 0.9996473628908, FNR: 0.0009535401145, FPR: 0.0015191519094, FDR: 0.0040996750398, FOR: 0.0003526371091, F1S: 0.9974709116134, }, \
 {name: "Upstairs", TP: 105947, FN: 12271, FP: 12596, TN: 825588, TPR: 0.8962002402341, TNR: 0.9849722733910, PPV: 0.8937431986705, NPV: 0.9853543376630, FNR: 0.1037997597658, FPR: 0.0150277266089, FDR: 0.1062568013294, FOR: 0.0146456623369, F1S: 0.8949700330713, }, \
 {name: "Walking", TP: 220401, FN: 8519, FP: 8578, TN: 718904, TPR: 0.9627861261576, TNR: 0.9882086429629, PPV: 0.9625380493407, NPV: 0.9882887948277, FNR: 0.0372138738423, FPR: 0.0117913570370, FDR: 0.0374619506592, FOR: 0.0117112051722, F1S: 0.9626620717669, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 90.522 %
* (F1S) F1 Score 90.698 %
* 
* Name of class                                            (unlabelled)       Downstairs          Jogging          Sitting         Standing         Upstairs          Walking
* (TP) True Positive or Correct Positive Prediction                   0            13905            26290            69713            19679            11816            53030
* (FN) False Negative or Incorrect Negative Prediction                0             7634             1620               49             3135             4173             3748
* (FP) False Positive or Incorrect Positive Prediction                0             5959               70              122               56             8259             5893
* (TN) True Negative or Correct Negative Prediction              214792           187294           186812           144908           191922           190544           152121
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          64.56 %          94.20 %          99.93 %          86.26 %          73.90 %          93.40 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          96.92 %          99.96 %          99.92 %          99.97 %          95.85 %          96.27 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          70.00 %          99.73 %          99.83 %          99.72 %          58.86 %          90.00 %
* (NPV) Negative Predictive Value                              100.00 %          96.08 %          99.14 %          99.97 %          98.39 %          97.86 %          97.60 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %          35.44 %           5.80 %           0.07 %          13.74 %          26.10 %           6.60 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           3.08 %           0.04 %           0.08 %           0.03 %           4.15 %           3.73 %
* (FDR) False Discovery Rate                                   100.00 %          30.00 %           0.27 %           0.17 %           0.28 %          41.14 %          10.00 %
* (FOR) False Omission Rate                                      0.00 %           3.92 %           0.86 %           0.03 %           1.61 %           2.14 %           2.40 %
* (F1S) F1 Score                                               100.00 %          67.17 %          96.89 %          99.88 %          92.50 %          65.53 %          91.67 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.905215278036426 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9069803687461239 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 214792, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Downstairs", TP: 13905, FN: 7634, FP: 5959, TN: 187294, TPR: 0.6455731463856, TNR: 0.9691647736387, PPV: 0.7000100684655, NPV: 0.9608368218008, FNR: 0.3544268536143, FPR: 0.0308352263612, FDR: 0.2999899315344, FOR: 0.0391631781991, F1S: 0.6716904572132, }, \
 {name: "Jogging", TP: 26290, FN: 1620, FP: 70, TN: 186812, TPR: 0.9419562880687, TNR: 0.9996254320908, PPV: 0.9973444613050, NPV: 0.9914027341428, FNR: 0.0580437119312, FPR: 0.0003745679091, FDR: 0.0026555386949, FOR: 0.0085972658571, F1S: 0.9688594066703, }, \
 {name: "Sitting", TP: 69713, FN: 49, FP: 122, TN: 144908, TPR: 0.9992976118803, TNR: 0.9991587947321, PPV: 0.9982530249874, NPV: 0.9996619687217, FNR: 0.0007023881196, FPR: 0.0008412052678, FDR: 0.0017469750125, FOR: 0.0003380312782, F1S: 0.9987750453089, }, \
 {name: "Standing", TP: 19679, FN: 3135, FP: 56, TN: 191922, TPR: 0.8625843780135, TNR: 0.9997082999093, PPV: 0.9971624018241, NPV: 0.9839277749580, FNR: 0.1374156219864, FPR: 0.0002917000906, FDR: 0.0028375981758, FOR: 0.0160722250419, F1S: 0.9250041129051, }, \
 {name: "Upstairs", TP: 11816, FN: 4173, FP: 8259, TN: 190544, TPR: 0.7390080680467, TNR: 0.9584563613225, PPV: 0.5885927770859, NPV: 0.9785688974254, FNR: 0.2609919319532, FPR: 0.0415436386774, FDR: 0.4114072229140, FOR: 0.0214311025745, F1S: 0.6552795031055, }, \
 {name: "Walking", TP: 53030, FN: 3748, FP: 5893, TN: 152121, TPR: 0.9339885166789, TNR: 0.9627058361917, PPV: 0.8999881200889, NPV: 0.9759541666399, FNR: 0.0660114833210, FPR: 0.0372941638082, FDR: 0.1000118799110, FOR: 0.0240458333600, F1S: 0.9166731488924, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Downstairs", "Jogging", "Sitting", "Standing", "Upstairs", "Walking"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xd4, 0x48, 0x81, 0x58, 0x62, 0x07, 0xdd, 0x4e, 0xa2, 0xbb, 0x31, 0xef, 0x7c, 0x85, 0x90, 0x96}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [3] (12 bytes)
#define IMAI_DATA_IN_COUNT (3)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [7] (28 bytes)
#define IMAI_DATA_OUT_COUNT (7)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (17)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float */*restrict*/ data_out);
int IMAI_enqueue(const float */*restrict*/ data_in);
void IMAI_init(void);

#endif /* _IMAI_CODEGENFULLDATASET_H_ */

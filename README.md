# Benchmarking-EdgeAI-platforms-using-Arduino-Nano-33-BLE
This repository contains my 6-month master's thesis project in the field of embedded AI. I worked to evaluate a series of Edge AI frameworks on a set of 5 metrics: accuracy, memory consumption (RAM+Flash), inference time, current consumption, and usability of the frameworks. In terms of usability, 4 main usability principles were chosen for the assessment: User Control and Freedom, Clarity, Help and Documentation, and Compatibility.
A baseline simple CNN model was designed as a foundational template using Keras and Google Colab for other frameworks to follow. This model architecture and configurations were replicated within all the frameworks ensuring consistency and comparability across different EdgeAI frameworks. Overall, the work concluded with the results from all five metrics and future work with the scope for improvements for case-to-case application scenarios. 

## Repo Structure
This repository contains folders for each EdgeAI framework that has been implemented and tested. Each framework is organized into its own folder, and within these folders, you will find sub-folders and files necessary for deployment on a Microcontroller Unit (MCU). 

## Deployment
* **Baseline CNN:** It contains the baseline model developed with Keras and Google Colab to be followed by the other frameworks. 
* **Edge Impulse:** The folder contains the source files of the trained model with its parameters and weights. The .ino file is specific to the Arduino Nano 33 BLE board and is ready to be deployed while containing all the functions necessary to perform inference.
* **Edge-ML:** This folder contains the trained decision tree classifier from the Edge-ML framework. Although, not part of the final evaluation because the framework is still in the beta version, I have included the model nonetheless for reference.
* **Imagimob Studio:** It stores the trained model "TFKerasFullDataset_min_max.md" with corresponding code gen files (C/C++) for deployment. The .ino file contains all the functionality necessary to perform the inference on the hardware device.
* **Matlab:** The folder contains multiple trials of classification models as Matlab functions. Additionally, corresponding C/C++ source files were generated for these functions to carry out deployment tests. However, the framework failed to demonstrate end-to-end edgeAI development and hence, was removed from the final evaluation.
* **NanoEdge AI Studio:** The folder contains the library (with .a extension) which encloses the source codes, and the arduino file (.ino) required for performing inference.
* **TFLite Micro:** It contains the trained python model (.pb), converted tflite model (.tflite), and the C-array file (.cc) of the model ready to run on the microcontroller. The "Hello world" example is used as a basis to perform the inference and has been modified according to the needs containing the C-array of the trained model.

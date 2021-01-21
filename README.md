# **IsoPhase**
This is the IsoPhase project page. Source code and contents that we was not able to cover in the paper due to the page limit are placed here.
## List of TensorFlow APIs
`TF API` contains the full list of TensorFlow API categorization.
## **Quick Start**
[simple demo](https://github.com/IsoPhase-security/IsoPhase/tree/main/demo)
It is OpenCV IsoPhase demo. Run with test.sh
## **Static API Analysis Tool**
We use the ast module of Python to analyze the target application's source code. 

[typed-ast](https://github.com/python/typed_ast) is used to extract API metadata from pyi files in the framework libraries.

Details are shown in `tools/Python_static_analysis`.
## **IsoPhase Source Code**
`code` folder contains the source code of IsoPhase.
## **Pipeline Application List**
In section 5 discussion, we mention that it is general that data processing applications follow the pipeline style data transfer.

This folder contains the list of most popular applications in the corresponding framework's topic in the GitHub. We evaluated them and found they all follow the pipeline style data transfer. 

Details are shown in `list.md`.

## **Kernel Module**
We use a configurable kernel module to block unintended syscalls.

Details are in `tools/kernel_module`.

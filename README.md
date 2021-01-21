# **IsoPhase**
This is the IsoPhase project page. Source code and contents that we was not able to cover in the paper due to the page limit are placed here.
## List of TensorFlow APIs
In section 10, we mentioned that we could not put the whole list of categorized TensorFlow APIs due to the paper limit.

`TF API` contains the full list of TensorFlow API categorization.

Details are shown in `TF API/phase.txt`.
## **Quick Start**
[simple demo](https://github.com/IsoPhase-security/IsoPhase/tree/main/demo)
It is OpenCV IsoPhase demo. Run with test.sh.
## **Static API Analysis Tool**
We use the ast module of Python to analyze the target application's source code. 

[typed-ast](https://github.com/python/typed_ast) is used to extract API metadata from pyi files in the framework libraries.

Details are shown in `tools/Python_static_analysis`.
## **IsoPhase Source Code**
`code` folder contains the source code of IsoPhase.
## **Application List**
In section 5 discussion, we mentioned that it is general that data processing applications follow the pipeline style data transfer.

This folder contains the list of most popular applications in the corresponding framework's topic in the GitHub. We evaluated them and found they all follow the pipeline style data transfer. 

Details are shown in `list.md`.

## **Kernel Module**
In section 2.1.2, we mentioned that IsoPhase uses a kernel module to block unintended syscalls. 

This folder contains the source code of a configurable kernel module.

Details are in `tools/kernel_module`.

## **CVEs**
`CVE cases` contains the POC image used by us to trigger the vulnerabilities of the underlying frameworks.
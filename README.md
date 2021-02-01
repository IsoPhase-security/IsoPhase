# **IsoPhase**
This is the IsoPhase project page. Source code and contents that we was not able to cover in the paper due to the page limit are placed here.
## List of TensorFlow APIs
In section 10, we mentioned that we could not put the whole list of categorized TensorFlow APIs due to the paper limit.

`TF API` contains the full list of TensorFlow API categorization.

Details are shown in `TF API/phase.txt`.


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
We evluated the CVEs of popular data processing frameworks including `OpenCV, Numpy, Pillow, TensorFlow, PyTorch and Caffe` and found that 59/92 CVEs are in Phase 1, 33/92 CVEs are in phase 2 and no CVE is in Phase 3.

Details are shown in `list.md`.

`CVE cases` contains the POC image used by us to trigger the vulnerabilities of the underlying frameworks.

## **Quick Start**
[simple demo](https://github.com/IsoPhase-security/IsoPhase/tree/main/demo)

Demo program with debug infomation will print the requested command in the terminal. 
It will automatically assign new index to a object is constructed to be stored in the shared memory and the index will be freed when the corresponding object is destructed.
### Execution of main process with debug information 
![main process](imgs/main.gif "main process")
### Execution of phase 1 with debug information 
![phase1](imgs/phase1.gif "phase1")
### Execution of phase 2 with debug information 
![phase2](imgs/phase2.gif "phase2")
### Execution of phase 3 with debug information 
![phase3](imgs/phase3.gif "phase3")

# **IsoPhase**
This is the IsoPhase project page. Source code and contents that we was not able to cover in the paper due to the page limit are placed here.
## **Application List**
In section 5 discussion, we mentioned that it is general that data processing applications follow the pipeline style data transfer.

This folder contains the list of most popular applications in the corresponding framework's topic in the GitHub. We evaluated them and found they all follow the pipeline style data transfer. 

Details are shown in [`Application List`](Application).

## **Impact of Vulnerability**
We evluated the CVEs of popular data processing frameworks including `OpenCV`, `Numpy`, `Pillow`, `TensorFlow`, `PyTorch` and `Caffe` and found that 59/92 CVEs are in Phase 1, 33/92 CVEs are in phase 2 and no CVE is in Phase 3.

Details about the information in each phase are in [`Application List`](Application).

`CVE cases` contains the POC image used by us to trigger the vulnerabilities of the underlying frameworks.

## List of TensorFlow APIs
In section 10, we mentioned that we could not put the whole list of categorized TensorFlow APIs due to the page limit.

`TF API` contains the full list of TensorFlow API categorization.

Details are shown in `TF API/phase.txt`.

## **IsoPhase Source Code**
`code` folder contains the source code of IsoPhase. It includes the static analysis tools and the run-time support tools of IsoPhase.








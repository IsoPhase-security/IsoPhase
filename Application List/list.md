# Analyzed Applications
We searched popular applications under topic OpenCV, PyTorch, Caffe and TensorFlow. The popularity is measured by the number of stars. 

We manually inspect the source code of these projects and find those deep learning framework based applications do not break the assumptions on the pipline data flow pattern. 


## List of Analyzed CVEs

We analyzed the CVEs on these 6 data processing related libraries and we find that vulnerablities only happens in Phase 1 and Phase 2. And except TensorFlow, other most of the frameworks' vulnerabilities are in phase 1. So when IsoPhase is applied to the target application, the most important phase3 can be protected from those CVEs.


|            | OpenCV           | Numpy          | pillow         | TensorFlow     |PyTorch|Caffe|
| ---------- | ---------------- | -------------- | -------------- | -------------- |-------|-----|
|    Phase1  | CVE-2019-5064    | CVE-2019-6446  | CVE-2020-5313  | CVE-2020-26271 |N/A|N/A|
|            | CVE-2019-5063    |                | CVE-2020-5312  | CVE-2019-9635  |
|            | CVE-2019-14493   |                | CVE-2020-5311  | CVE-2018-21233 |
|            | CVE-2018-7714    |                | CVE-2020-5310  | CVE-2018-7575  |
|            | CVE-2018-7713    |                | CVE-2020-35655 | CVE-2018-7576  |
|            | CVE-2018-7712    |                | CVE-2020-35654 |                |
|            | CVE-2018-5269    |                | CVE-2020-35653 |                |
|            | CVE-2018-5268    |                | CVE-2020-11538 |                |
|            | CVE-2017-18009   |                | CVE-2020-11538 |                |
|            | CVE-2017-17760   |                | CVE-2020-10379 |                |
|            | CVE-2017-14136   |                | CVE-2020-10378 |                |
|            | CVE-2017-12864   |                | CVE-2020-10177 |                |
|            | CVE-2017-12863   |                | CVE-2019-19911 |                |
|            | CVE-2017-12862   |                | CVE-2019-16865 |                |
|            | CVE-2017-12606   |                | CVE-2016-9190  |                |
|            | CVE-2017-12605   |                | CVE-2016-9189  |                |
|            | CVE-2017-12604   |                | CVE-2016-3076  |                |
|            | CVE-2017-12603   |                | CVE-2016-2533  |                |
|            | CVE-2017-12602   |                | CVE-2016-0775  |                |
|            | CVE-2017-12601   |                | CVE-2016-0740  |                |
|            | CVE-2017-12600   |                | CVE-2014-9601  |                |
|            | CVE-2017-12599   |                | CVE-2014-3598  |                |
|            | CVE-2017-12598   |                | CVE-2014-3589  |                |
|            | CVE-2017-12597   |                | CVE-2014-3007  |                |
|            | CVE-2017-1000450 |                | CVE-2014-1933  |                |
|            | CVE-2016-1516    |                | CVE-2014-1932  |                |
|            | CVE-2016-1517    |                |                |                | 
| Phase 2    | CVE-2019-19624   | CVE-2017-12852 | CVE-2016-4009  | CVE-2020-5215  |
|            | CVE-2019-15939   |                |                | CVE-2020-26270 |
|            | CVE-2019-14492   |                |                | CVE-2020-26269 |
|            | CVE-2019-14491   |                |                | CVE-2020-26268 |
|            |                  |                |                | CVE-2020-26267 |
|            |                  |                |                | CVE-2020-26266 |
|            |                  |                |                | CVE-2020-15266 |
|            |                  |                |                | CVE-2020-15265 |
|            |                  |                |                | CVE-2020-15206 |
|            |                  |                |                | CVE-2020-15205 |
|            |                  |                |                | CVE-2020-15204 |
|            |                  |                |                | CVE-2020-15203 |
|            |                  |                |                | CVE-2020-15202 |
|            |                  |                |                | CVE-2020-15201 |
|            |                  |                |                | CVE-2020-15200 |
|            |                  |                |                | CVE-2020-15199 |
|            |                  |                |                | CVE-2020-15198 |
|            |                  |                |                | CVE-2020-15197 |
|            |                  |                |                | CVE-2020-15196 |
|            |                  |                |                | CVE-2020-15195 |
|            |                  |                |                | CVE-2020-15194 |
|            |                  |                |                | CVE-2020-15193 |
|            |                  |                |                | CVE-2020-15192 |
|            |                  |                |                | CVE-2020-15191 |
|            |                  |                |                | CVE-2020-15190 |
|            |                  |                |                | CVE-2019-16778 |
|            |                  |                |                | CVE-2018-21233 |
| Phase 3 |         N/A         |   N/A             |  N/A              |  N/A              |

|Syntax|Information Type|
|----|----------------|
|S<sub>1</sub>|result values of algorithm|
|S<sub>2</sub>|outputs annotated with the results and sensitive information|
|S<sub>3</sub>|sensitive metadata that the program loads|
|S<sub>4</sub>|ML models|

## List of Applications
|FrameWork|Name|Link|
|---------|----|-------|
|OpenCV|Face_Recognition|https://github.com/ageitgey/face_recognition|
|OpenCV|faceai|https://github.com/vipstone/faceai|
|OpenCV|BossSensor|https://github.com/Hironsan/BossSensor|
|OpenCV|tiler|https://github.com/nuno-faria/tiler|
|OpenCV|sistine|https://github.com/bijection/sistine|
|OpenCV|trace.moe|https://github.com/soruly/trace.moe|
|OpenCV|mathAI|https://github.com/Roujack/mathAI|
|OpenCV|Is-Now-Illegal|https://github.com/ivanseidel/Is-Now-Illegal|
|OpenCV|video-to-ascii|https://github.com/joelibaceta/video-to-ascii|
|OpenCV|DeepNude_NoWatermark_withModel|https://github.com/zhengyima/DeepNude_NoWatermark_withModel|
|OpenCV|idcardgenerator|https://github.com/airob0t/idcardgenerator|
|OpenCV|eyeLike|https://github.com/trishume/eyeLike|
|OpenCV|Anime-InPainting|https://github.com/youyuge34/Anime-InPainting|
|OpenCV|lbpcascade_animeface|https://github.com/nagadomi/lbpcascade_animeface|
|OpenCV|captcha-break|https://github.com/nladuo/captcha-break|
|OpenCV|vehicle_detection|https://github.com/tatsuyah/vehicle-detection|
|PyTorch|Real-Time-Voice-Cloning|https://github.com/CorentinJ/Real-Time-Voice-Cloning|
|PyTorch|pytorch-CycleGAN-and-pix2pix|https://github.com/junyanz/pytorch-CycleGAN-and-pix2pix|
|PyTorch|mmdetection|https://github.com/open-mmlab/mmdetection|
|PyTorch|fairseq|https://github.com/pytorch/fairseq|
|PyTorch|EasyOCR|https://github.com/JaidedAI/EasyOCR|
|PyTorch|yolov5|https://github.com/ultralytics/yolov5|
|PyTorch|Bringing-Old-Photos-Back-to-Life|https://github.com/microsoft/Bringing-Old-Photos-Back-to-Life|
|PyTorch|yolov3|https://github.com/ultralytics/yolov3|
|PyTorch|chineseocr_lite|https://github.com/ouyanghuiyu/chineseocr_lite|
|PyTorch|pix2pixHD|https://github.com/NVIDIA/pix2pixHD|
|PyTorch|stargan|https://github.com/yunjey/stargan|
|PyTorch|SiamMask|https://github.com/foolwood/SiamMask|
|PyTorch|Pytorch-UNet|https://github.com/milesial/Pytorch-UNet|
|PyTorch|EfficientNet-PyTorch|https://github.com/lukemelas/EfficientNet-PyTorch|
|PyTorch|Semantic-Segmentation|https://github.com/CSAILVision/semantic-segmentation-pytorch|
|TensorFlow|Real-Time-Voice-Cloning|https://github.com/CorentinJ/Real-Time-Voice-Cloning|
|TensorFlow|DeepSpeech|https://github.com/mozilla/DeepSpeech|
|TensorFlow|facenet|https://github.com/davidsandberg/facenet|
|TensorFlow|DeepCreamPy|https://github.com/deeppomf/DeepCreamPy|
|TensorFlow|Learning-to-See-in-the-Dark|https://github.com/cchen156/Learning-to-See-in-the-Dark|
|TensorFlow|tf-pose-estimation|https://github.com/ildoonet/tf-pose-estimation|
|TensorFlow|CapsNet-Tensorflow|https://github.com/naturomics/CapsNet-Tensorflow|
|TensorFlow|text-classification-cnn-rnn|https://github.com/gaussic/text-classification-cnn-rnn|
|TensorFlow|tensorflow-yolov3|https://github.com/YunYang1994/tensorflow-yolov3|
|TensorFlow|tensorflow_poems|https://github.com/jinfagang/tensorflow_poems|
|TensorFlow|Automatic_Speech_Recognition|https://github.com/zzw922cn/Automatic_Speech_Recognition|
|TensorFlow|AnimeGAN|https://github.com/TachibanaYoshino/AnimeGAN|
|TensorFlow|srgan|https://github.com/tensorlayer/srgan|
|TensorFlow|DCGAN-TensorFlow|https://github.com/carpedm20/DCGAN-tensorflow|
|TensorFlow|Style-Transfer|https://github.com/lengstrom/fast-style-transfer|
|Caffe|openpose|https://github.com/CMU-Perceptual-Computing-Lab/openpose|
|Caffe|MobileNet-SSD|https://github.com/chuanqi305/MobileNet-SSD|
|Caffe|EmoRecon|https://github.com/sushant3095/RealtimeFacialEmotionRecognition|
|Caffe|MTCNN|https://github.com/CongWeilin/mtcnn-caffe|
|Caffe|FaceMaskDetection|https://github.com/AIZOOTech/FaceMaskDetection|
|Caffe|face_verification|https://github.com/AlfredXiangWu/face_verification_experiment|
|Caffe|Face-Mask-Detection|https://github.com/chandrikadeb7/Face-Mask-Detection|
|Caffe|person_search|https://github.com/ShuangLI59/person_search|
|Caffe|multi-object-tracker|https://github.com/adipandas/multi-object-tracker|
|Caffe|caffe-yolov3|https://github.com/ChenYingpeng/caffe-yolov3|
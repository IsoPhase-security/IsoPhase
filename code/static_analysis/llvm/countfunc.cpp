//------------------------------------------------------------------------------
// simple_module_pass LLVM sample. Demonstrates:
//
// * How to write a ModulePass
// * How to iterate over the global values in a module, and access their names
//   and types.
// * How to produce a string representation of a LLVM type.
//
// Eli Bendersky (eliben@gmail.com)
// This code is in the public domain
//------------------------------------------------------------------------------
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Pass.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <unordered_set>
#include <vector>
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/InstrTypes.h" // It seems that LLVM 3.8 don't have CallBase...
#include "llvm/IR/CFG.h"
#include "llvm/IR/InstVisitor.h"
#include "llvm/IR/DebugLoc.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/ADT/StringExtras.h"
#include "llvm/Demangle/Demangle.h"
using namespace llvm;

// Helper method for converting the name of a LLVM type to a string
static std::string LLVMTypeAsString(const Type *T) {
  std::string TypeName;
  raw_string_ostream N(TypeName);
  T->print(N);
  return N.str();
}
//char target[7][30]=["Classifier","predict","argmax","resize_image","load_image","blobproto_to_array","FromString"];
class GVNames : public ModulePass {
public:
  GVNames() : ModulePass(ID) {}
  std::vector<std::string>     target_opencv_function;
  std::vector<std::string> target_caffe_function;
  int count_caffe[600];
  int count_opencv[600];
  virtual bool runOnModule(Module &M) {
//load caffe target functions
    target_caffe_function.push_back("AllowForceBackward");
    target_caffe_function.push_back("AppendBottom");
    target_caffe_function.push_back("AppendParam");
    target_caffe_function.push_back("AppendTop");
    target_caffe_function.push_back("asum_data");
    target_caffe_function.push_back("asum_diff");
    target_caffe_function.push_back("AutoTopBlobs");
    target_caffe_function.push_back("Backward");
    target_caffe_function.push_back("Backward_cpu");
    target_caffe_function.push_back("Backward_gpu");
    target_caffe_function.push_back("BackwardDebugInfo");
    target_caffe_function.push_back("blob_names");
    target_caffe_function.push_back("blobs");
    target_caffe_function.push_back("bottom_ids");
    target_caffe_function.push_back("bottom_vecs");
    target_caffe_function.push_back("CanonicalAxisIndex");
    target_caffe_function.push_back("channels");
    target_caffe_function.push_back("CheckBlobCounts");
    target_caffe_function.push_back("ClearParamDiffs");
    target_caffe_function.push_back("CopyFrom");
    target_caffe_function.push_back("CopyTrainedLayersFrom");
    target_caffe_function.push_back("count");
    target_caffe_function.push_back("EqualNumBottomTopBlobs");
    target_caffe_function.push_back("ExactNumBottomBlobs");
    target_caffe_function.push_back("ExactNumTopBlobs");
    target_caffe_function.push_back("FillUnrolledNet");
    target_caffe_function.push_back("FilterNet");
    target_caffe_function.push_back("Forward");
    target_caffe_function.push_back("Forward_cpu");
    target_caffe_function.push_back("Forward_gpu");
    target_caffe_function.push_back("ForwardDebugInfo");
    target_caffe_function.push_back("ForwardFromTo");
    target_caffe_function.push_back("ForwardPrefilled");
    target_caffe_function.push_back("get_normalizer");
    target_caffe_function.push_back("height");
    target_caffe_function.push_back("InferBlobShape");
    target_caffe_function.push_back("Init");
    target_caffe_function.push_back("InitRand");
    target_caffe_function.push_back("input_shape");
    target_caffe_function.push_back("layer_names");
    target_caffe_function.push_back("layer_param");
    target_caffe_function.push_back("layers");
    target_caffe_function.push_back("LayerSetUp");
    target_caffe_function.push_back("loss");
    target_caffe_function.push_back("MaxBottomBlobs");
    target_caffe_function.push_back("MaxTopBlobs");
    target_caffe_function.push_back("MinBottomBlobs");
    target_caffe_function.push_back("MinTopBlobs");
    target_caffe_function.push_back("name");
    target_caffe_function.push_back("num");
    target_caffe_function.push_back("num_inputs");
    target_caffe_function.push_back("OutputBlobNames");
    target_caffe_function.push_back("param_propagate_down");
    target_caffe_function.push_back("params");
    target_caffe_function.push_back("params_lr");
    target_caffe_function.push_back("params_weight_decay");
    target_caffe_function.push_back("phase");
    target_caffe_function.push_back("Rand");
    target_caffe_function.push_back("RecurrentInputBlobNames");
    target_caffe_function.push_back("RecurrentInputShapes");
    target_caffe_function.push_back("RecurrentOutputBlobNames");
    target_caffe_function.push_back("Reshape");
    target_caffe_function.push_back("scale_data");
    target_caffe_function.push_back("scale_diff");
    target_caffe_function.push_back("set_loss");
    target_caffe_function.push_back("set_param_propagate_down");
    target_caffe_function.push_back("SetLossWeights");
    target_caffe_function.push_back("SetUp");
    target_caffe_function.push_back("shape");
    target_caffe_function.push_back("ShareData");
    target_caffe_function.push_back("ShareDiff");
    target_caffe_function.push_back("ShareTrainedLayersWith");
    target_caffe_function.push_back("ShareWeights");
    target_caffe_function.push_back("StartInternalThread");
    target_caffe_function.push_back("StateMeetsRule");
    target_caffe_function.push_back("StopInternalThread");
    target_caffe_function.push_back("sum_rows_of_H");
    target_caffe_function.push_back("sumsq_data");
    target_caffe_function.push_back("sumsq_diff");
    target_caffe_function.push_back("ToHDF5");
    target_caffe_function.push_back("top_ids");
    target_caffe_function.push_back("top_vecs");
    target_caffe_function.push_back("ToProto");
    target_caffe_function.push_back("Transform");
    target_caffe_function.push_back("type");
    target_caffe_function.push_back("Update");
    target_caffe_function.push_back("UpdateDebugInfo");
    target_caffe_function.push_back("width");
target_caffe_function.push_back("Blob");
target_caffe_function.push_back("AccuracyLayer");
target_caffe_function.push_back("ArgMaxLayer");
target_caffe_function.push_back("ConvolutionLayer");
target_caffe_function.push_back("DropoutLayer");
target_caffe_function.push_back("ELULayer");
target_caffe_function.push_back("ExpLayer");
target_caffe_function.push_back("Layer");
target_caffe_function.push_back("LogLayer");
target_caffe_function.push_back("PowerLayer");    
target_caffe_function.push_back("PReLULayer");
target_caffe_function.push_back("ReLULayer");
target_caffe_function.push_back("SoftmaxWithLossLayer");
target_caffe_function.push_back("ThresholdLayer");

    //load target opencv functions and constructors
    //OpenCV APIs: https://docs.opencv.org/ref/2.4.13.7/d2/d75/namespacecv.html#ac5f92f48ec32cacf5275969c33ee837d
    target_opencv_function.push_back("abs");
    target_opencv_function.push_back("absdiff");
    target_opencv_function.push_back("accumulate");
    target_opencv_function.push_back("accumulateProduct");
    target_opencv_function.push_back("accumulateSquare");
    target_opencv_function.push_back("accumulateWeighted");
    target_opencv_function.push_back("adaptiveBilateralFilter");
    target_opencv_function.push_back("adaptiveThreshold");
    target_opencv_function.push_back("add");
    target_opencv_function.push_back("addText");
    target_opencv_function.push_back("addWeighted");
    target_opencv_function.push_back("applyColorMap");
    target_opencv_function.push_back("approxPolyDP");
    target_opencv_function.push_back("arcLength");
    target_opencv_function.push_back("arrowedLine");
    target_opencv_function.push_back("batchDistance");
    target_opencv_function.push_back("bilateralFilter");
    target_opencv_function.push_back("bitwise_and");
    target_opencv_function.push_back("bitwise_not");
    target_opencv_function.push_back("bitwise_or");
    target_opencv_function.push_back("bitwise_xor");
    target_opencv_function.push_back("blur");
    target_opencv_function.push_back("borderInterpolate");
    target_opencv_function.push_back("boundingRect");
    target_opencv_function.push_back("boxFilter");
    target_opencv_function.push_back("buildOpticalFlowPyramid");
    target_opencv_function.push_back("buildPyramid");
    target_opencv_function.push_back("calcBackProject");
    target_opencv_function.push_back("calcCovarMatrix");
    target_opencv_function.push_back("calcHist");
    target_opencv_function.push_back("calcMotionGradient");
    target_opencv_function.push_back("calcOpticalFlowFarneback");
    target_opencv_function.push_back("calcOpticalFlowPyrLK");
    target_opencv_function.push_back("calcOpticalFlowSF");
    target_opencv_function.push_back("calcOpticalFlowSF");
    target_opencv_function.push_back("calibrateCamera");
    target_opencv_function.push_back("calibrationMatrixValues");
    target_opencv_function.push_back("CamShift");
    target_opencv_function.push_back("Canny");
    target_opencv_function.push_back("cartToPolar");
    target_opencv_function.push_back("chamerMatching");
    target_opencv_function.push_back("checkHardwareSupport");
    target_opencv_function.push_back("checkRange");
    target_opencv_function.push_back("Cholesky");
    target_opencv_function.push_back("circle");
    target_opencv_function.push_back("clearSeq");
    target_opencv_function.push_back("clipLine");
    target_opencv_function.push_back("analyzeValue");
    target_opencv_function.push_back("compare");
    target_opencv_function.push_back("compareHist");
    target_opencv_function.push_back("completeSymm");
    target_opencv_function.push_back("composeRT");
    target_opencv_function.push_back("computeCorrespondEpilines");
    target_opencv_function.push_back("computeRecallPrecisionCurve");
    target_opencv_function.push_back("conjugate");
    target_opencv_function.push_back("contourArea");
    target_opencv_function.push_back("convertMaps");
    target_opencv_function.push_back("convertPointsFromHomogeneous");
    target_opencv_function.push_back("convertPointsHomogeneous");
    target_opencv_function.push_back("convertPointsToHomogeneous");
    target_opencv_function.push_back("convertScaleAbs");
    target_opencv_function.push_back("convexHull");
    target_opencv_function.push_back("convexityDefects");
    target_opencv_function.push_back("copyMakeBorder");
    target_opencv_function.push_back("cornerEigenValsAndVecs");
    target_opencv_function.push_back("cornerHarris");
    target_opencv_function.push_back("cornerMinEigenVal");
    target_opencv_function.push_back("cornerSubPix");
    target_opencv_function.push_back("correctMatches");
    target_opencv_function.push_back("countNonZero");
    target_opencv_function.push_back("createBoxFilter");
    target_opencv_function.push_back("createButton");
    target_opencv_function.push_back("createCLAHE");
    target_opencv_function.push_back("createDerivFilter");
    target_opencv_function.push_back("createEigenFaceRecognizer");
    target_opencv_function.push_back("createFisherFaceRecognizer");
    target_opencv_function.push_back("createGaussianFilter");
    target_opencv_function.push_back("createHanningWindow");
    target_opencv_function.push_back("createLBPHFaceRecognizer");
    target_opencv_function.push_back("createLinearFilter");
    target_opencv_function.push_back("createMorphologyFilter");
    target_opencv_function.push_back("createOptFlow_DualTVL1");
    target_opencv_function.push_back("createSeparableLinearFilter");
    target_opencv_function.push_back("createTrackbar");
    target_opencv_function.push_back("cubeRoot");
    target_opencv_function.push_back("currentParallelFramework");
    target_opencv_function.push_back("cv2eigen");
    target_opencv_function.push_back("CV_EXPORTS_AS");
    target_opencv_function.push_back("cvarrToMat");
    target_opencv_function.push_back("cvtColor");
    target_opencv_function.push_back("dct");
    target_opencv_function.push_back("decomposeProjectionMatrix");
    target_opencv_function.push_back("destroyAllWindows");
    target_opencv_function.push_back("destroyWindow");
    target_opencv_function.push_back("determinant");
    target_opencv_function.push_back("dft");
    target_opencv_function.push_back("dilate");
    target_opencv_function.push_back("displayOverlay");
    target_opencv_function.push_back("displayStatusBar");
    target_opencv_function.push_back("distanceTransform");
    target_opencv_function.push_back("divide");
    target_opencv_function.push_back("dot");
    target_opencv_function.push_back("drawChessboardCorners");
    target_opencv_function.push_back("drawContours");
    target_opencv_function.push_back("drawDataMatrixCodes");
    target_opencv_function.push_back("drawKeypoints");
    target_opencv_function.push_back("drawMarker");
    target_opencv_function.push_back("drawMatches");
    target_opencv_function.push_back("eigen");
    target_opencv_function.push_back("eigen2cv");
    target_opencv_function.push_back("eigen2x2");
    target_opencv_function.push_back("ellipse");
    target_opencv_function.push_back("ellipse2Poly");
    target_opencv_function.push_back("EMD");
    target_opencv_function.push_back("equalizeHist");
    target_opencv_function.push_back("erode");
    target_opencv_function.push_back("error");
    target_opencv_function.push_back("estimateAffine3D");
    target_opencv_function.push_back("estimateRigidTransform");
    target_opencv_function.push_back("evaluateFeatureDetector");
    target_opencv_function.push_back("evaluateGenericDescriptorMatcher");
    target_opencv_function.push_back("exp");
    target_opencv_function.push_back("extractChannel");
    target_opencv_function.push_back("extractImageCOI");
    target_opencv_function.push_back("FAST");
    target_opencv_function.push_back("fast_abs");
    target_opencv_function.push_back("fastAtan2");
    target_opencv_function.push_back("fastFree");
    target_opencv_function.push_back("fastMalloc");
    target_opencv_function.push_back("fastNlMeansDenoising");
    target_opencv_function.push_back("fastNlMeansDenoisingColored");
    target_opencv_function.push_back("fastNlMeansDenoisingColoredMulti");
    target_opencv_function.push_back("fastNlMeansDenoisingMulti");
    target_opencv_function.push_back("FASTX");
    target_opencv_function.push_back("fillConvexPoly");
    target_opencv_function.push_back("fillConvexPoly");
    target_opencv_function.push_back("fillPoly");
    target_opencv_function.push_back("filter2D");
    target_opencv_function.push_back("filterSpeckles");
    target_opencv_function.push_back("find4QuadCornerSubpix");
    target_opencv_function.push_back("findChessboardCorners");
    target_opencv_function.push_back("findCirclesGrid");
    target_opencv_function.push_back("findCirclesGridDefault");
    target_opencv_function.push_back("findHomography");
    target_opencv_function.push_back("findNonZero");
    target_opencv_function.push_back("fitEllipse");
    target_opencv_function.push_back("fitLine");
    target_opencv_function.push_back("flip");
    target_opencv_function.push_back("floodFill");
    target_opencv_function.push_back("fontQt");
    target_opencv_function.push_back("format");
    target_opencv_function.push_back("fromUtf16");
    target_opencv_function.push_back("GaussianBlur");
    target_opencv_function.push_back("gemm");
    target_opencv_function.push_back("generateColors");
    target_opencv_function.push_back("getAffineTransform");
    target_opencv_function.push_back("getBuildInformation");
    target_opencv_function.push_back("getColumnSumFilter");
    target_opencv_function.push_back("getConvertElem");
    target_opencv_function.push_back("getConvertFunc");
    target_opencv_function.push_back("getConvertScaleElem");
    target_opencv_function.push_back("getConvertScaleFunc");
    target_opencv_function.push_back("getCopyMaskFunc");
    target_opencv_function.push_back("getCPUTickCount");
    target_opencv_function.push_back("getData");
    target_opencv_function.push_back("getDefaultNewCameraMatrix");
    target_opencv_function.push_back("getDerivKernels");
    target_opencv_function.push_back("getGaborKernel");
    target_opencv_function.push_back("getGaussianKernel");
    target_opencv_function.push_back("getKernelType");
    target_opencv_function.push_back("getLinearColumnFilter");
    target_opencv_function.push_back("getLinearFilter");
    target_opencv_function.push_back("getLinearRowFilter");
    target_opencv_function.push_back("getMorphologyColumnFilter");
    target_opencv_function.push_back("getMorphologyFilter");
    target_opencv_function.push_back("getMorphologyRowFilter");
    target_opencv_function.push_back("getNearestPoint");
    target_opencv_function.push_back("getNumberOfCPUs");
    target_opencv_function.push_back("getNumThreads");
    target_opencv_function.push_back("getOptimalDFTSize");
    target_opencv_function.push_back("getOptimalNewCameraMatrix");
    target_opencv_function.push_back("getPerspectiveTransform");
    target_opencv_function.push_back("getRecall");
    target_opencv_function.push_back("getRectSubPix");
    target_opencv_function.push_back("getRotationMatrix2D");
    target_opencv_function.push_back("getRowSumFilter");
    target_opencv_function.push_back("getSeqElem");
    target_opencv_function.push_back("getStructuringElement");
    target_opencv_function.push_back("getTextSize");
    target_opencv_function.push_back("getThreadNum");
    target_opencv_function.push_back("getTickCount");
    target_opencv_function.push_back("getTickFrequency");
    target_opencv_function.push_back("getTrackbarPos");
    target_opencv_function.push_back("getValidDisparityROI");
    target_opencv_function.push_back("getWindowProperty");
    target_opencv_function.push_back("glob");
    target_opencv_function.push_back("goodFeaturesToTrack");
    target_opencv_function.push_back("grabCut");
    target_opencv_function.push_back("groupRectangles");
    target_opencv_function.push_back("groupRectangles_meanshift");
    target_opencv_function.push_back("hconcat");
    target_opencv_function.push_back("HoughCircles");
    target_opencv_function.push_back("HoughLines");
    target_opencv_function.push_back("HoughLinesP");
    target_opencv_function.push_back("HuMoments");
    target_opencv_function.push_back("idct");
    target_opencv_function.push_back("idft");
    target_opencv_function.push_back("imdecode");
    target_opencv_function.push_back("imencode");
    target_opencv_function.push_back("imread");
    target_opencv_function.push_back("imshow");
    target_opencv_function.push_back("imwrite");
    target_opencv_function.push_back("initCameraMatrix2D");
    target_opencv_function.push_back("initModule_contrib");
    target_opencv_function.push_back("initModule_features2d");
    target_opencv_function.push_back("initModule_ml");
    target_opencv_function.push_back("initModule_nonfree");
    target_opencv_function.push_back("initModule_video");
    target_opencv_function.push_back("initUndistortRectifyMap");
    target_opencv_function.push_back("initWideAngleProjMap");
    target_opencv_function.push_back("inpaint");
    target_opencv_function.push_back("inRange");
    target_opencv_function.push_back("insertChannel");
    target_opencv_function.push_back("insertImageCOI");
    target_opencv_function.push_back("integral");
    target_opencv_function.push_back("intersectConvexConvex");
    target_opencv_function.push_back("invert");
    target_opencv_function.push_back("invertAffineTransform");
    target_opencv_function.push_back("isContourConvex");
    target_opencv_function.push_back("kmeans");
    target_opencv_function.push_back("Laplacian");
    target_opencv_function.push_back("line");
    target_opencv_function.push_back("loadWindowParameters");
    target_opencv_function.push_back("log");
    target_opencv_function.push_back("LU");
    target_opencv_function.push_back("LUT");
    target_opencv_function.push_back("magnitude");
    target_opencv_function.push_back("Mahalanobis");
    target_opencv_function.push_back("Mahalonobis");
    target_opencv_function.push_back("makePtr");
    target_opencv_function.push_back("Mat");
    target_opencv_function.push_back("matchShapes");
    target_opencv_function.push_back("matchTemplate");
    target_opencv_function.push_back("matMulDeriv");
    target_opencv_function.push_back("max");
    target_opencv_function.push_back("mean");
    target_opencv_function.push_back("meanShift");
    target_opencv_function.push_back("meanStdDev");
    target_opencv_function.push_back("medianBlur");
    target_opencv_function.push_back("merge");
    target_opencv_function.push_back("min");
    target_opencv_function.push_back("minAreaRect");
    target_opencv_function.push_back("minEnclosingCircle");
    target_opencv_function.push_back("minMaxIdx");
    target_opencv_function.push_back("minMaxLoc");
    target_opencv_function.push_back("mixChannels");
    target_opencv_function.push_back("moments");
    target_opencv_function.push_back("morphologyEx");
    target_opencv_function.push_back("moveWindow");
    target_opencv_function.push_back("mulSpectrums");
    target_opencv_function.push_back("multiply");
    target_opencv_function.push_back("mulTransposed");
    target_opencv_function.push_back("namedWindow");
    target_opencv_function.push_back("noArray");
    target_opencv_function.push_back("norm");
    target_opencv_function.push_back("normalize");
    target_opencv_function.push_back("normHamming");
    target_opencv_function.push_back("normL1");
    target_opencv_function.push_back("normL1_");
    target_opencv_function.push_back("normL2Sqr");
    target_opencv_function.push_back("normL2Sqr_");
    target_opencv_function.push_back("operator");
    target_opencv_function.push_back("parallel_for_");
    target_opencv_function.push_back("partition");
    target_opencv_function.push_back("patchNaNs");
    target_opencv_function.push_back("PCABackProject");
    target_opencv_function.push_back("PCACompute");
    target_opencv_function.push_back("PCAComputeVar");
    target_opencv_function.push_back("PCAProject");
    target_opencv_function.push_back("perspectiveTransform");
    target_opencv_function.push_back("phase");
    target_opencv_function.push_back("phaseCorrelate");
    target_opencv_function.push_back("phaseCorrelateRes");
    target_opencv_function.push_back("Point");
    target_opencv_function.push_back("pointCloudShow");
    target_opencv_function.push_back("pointPolygonTest");
    target_opencv_function.push_back("polarToCart");
    target_opencv_function.push_back("polyfit");
    target_opencv_function.push_back("polylines");
    target_opencv_function.push_back("pow");
    target_opencv_function.push_back("preCornerDetect");
    target_opencv_function.push_back("process");
    target_opencv_function.push_back("projectPoints");
    target_opencv_function.push_back("PSNR");
    target_opencv_function.push_back("putText");
    target_opencv_function.push_back("pyrDown");
    target_opencv_function.push_back("pyrMeanShiftFiltering");
    target_opencv_function.push_back("pyrUp");
    target_opencv_function.push_back("randn");
    target_opencv_function.push_back("randShuffle");
    target_opencv_function.push_back("randu");
    target_opencv_function.push_back("read");
    target_opencv_function.push_back("Rect");
    target_opencv_function.push_back("rectangle");
    target_opencv_function.push_back("rectify3Collinear");
    target_opencv_function.push_back("redirectError");
    target_opencv_function.push_back("reduce");
    target_opencv_function.push_back("remap");
    target_opencv_function.push_back("render");
    target_opencv_function.push_back("repeat");
    target_opencv_function.push_back("reprojectImageTo3D");
    target_opencv_function.push_back("resize");
    target_opencv_function.push_back("resizeWindow");
    target_opencv_function.push_back("RGBDOdometry");
    target_opencv_function.push_back("Rodrigues");
    target_opencv_function.push_back("RQDecomp3x3");
    target_opencv_function.push_back("saturate_cast");
    target_opencv_function.push_back("saveWindowParameters");
    target_opencv_function.push_back("scalar");
    target_opencv_function.push_back("scalarToRawData");
    target_opencv_function.push_back("scaleAdd");
    target_opencv_function.push_back("Scharr");
    target_opencv_function.push_back("segmentMotion");
    target_opencv_function.push_back("sepFilter2D");
    target_opencv_function.push_back("seqInsertSlice");
    target_opencv_function.push_back("seqPop");
    target_opencv_function.push_back("seqPopFront");
    target_opencv_function.push_back("seqPopMulti");
    target_opencv_function.push_back("seqPush");
    target_opencv_function.push_back("seqPushFront");
    target_opencv_function.push_back("seqRemove");
    target_opencv_function.push_back("seqRemoveSlice");
    target_opencv_function.push_back("setBreakOnError");
    target_opencv_function.push_back("setIdentity");
    target_opencv_function.push_back("setMouseCallback");
    target_opencv_function.push_back("setNumThreads");
    target_opencv_function.push_back("setOpenGlContext");
    target_opencv_function.push_back("setOpenGlDrawCallback");
    target_opencv_function.push_back("setRNGSeed");
    target_opencv_function.push_back("setTrackbarPos");
    target_opencv_function.push_back("setUseOptimized");
    target_opencv_function.push_back("setWindowProperty");
    target_opencv_function.push_back("Sobel");
    target_opencv_function.push_back("solve");
    target_opencv_function.push_back("solveCubic");
    target_opencv_function.push_back("solvePnP");
    target_opencv_function.push_back("solvePnPRansac");
    target_opencv_function.push_back("solvePoly");
    target_opencv_function.push_back("sort");
    target_opencv_function.push_back("sortIdx");
    target_opencv_function.push_back("split");
    target_opencv_function.push_back("sqrt");
    target_opencv_function.push_back("startLoop");
    target_opencv_function.push_back("startWindowThread");
    target_opencv_function.push_back("stereoCalibrate");
    target_opencv_function.push_back("stereoRectify");
    target_opencv_function.push_back("stereoRectifyUncalibrated");
    target_opencv_function.push_back("stopLoop");
    target_opencv_function.push_back("subspaceProject");
    target_opencv_function.push_back("subspaceReconstruct");
    target_opencv_function.push_back("subtract");
    target_opencv_function.push_back("SVBackSubst");
    target_opencv_function.push_back("SVDecomp");
    target_opencv_function.push_back("swap");
    target_opencv_function.push_back("tempfile");
    target_opencv_function.push_back("theRNG");
    target_opencv_function.push_back("threshold");
    target_opencv_function.push_back("toUtf16");
    target_opencv_function.push_back("trace");
    target_opencv_function.push_back("transform");
    target_opencv_function.push_back("transpose");
    target_opencv_function.push_back("triangulatePoints");
    target_opencv_function.push_back("undistort");
    target_opencv_function.push_back("undistortPoints");
    target_opencv_function.push_back("updateMotionHistory");
    target_opencv_function.push_back("updateWindow");
    target_opencv_function.push_back("useOptimized");
    target_opencv_function.push_back("validateDisparity");
    target_opencv_function.push_back("vconcat");
    target_opencv_function.push_back("waitKey");
    target_opencv_function.push_back("warpAffine");
    target_opencv_function.push_back("warpPerspective");
    target_opencv_function.push_back("watershed");
    target_opencv_function.push_back("windowedMatchingMask");
    target_opencv_function.push_back("write");
    target_opencv_function.push_back("writeScalar");


    //bwlow are constructors
    target_opencv_function.push_back("Affine3");
    target_opencv_function.push_back("Algorithm");
    target_opencv_function.push_back("AlgorithmInfo");
    target_opencv_function.push_back("Allocator");
    target_opencv_function.push_back("AutoBuffer");
    target_opencv_function.push_back("AutoLock");
    target_opencv_function.push_back("BackgroundSubtractor");
    target_opencv_function.push_back("BackgroundSubtractorGMG");
    target_opencv_function.push_back("BackgroundSubtractorMOG");
    target_opencv_function.push_back("BackgroundSubtractorMOG2");
    target_opencv_function.push_back("BaseColumnFilter");
    target_opencv_function.push_back("BaseFilter");
    target_opencv_function.push_back("BaseRowFilter");
    target_opencv_function.push_back("BFMatcher");
    target_opencv_function.push_back("BlockedRange");
    target_opencv_function.push_back("BOWImgDescriptorExtractor");
    target_opencv_function.push_back("BOWKMeansTrainer");
    target_opencv_function.push_back("BOWTrainer");
    target_opencv_function.push_back("BriefDescriptorExtractor");
    target_opencv_function.push_back("BRISK");
    target_opencv_function.push_back("BruteForceMatcher");
    target_opencv_function.push_back("CalonderDescriptorExtractor");
    target_opencv_function.push_back("CascadeClassifier");
    target_opencv_function.push_back("CLAHE");
    target_opencv_function.push_back("CommandLineParser");
    target_opencv_function.push_back("Complex");
    target_opencv_function.push_back("CompressedRectilinearPortraitWarper");
    target_opencv_function.push_back("CompressedRectilinearWarper");
    target_opencv_function.push_back("CvAffinePose");
    target_opencv_function.push_back("CvFeatureTracker");
    target_opencv_function.push_back("CvHybridTracker");
    target_opencv_function.push_back("CvMeanShiftTracker");
    target_opencv_function.push_back("CylindricalWarper");
    target_opencv_function.push_back("CylindricalWarperGpu");
    target_opencv_function.push_back("DataDepth");
    target_opencv_function.push_back("DataType");
    target_opencv_function.push_back("DenseFeatureDetector");
    target_opencv_function.push_back("DenseOpticalFlow");
    target_opencv_function.push_back("DescriptorExtractor");
    target_opencv_function.push_back("DescriptorMatcher");
    target_opencv_function.push_back("Directory");
    target_opencv_function.push_back("DynamicAdaptedFeatureDetector");
    target_opencv_function.push_back("EM");
    target_opencv_function.push_back("Exception");
    target_opencv_function.push_back("FaceRecognizer");
    target_opencv_function.push_back("FastAdjuster");
    target_opencv_function.push_back("FastFeatureDetector");
    target_opencv_function.push_back("Feature2D");
    target_opencv_function.push_back("FeatureDetector");
    target_opencv_function.push_back("FeatureEvaluator");
    target_opencv_function.push_back("FernClassifier");
    target_opencv_function.push_back("FernDescriptorMatcher");
    target_opencv_function.push_back("FileNode");
    target_opencv_function.push_back("FileNodeIterator");
    target_opencv_function.push_back("FileStorage");
    target_opencv_function.push_back("FilterEngine");
    target_opencv_function.push_back("FisheyeWarper");
    target_opencv_function.push_back("FlannBasedMatcher");
    target_opencv_function.push_back("Formatter");
    target_opencv_function.push_back("FREAK");
    target_opencv_function.push_back("GeneralizedHough");
    target_opencv_function.push_back("GenericDescriptorMatcher");
    target_opencv_function.push_back("GFTTDetector");
    target_opencv_function.push_back("GlArrays");
    target_opencv_function.push_back("GlBuffer");
    target_opencv_function.push_back("GlCamera");
    target_opencv_function.push_back("GlFont");
    target_opencv_function.push_back("GlTexture");
    target_opencv_function.push_back("GreaterEq");
    target_opencv_function.push_back("GreaterEqIdx");
    target_opencv_function.push_back("GridAdaptedFeatureDetector");
    target_opencv_function.push_back("KalmanFilter");
    target_opencv_function.push_back("KDTree");
    target_opencv_function.push_back("KeyPoint");
    target_opencv_function.push_back("KeyPointsFilter");
    target_opencv_function.push_back("LatentSvmDetector");
    target_opencv_function.push_back("LDA");
    target_opencv_function.push_back("LDetector");
    target_opencv_function.push_back("LessThan");
    target_opencv_function.push_back("LessThanIdx");
    target_opencv_function.push_back("LevMarqSparse");
    target_opencv_function.push_back("LineIterator");
    target_opencv_function.push_back("LogPolar_Adjacent");
    target_opencv_function.push_back("LogPolar_Interp");
    target_opencv_function.push_back("LogPolar_Overlapping");
    target_opencv_function.push_back("Mat");
    target_opencv_function.push_back("Mat_");
    target_opencv_function.push_back("MatAllocator");
    target_opencv_function.push_back("MatCommaInitializer_");
    target_opencv_function.push_back("MatConstIterator");
    target_opencv_function.push_back("MatConstIterator_");
    target_opencv_function.push_back("MatExpr");
    target_opencv_function.push_back("MatIterator_");
    target_opencv_function.push_back("MatOp");
    target_opencv_function.push_back("MatOp_Iter_");
    target_opencv_function.push_back("Matx");
    target_opencv_function.push_back("MatxCommaInitializer");
    target_opencv_function.push_back("MercatorWarper");
    target_opencv_function.push_back("Mesh3D");
    target_opencv_function.push_back("Moments");
    target_opencv_function.push_back("MSER");
    target_opencv_function.push_back("Mutex");
    target_opencv_function.push_back("NAryMatIterator");
    target_opencv_function.push_back("Octree");
    target_opencv_function.push_back("OneWayDescriptor");
    target_opencv_function.push_back("OneWayDescriptorBase");
    target_opencv_function.push_back("OneWayDescriptorMatcher");
    target_opencv_function.push_back("OneWayDescriptorObject");
    target_opencv_function.push_back("OpponentColorDescriptorExtractor");
    target_opencv_function.push_back("ORB");
    target_opencv_function.push_back("PaniniPortraitWarper");
    target_opencv_function.push_back("PaniniWarper");
    target_opencv_function.push_back("ParallelLoopBody");
    target_opencv_function.push_back("PatchGenerator");
    target_opencv_function.push_back("PCA");
    target_opencv_function.push_back("PlanarObjectDetector");
    target_opencv_function.push_back("PlaneWarper");
    target_opencv_function.push_back("PlaneWarperGpu");
    target_opencv_function.push_back("Point3_");
    target_opencv_function.push_back("Point_ ");
    target_opencv_function.push_back("Ptr");
    target_opencv_function.push_back("PyramidAdaptedFeatureDetector");
    target_opencv_function.push_back("RandomizedTree");
    target_opencv_function.push_back("Range");
    target_opencv_function.push_back("Rect_");
    target_opencv_function.push_back("Retina");
    target_opencv_function.push_back("RNG");
    target_opencv_function.push_back("RNG_MT19937");
    target_opencv_function.push_back("RotatedRect");
    target_opencv_function.push_back("RTreeClassifier");
    target_opencv_function.push_back("Scalar_");
    target_opencv_function.push_back("SelfSimDescriptor"); 
    target_opencv_function.push_back("Seq");
    target_opencv_function.push_back("SeqIterator");
    target_opencv_function.push_back("SIFT");
    target_opencv_function.push_back("SimilarRects");
    target_opencv_function.push_back("SimpleBlobDetector");
    target_opencv_function.push_back("Size_");
    target_opencv_function.push_back("SparseMat");
    target_opencv_function.push_back("SparseMat_");
    target_opencv_function.push_back("SparseMatConstIterator");
    target_opencv_function.push_back("SparseMatConstIterator_");
    target_opencv_function.push_back("SparseMatIterator");
    target_opencv_function.push_back("SparseMatIterator_");
    target_opencv_function.push_back("SphericalWarper");
    target_opencv_function.push_back("SphericalWarperGpu");
    target_opencv_function.push_back("SpinImageModel");
    target_opencv_function.push_back("Split");
    target_opencv_function.push_back("StarAdjuster");
    target_opencv_function.push_back("StarDetector");
    target_opencv_function.push_back("StereoBM");
    target_opencv_function.push_back("StereographicWarper");
    target_opencv_function.push_back("StereoSGBM");
    target_opencv_function.push_back("StereoVar");
    target_opencv_function.push_back("Stitcher");
    target_opencv_function.push_back("Subdiv2D");
    target_opencv_function.push_back("SURF");
    target_opencv_function.push_back("SurfAdjuster");
    target_opencv_function.push_back("SVD");
    target_opencv_function.push_back("TermCriteria");
    target_opencv_function.push_back("TickMeter");
    target_opencv_function.push_back("TLSData");
    target_opencv_function.push_back("TLSDataContainer");
    target_opencv_function.push_back("TransverseMercatorWarper");
    target_opencv_function.push_back("Vec");
    target_opencv_function.push_back("VecCommaInitializer");
    target_opencv_function.push_back("VecReaderProxy");
    target_opencv_function.push_back("Vector");
    target_opencv_function.push_back("VectorDescriptorMatcher");
    target_opencv_function.push_back("VecWriterProxy");
    target_opencv_function.push_back("VideoCapture");
    target_opencv_function.push_back("VideoWriter");
    target_opencv_function.push_back("WarperCreator");
    target_opencv_function.push_back("WImage");
    target_opencv_function.push_back("WImageBuffer");
    target_opencv_function.push_back("WImageBufferC");
    target_opencv_function.push_back("WImageC");
    target_opencv_function.push_back("WImageView");
    target_opencv_function.push_back("WImageViewC");
    target_opencv_function.push_back("WriteStructContext");
    int i=0;
    for(i=0;i<600;i++)
    {
      count_caffe[i]=0;
      count_opencv[i]=0;
    }
    int j=0;
    std::string tmpstring;
    //rearrange the sequence of caffe functions to make sure the longest are compared firstly
    for(i=0;i<88;i++)
    {
      for(j=i+1;j<88;j++)
      {
        if(target_caffe_function[i].length()<target_caffe_function[j].length())
        {
            tmpstring=target_caffe_function[i];
            target_caffe_function[i]=target_caffe_function[j];
            target_caffe_function[j]=tmpstring;
        }
      }
    }

    for(i=88;i<102;i++)
    {
      for(j=i+1;j<102;j++)
      {
        if(target_caffe_function[i].length()<target_caffe_function[j].length())
        {
            tmpstring=target_caffe_function[i];
            target_caffe_function[i]=target_caffe_function[j];
            target_caffe_function[j]=tmpstring;
        }
      }
    }
    //rearrange the sequence of opencv functions to make sure the longest are compared firstly
    for(i=0;i<385;i++)
    {
      for(j=i+1;j<385;j++)
      {
        if(target_opencv_function[i].length()<target_opencv_function[j].length())
        {
            tmpstring=target_opencv_function[i];
            target_opencv_function[i]=target_opencv_function[j];
            target_opencv_function[j]=tmpstring;
        }
      }
    }

    //rearrange the sequence of opencv constructors to make sure the longest are compared firstly
    for(i=385;i<565;i++)
    {
      for(j=i+1;j<565;j++)
      {
        if(target_opencv_function[i].length()<target_opencv_function[j].length())
        {
            tmpstring=target_opencv_function[i];
            target_opencv_function[i]=target_opencv_function[j];
            target_opencv_function[j]=tmpstring;
        }
      }
    }
    std::size_t found1;
    std::size_t found2;
    std::size_t found3;

    std::string funcname;
    std::string demangled;
    for (auto F=M.getFunctionList().begin(), FE=M.getFunctionList().end(); F!=FE;F++)
    {
        i=0;
        funcname=F->getName().str();
        demangled=itaniumDemangle(funcname);
        outs()<<demangled<<"\n";
        j=0;
        for(i=0;i<102;i++)
        {
          found1=funcname.find(target_caffe_function[i]);
          found2=funcname.find("caffe");
          //outs()<<funcname<<"\n";
          //outs()<<target_function[i]<<"\n";
          if(found1!=std::string::npos && found2!=std::string::npos)
          {
            outs()<<"Function Found "<<target_caffe_function[i]<<"\n";
            outs()<<"raw data is "<<funcname<<"\n";
            outs()<<" \n";
            count_caffe[i]=count_caffe[i]+1;
            break;
          }
          // if(found1==std::string::npos && found2!=std::string::npos)
          // {
          //   for(j=0;j<14;j++)
          //   {
          //     found3=funcname.find(target_caffe_function[j]);
          //     if(found3!=std::string::npos)
          //     {
          //       outs()<<"Function Found "<<target_caffe_function[j]<<"\n";
          //       outs()<<"raw data is "<<funcname<<"\n";
          //       outs()<<" \n";
          //       count_caffe[j]=count_caffe[j]+1;
          //       break;
          //     }
          //   }
          // }
        }

        for(i=0;i<565;i++)
        {
            found1=funcname.find(target_opencv_function[i]);
            found2=funcname.find("cv");
            //outs()<<funcname<<"\n";
            //outs()<<target_function[i]<<"\n";
            if(found1!=std::string::npos && found2!=std::string::npos)
            {
              outs()<<"Function Found "<<target_opencv_function[i]<<"\n";
              outs()<<"raw data is "<<funcname<<"\n";
              outs()<<" \n";
              count_opencv[i]=count_opencv[i]+1;
              break;
            }
            // if(found1==std::string::npos && found2!=std::string::npos)
            // {
            //   for(j=385;j<565;j++)
            //   {
            //     found3=funcname.find(target_opencv_function[j]);
            //     if(found3!=std::string::npos)
            //     {
            //       outs()<<"Function Found "<<target_opencv_function[j]<<"\n";
            //       outs()<<"raw data is "<<funcname<<"\n";
            //       outs()<<" \n";
            //       count_opencv[j]=count_opencv[j]+1;
            //       break;
            //     }
            //   }
              
            // }
        }




        //outs()<< "Enter function: "<<funcname<<'\n';
        for(auto BB=F->begin(),BE=F->end();BB!=BE;BB++)
        {
            for(auto I=BB->begin(), IE=BB->end();I!=IE;I++)
            {
              // if (isa<CallInst>(I)) 
              // {
              //   StringRef name = cast<CallInst>(I).getCalledFunction().getName();
              //   outs()<<name<<"\n";
              // }
                CallInst *cs= dyn_cast<CallInst>(&*I);
                if(cs)
                {
                    Function* callee=cs->getCalledFunction();

                    if(!callee)
                    {
                        continue;
                    }

                    std::string callee_name=callee->getName().str();
                    for(i=0;i<7;i++)
                    {
                        found1=callee_name.find(target_caffe_function[i]);
                        if(found1!=std::string::npos)
                        {
                            outs()<<"Call Function Found "<<target_caffe_function[i]<<"\n";
                            outs()<<"raw data is "<<callee_name<<"\n";
                            outs()<<" \n";
                        }
                    }
                    //outs()<<callee_name<<"\n";
                    // CallSite css(&*I);
                    // LoadInst* load=dyn_cast<LoadInst>(cs->getOperand(0));
                    // if(!load)
                    // {
                    //   continue;
                    // }
                    // Value* arg1=load->getOperand(0);
                    // outs()<<arg1<<'\n';
                    // outs()<<*arg1<<'\n';
                }
            }
        }
    }
            for(i=0;i<102;i++)
        {
          if(count_caffe[i]!=0)
          {
            outs()<<"function: "<<"caffe::"<<target_caffe_function[i]<<" "<<count_caffe[i]<<"\n";
          }
          
        }

        for(i=0;i<565;i++)
        {
          if(count_opencv[i]!=0)
          {
            outs()<<"function: "<<"cv::"<<target_opencv_function[i]<<" "<<count_opencv[i]<<"\n";
          }
          
        }

    for (Module::const_global_iterator GI = M.global_begin(),GE = M.global_end();GI != GE; ++GI) 
    {
      //outs() << "Found global named \"" << GI->getName()<< "\": type = " << LLVMTypeAsString(GI->getType()) << "\n";
    }
    return false;
  }

  // The address of this member is used to uniquely identify the class. This is
  // used by LLVM's own RTTI mechanism.
  static char ID;
};

char GVNames::ID = 0;

int main(int argc, char **argv) {
  if (argc < 2) {
    errs() << "Usage: " << argv[0] << " <IR file>\n";
    return 1;
  }

  // Parse the input LLVM IR file into a module.
  SMDiagnostic Err;
  LLVMContext Context;
  std::unique_ptr<Module> Mod(parseIRFile(argv[1], Err, Context));
  if (!Mod) {
    Err.print(argv[0], errs());
    return 1;
  }

  // Create a pass manager and fill it with the passes we want to run.
  legacy::PassManager PM;
  PM.add(new GVNames());
  PM.run(*Mod);

  return 0;
}

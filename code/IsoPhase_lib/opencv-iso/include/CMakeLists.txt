file(GLOB old_hdrs "opencv/*.h*")
file(GLOB instru_hdrs "instrumentation/*.h*")
install(FILES ${old_hdrs}
    DESTINATION ${OPENCV_INCLUDE_INSTALL_PATH}/opencv
    COMPONENT dev)
install(FILES "opencv2/opencv.hpp"
    DESTINATION ${OPENCV_INCLUDE_INSTALL_PATH}/opencv2
    COMPONENT dev)


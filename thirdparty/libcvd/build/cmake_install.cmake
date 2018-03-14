# Install script for directory: /home/duan/ROVGS/ROVGS/thirdparty/libcvd

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/libCVD.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/argb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/bgrx.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/bresenham.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/byte.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/camera.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/canny.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourmap.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourspace.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourspacebuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourspaces.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourspace_convert.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/colourspace_frame.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/connected_components.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/convolution.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/deinterlacebuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/deinterlaceframe.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/diskbuffer2.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/diskbuffer2_frame.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/distance_transform.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/documentation.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/draw.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/esm.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/exceptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/fast_corner.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/gles1_helpers.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/glwindow.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/gl_helpers.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/haar.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/harris_corner.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/helpers.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image_convert.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image_convert_fwd.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image_interpolate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image_io.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/image_ref.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/integral_image.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/interpolate.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/la.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/localvideobuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/localvideoframe.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/morphology.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/nonmax_suppression.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/opencv.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/readaheadvideobuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/rgb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/rgb8.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/rgba.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/serverpushjpegbuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/serverpushjpegframe.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/timeddiskbuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/timer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/utility.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/vector_image_ref.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videobuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videobufferflags.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videobufferwithdata.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videofilebuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videofilebuffer_frame.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videoframe.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videosource.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/vision.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/vision_exceptions.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/yc.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/video" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/video/skipbuffer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/builtin_components.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/concurrency_utilities.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/convert_pixel_types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/gles1_types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/gl_types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/image_ref_implementation.hh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/bmp.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/cvdimage.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/fits.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/jpeg.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/parameter.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/png.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/pnm_grok.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/save_postscript.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/text.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal/io" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/io/tiff.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/load_and_save.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/name_builtin_types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/name_CVD_rgb_types.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/pixel_operations.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/pixel_traits.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/rgb_components.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/scalar_convert.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd/internal" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/internal/win.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvd" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cvd/videodisplay.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/include/cvd")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/cmake/CVDConfig.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/tests/cmake_install.cmake")
  include("/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/progs/cmake_install.cmake")
  include("/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/examples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/duan/ROVGS/ROVGS/thirdparty/libcvd/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

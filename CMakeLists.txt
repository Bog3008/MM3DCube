cmake_minimum_required(VERSION 3.25)
project(MM3DCube)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)


add_executable(MM3DCube main.cpp)
target_link_libraries(MM3DCube
        ${OpenCV_LIBS})

CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(camerashow)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# MatOpencv camera
add_executable(camerashow ${PROJECT_SOURCE_DIR}/src/MatOpencv.cpp)

target_link_libraries(camerashow PRIVATE ${OpenCV_LIBS})
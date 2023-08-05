CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(opencvBasis)

find_package(OpenCV REQUIRED)
file(GLOB_RECURSE CV_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

message(STATUS "prj source: ${PROJECT_SOURCE_DIR}")
message(STATUS "runtime output dir:-> ${CMAKE_BINARY_DIR}")

foreach(CV_SOURCE ${CV_SOURCES})
    get_filename_component(cv_filename ${CV_SOURCE} NAME)
    string(REPLACE ".cpp" "" cv_name ${cv_filename})
        message("detect cpp: ${cv_name}")
    # Add the test target separately and as part of "make check-tests".
    add_executable(${cv_name} EXCLUDE_FROM_ALL ${CV_SOURCE})
    # add_executable(${cv_name} ${CV_SOURCE})
    # Set test target properties and dependencies.
    set_target_properties(${cv_name}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PROJECT_NAME}"
            COMMAND ${cv_name}
            )
    target_link_libraries(${cv_name} PRIVATE ${OpenCV_LIBS})
endforeach()

#################################
##      在这里添加你自己需要的库    ##
#################################

# # MatOpencv camera
# add_executable(camerashow ${PROJECT_SOURCE_DIR}/src/MatOpencv.cpp)


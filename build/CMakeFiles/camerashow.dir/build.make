# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liam/Documents/codes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liam/Documents/codes/build

# Include any dependencies generated for this target.
include CMakeFiles/camerashow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/camerashow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/camerashow.dir/flags.make

CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o: CMakeFiles/camerashow.dir/flags.make
CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o: ../src/MatOpencv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liam/Documents/codes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o -c /home/liam/Documents/codes/src/MatOpencv.cpp

CMakeFiles/camerashow.dir/src/MatOpencv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camerashow.dir/src/MatOpencv.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liam/Documents/codes/src/MatOpencv.cpp > CMakeFiles/camerashow.dir/src/MatOpencv.cpp.i

CMakeFiles/camerashow.dir/src/MatOpencv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camerashow.dir/src/MatOpencv.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liam/Documents/codes/src/MatOpencv.cpp -o CMakeFiles/camerashow.dir/src/MatOpencv.cpp.s

# Object files for target camerashow
camerashow_OBJECTS = \
"CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o"

# External object files for target camerashow
camerashow_EXTERNAL_OBJECTS =

camerashow: CMakeFiles/camerashow.dir/src/MatOpencv.cpp.o
camerashow: CMakeFiles/camerashow.dir/build.make
camerashow: /usr/local/lib/libopencv_gapi.so.4.5.1
camerashow: /usr/local/lib/libopencv_stitching.so.4.5.1
camerashow: /usr/local/lib/libopencv_alphamat.so.4.5.1
camerashow: /usr/local/lib/libopencv_aruco.so.4.5.1
camerashow: /usr/local/lib/libopencv_bgsegm.so.4.5.1
camerashow: /usr/local/lib/libopencv_bioinspired.so.4.5.1
camerashow: /usr/local/lib/libopencv_ccalib.so.4.5.1
camerashow: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.1
camerashow: /usr/local/lib/libopencv_dnn_superres.so.4.5.1
camerashow: /usr/local/lib/libopencv_dpm.so.4.5.1
camerashow: /usr/local/lib/libopencv_face.so.4.5.1
camerashow: /usr/local/lib/libopencv_freetype.so.4.5.1
camerashow: /usr/local/lib/libopencv_fuzzy.so.4.5.1
camerashow: /usr/local/lib/libopencv_hdf.so.4.5.1
camerashow: /usr/local/lib/libopencv_hfs.so.4.5.1
camerashow: /usr/local/lib/libopencv_img_hash.so.4.5.1
camerashow: /usr/local/lib/libopencv_intensity_transform.so.4.5.1
camerashow: /usr/local/lib/libopencv_line_descriptor.so.4.5.1
camerashow: /usr/local/lib/libopencv_mcc.so.4.5.1
camerashow: /usr/local/lib/libopencv_quality.so.4.5.1
camerashow: /usr/local/lib/libopencv_rapid.so.4.5.1
camerashow: /usr/local/lib/libopencv_reg.so.4.5.1
camerashow: /usr/local/lib/libopencv_rgbd.so.4.5.1
camerashow: /usr/local/lib/libopencv_saliency.so.4.5.1
camerashow: /usr/local/lib/libopencv_stereo.so.4.5.1
camerashow: /usr/local/lib/libopencv_structured_light.so.4.5.1
camerashow: /usr/local/lib/libopencv_superres.so.4.5.1
camerashow: /usr/local/lib/libopencv_surface_matching.so.4.5.1
camerashow: /usr/local/lib/libopencv_tracking.so.4.5.1
camerashow: /usr/local/lib/libopencv_videostab.so.4.5.1
camerashow: /usr/local/lib/libopencv_viz.so.4.5.1
camerashow: /usr/local/lib/libopencv_xfeatures2d.so.4.5.1
camerashow: /usr/local/lib/libopencv_xobjdetect.so.4.5.1
camerashow: /usr/local/lib/libopencv_xphoto.so.4.5.1
camerashow: /usr/local/lib/libopencv_shape.so.4.5.1
camerashow: /usr/local/lib/libopencv_highgui.so.4.5.1
camerashow: /usr/local/lib/libopencv_datasets.so.4.5.1
camerashow: /usr/local/lib/libopencv_plot.so.4.5.1
camerashow: /usr/local/lib/libopencv_text.so.4.5.1
camerashow: /usr/local/lib/libopencv_ml.so.4.5.1
camerashow: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.1
camerashow: /usr/local/lib/libopencv_optflow.so.4.5.1
camerashow: /usr/local/lib/libopencv_ximgproc.so.4.5.1
camerashow: /usr/local/lib/libopencv_video.so.4.5.1
camerashow: /usr/local/lib/libopencv_dnn.so.4.5.1
camerashow: /usr/local/lib/libopencv_videoio.so.4.5.1
camerashow: /usr/local/lib/libopencv_imgcodecs.so.4.5.1
camerashow: /usr/local/lib/libopencv_objdetect.so.4.5.1
camerashow: /usr/local/lib/libopencv_calib3d.so.4.5.1
camerashow: /usr/local/lib/libopencv_features2d.so.4.5.1
camerashow: /usr/local/lib/libopencv_flann.so.4.5.1
camerashow: /usr/local/lib/libopencv_photo.so.4.5.1
camerashow: /usr/local/lib/libopencv_imgproc.so.4.5.1
camerashow: /usr/local/lib/libopencv_core.so.4.5.1
camerashow: CMakeFiles/camerashow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liam/Documents/codes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable camerashow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camerashow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/camerashow.dir/build: camerashow

.PHONY : CMakeFiles/camerashow.dir/build

CMakeFiles/camerashow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/camerashow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/camerashow.dir/clean

CMakeFiles/camerashow.dir/depend:
	cd /home/liam/Documents/codes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liam/Documents/codes /home/liam/Documents/codes /home/liam/Documents/codes/build /home/liam/Documents/codes/build /home/liam/Documents/codes/build/CMakeFiles/camerashow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/camerashow.dir/depend


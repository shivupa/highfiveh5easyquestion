################################################################################
# Set a requirement on the cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)
include(FetchContent)
################################################################################
# Set up the project and version info
project(test)
set(test_VERSION_MAJOR 0)
set(test_VERSION_MINOR 0)
set(test_VERSION_PATCH 0)
# set include paths
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_BINARY_DIR}/src)
################################################################################
# set required C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
################################################################################
# Set up build type
message(STATUS "Ready to build test")
################################################################################
# set up where to find Find*.cmake files and where to put the things we build
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${test_BINARY_DIR}/lib CACHE PATH "Single output directory for building all libraries.")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${test_BINARY_DIR}/bin CACHE PATH "Single output directory for building all executables.")
################################################################################
# set some flags that we can use cmake -Dflag={0,1} to trigger special things
set(FETCHCONTENT_QUIET ON)
################################################################################
# Find libraries
########################################
# OpenMP for parallelization
find_package(OpenMP REQUIRED)
########################################
# Eigen for matrix math
find_package(Eigen3 3.3 NO_MODULE)
if (NOT TARGET Eigen3::Eigen)
    FetchContent_Declare(
      Eigen
      GIT_REPOSITORY https://gitlab.com/shivupa/eigen.git
      GIT_TAG master
      GIT_SHALLOW TRUE
      GIT_PROGRESS TRUE)
    set(EIGEN_BUILD_DOC OFF)
    # note: To disable eigen tests,
    # you should put this code in a add_subdirectory to avoid to change
    # BUILD_TESTING for your own project too since variables are directory
    # scoped
    set(BUILD_TESTING OFF)
    set(EIGEN_BUILD_PKGCONFIG OFF)
    FetchContent_MakeAvailable(Eigen)
endif (NOT TARGET Eigen3::Eigen)
########################################
# HDF5
set(HIGHFIVE_USE_EIGEN ON CACHE INTERNAL "")  # Forces the value
set(HIGHFIVE_BUILD_DOCS OFF CACHE INTERNAL "")  # Forces the value
set(HIGHFIVE_EXAMPLES OFF CACHE INTERNAL "")  # Forces the value
FetchContent_Declare(
  HighFive
  GIT_REPOSITORY https://github.com/BlueBrain/HighFive.git
  GIT_TAG origin/master)
FetchContent_MakeAvailable(HighFive)
################################################################################
# this will do stuff in the src/CMakeLists.txt
add_subdirectory(src)
################################################################################

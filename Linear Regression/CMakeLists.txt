# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project("example" LANGUAGES CXX)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

#find eigen library
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# find python libraries
find_package(Python COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 2.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

# populate matplotlib repository
include(FetchContent)
FetchContent_Declare(
    matplotlib
    GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
    GIT_TAG        f23347fca25219d1c42cbb91608b5556814bf572
)
FetchContent_GetProperties(matplotlib)
if(NOT matplotlib_POPULATED)
    FetchContent_Populate(matplotlib)
endif()
include_directories(SYSTEM ${matplotlib_SOURCE_DIR})

# add executable
add_executable(least_square src/l_regression.cpp)
#add_executable(copy src/least_square.cpp)

# link python and numpy
target_link_libraries(least_square
    PRIVATE
        ${PYTHON_LIBRARIES}
        Python::NumPy
        Eigen3::Eigen
)




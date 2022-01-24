cmake_minimum_required (VERSION 3.5)
project (Liblab1)
set (CMAKE_CXX_STANDARD 11)

# set build type to DEBUG
set(CMAKE_BUILD_TYPE Debug)
# or to get an optimized build w/ debug symbols
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# add the library to the include file search path
include_directories ("${PROJECT_SOURCE_DIR}/liblab")

add_subdirectory (liblab) 

# set compiler and linker flags
add_compile_options("-Og")
#add_compile_options("-fsanitize=address")
#link_libraries("-fsanitize=address")

# add the executable and its dependency
add_executable(TestList ltest.cc)
target_link_libraries (TestList liblab)
add_executable(TestCoding test_coding.cc)
target_link_libraries (TestCoding liblab)
add_executable(Encode encode.cc)
target_link_libraries (Encode liblab)
add_executable(Decode decode.cc)
target_link_libraries (Decode liblab)
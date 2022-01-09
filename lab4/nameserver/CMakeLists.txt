cmake_minimum_required (VERSION 3.5)
project (NameServerBenchmark)
set (CMAKE_CXX_STANDARD 11)

set (CMAKE_BUILD_TYPE RelWithDebInfo)

set (IMPLS vns.cc mns.cc umns.cc hns.cc )

add_executable(nstest nstest.cc ${IMPLS})
# add_executable(nstime nstime.cc ${IMPLS})

include(ExternalProject)

ExternalProject_Add(google_benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.5.0
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external/tmp/benchmark
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external
  CMAKE_CACHE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    -DCMAKE_BUILD_TYPE:STRING=RELEASE
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES:STRING=ON
    -DBENCHMARK_ENABLE_TESTING:BOOL=OFF
  )

add_executable(nsbench nsbench.cc ${IMPLS})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/external/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/external/lib)
add_dependencies(nsbench google_benchmark)
# TODO: why does not the link_directories command above work?
#       temporary fix, add -L flag directly
target_link_libraries (nsbench -Lexternal/lib)
target_link_libraries (nsbench benchmark pthread)

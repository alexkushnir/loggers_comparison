set(PROJECT_NAME "glog-log-example")
project(${PROJECT_NAME})

file(GLOB glog_example_SRC
     "*.h"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${glog_example_SRC})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

include(FetchContent)

FetchContent_Declare(glog GIT_REPOSITORY https://github.com/google/glog.git GIT_TAG master)
set(WITH_GFLAGS OFF CACHE BOOL "Use gflags" FORCE)
set(WITH_GTEST OFF CACHE BOOL "Use Google Test" FORCE)
set(WITH_UNWIND none CACHE STRING "Use libunwind" FORCE)
FetchContent_MakeAvailable(glog)

FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/glog-src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/cxxopts-src/include")
target_link_libraries(${PROJECT_NAME} PRIVATE glog::glog)
add_dependencies(${PROJECT_NAME} glog)

target_link_options(${PROJECT_NAME} PRIVATE -lc++ -lc++abi)
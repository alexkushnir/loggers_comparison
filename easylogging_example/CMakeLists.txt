set(PROJECT_NAME "el-log-example")
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

include(FetchContent)

FetchContent_Declare(easylogging GIT_REPOSITORY https://github.com/abumq/easyloggingpp.git GIT_TAG v9.97.1)
FetchContent_MakeAvailable(easylogging)

FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

file(GLOB el_example_SRC
     "*.h"
     "*.cpp"
     "${CMAKE_BINARY}/_deps/easylogging-src/src/easylogging++.cc"
)

add_executable(${PROJECT_NAME} ${el_example_SRC})

set(test OFF CACHE BOOL "Build all tests" FORCE)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/easylogging-src/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/cxxopts-src/include")

target_link_options(${PROJECT_NAME} PRIVATE -lc++ -lc++abi -v)
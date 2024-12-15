set(PROJECT_NAME "el-log-example")
project(${PROJECT_NAME})

include(FetchContent)

FetchContent_Declare(easylogging GIT_REPOSITORY https://github.com/abumq/easyloggingpp.git GIT_TAG master)
FetchContent_MakeAvailable(easylogging)

FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

file(GLOB el_example_SRC
     "*.h"
     "*.cpp"
)

list(APPEND el_example_SRC "${CMAKE_BINARY_DIR}/_deps/easylogging-src/src/easylogging++.cc")

add_executable(${PROJECT_NAME} ${el_example_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/easylogging-src/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/cxxopts-src/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE -DELPP_STL_LOGGING)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DELPP_FEATURE_PERFORMANCE_TRACKING)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DELPP_PERFORMANCE_MICROSECONDS)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DELPP_FEATURE_CRASH_LOG)
target_link_options(${PROJECT_NAME} PRIVATE -lc++ -lc++abi)
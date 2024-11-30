set(PROJECT_NAME "glog-log-example")
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

include(FetchContent)

FetchContent_Declare(easylogging GIT_REPOSITORY https://github.com/abumq/easyloggingpp.git GIT_TAG master)
FetchContent_MakeAvailable(easylogging)

FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

# file(GLOB glog_example_SRC
#      "*.h"
#      "*.cpp"
# )

# add_executable(${PROJECT_NAME} ${glog_example_SRC})

# target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/glog-src")
# target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/cxxopts-src/include")
# target_link_libraries(${PROJECT_NAME} PRIVATE glog::glog)
# add_dependencies(${PROJECT_NAME} glog)

# target_link_options(${PROJECT_NAME} PRIVATE -lc++ -lc++abi)
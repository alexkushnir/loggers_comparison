set(PROJECT_NAME "spdlog-log-example")
project(${PROJECT_NAME})

file(GLOB spdlog_example_SRC
     "*.h"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${spdlog_example_SRC})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

include(FetchContent)

FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v2.x)
set(SPDLOG_BUILD_EXAMPLE  OFF CACHE BOOL "Build example" FORCE)
set(SPDLOG_BUILD_TESTS  OFF CACHE BOOL "Build tests" FORCE)
set(SPDLOG_USE_STD_FORMAT OFF CACHE BOOL "Build tests" FORCE)

 
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git GIT_TAG master)
FetchContent_MakeAvailable(cxxopts)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/spdlog-src/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/_deps/cxxopts-src/include")
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)
add_dependencies(${PROJECT_NAME} spdlog)
 
target_link_options(${PROJECT_NAME} PRIVATE -lc++ -lc++abi)
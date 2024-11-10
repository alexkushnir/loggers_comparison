Loggers comparison
==================
[![Examples build status](https://github.com/alexkushnir/loggers_comparison/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/alexkushnir/loggers_comparison/actions/workflows/cmake-single-platform.yml)

Preface
-------

This is a repository for a series of blog posts about logging libraries in C++ 
The first series post is located at <https://c-and-beyond.hashnode.dev/top-c-logging-libraries-compared-how-to-choose-the-best-one-part-0>

Prerequisites for building the repository
-----------------------------------------

I was using the following setup (might work on others too)

- Ubuntu 22.04
- CMake 3.29
- clang 18.1.3
- ninja 1.11.1
  
Each folder in the repository represents an example program for a different library
Currently, the project compiles all example without an option to choose a target. 
Artifacts are stored in <BUILD_DIRECTORY>/bin/<BUILD_TYPE>

Building the repo
-----------------

The following builds the project:

```cmake -S <SRC_DIR> -B <BUILD_DIR> -DCMAKE_BUILD_TYPE=<BUILD_TYPE> -G Ninja && cmake --build <BUILD_DIR>```

For example, if the project is cloned into ~/loggers_comparison folder, and pwd is ~, the following should be typed for the project to build:

```cmake -S loggers_comparison -B loggers_comparison/build -DCMAKE_BUILD_TYPE=Release -G Ninja && cmake --build loggers_comparison/build```

And the artifacts will be present in ```loggers_comparison/build/bin/Release```

spdlog_example
--------------

The spdlog example artifact is called ```spdlog-log-example``` and located in ```<BUILD_DIR>/bin/<BUILD_TYPE>/```

Displaying help:

```
cd loggers_comparison
build/bin/Release/spdlog-log-example -h

Available flags:
-e, --basic-example - run the basic_usage_example() function
-m, --hand-made - run the handmade_logger() function
-c, --console - run the console_logger() function
-a, --async - run the async_logger() function
-s, --stopwatch - run the stopwatch() function
-a, --async - run the async_logger() function
-u, --user-defined - run the user_defined_object_logger() function
-h, --help - print this screen and exit
```

glog_example
------------

The glog example artifact is called ```glog-log-example``` and located in ```<BUILD_DIR>/bin/<BUILD_TYPE>/```

Usage:

```
cd loggers_comparison
build/bin/Release/g-log-example 

Available flags:
-m, --multiple-log-levels - run the multiple_log_levels() function
-f, --custom-formatting - run the custom_formatting() function
-c, --conditional-logging - run the conditional_logging() function
-a, --async - run the async_logger() function
-s, --custom-sink - run the custom_sink_logging() function
```

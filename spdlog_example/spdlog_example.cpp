
#include "basic_usage.example.h"
#include "handmade_logger.h"
#include "console_logger.h"
#include "stopwatch.h"
#include "async_logger.h"

#include "spdlog/spdlog.h"
#include "spdlog/stopwatch.h"
#include "cxxopts.hpp"

#include <iostream>
#include <filesystem>

int main(int argc, char** argv) 
{
    cxxopts::Options options("spdlog-log-test", "spdlog usage example");
    options.add_options()
    ("e, basic-example", "basic example") 
    ("m, hand-made", "hand-made logger")
    ("c, console", "console logger")
    ("b, backtrace", "backtrace logger")
    ("s, stopwatch", "stopwatch example")
    ("a, async", "async logger")
    ("h, help", "print help")
    ;
    
    auto parsed_options = options.parse(argc, argv);
    
    // Create the logs/ directory
    const std::filesystem::path directory{ "logs/" };
    if (!std::filesystem::exists(directory))
    {
        if (!std::filesystem::create_directory(directory))
        {
            std::cerr << "Failed to create logs directory\n";
            return 1;
        }
    }

    if (parsed_options.count("h"))
    {
        std::cout << "Available flags:\n";
        std::cout << "-e, --basic-example - run the basic_usage_example() function\n";
        std::cout << "-m, --hand-made - run the handmade_logger() function\n";
        std::cout << "-c, --console - run the console_logger() function\n";
        std::cout << "-a, --async - run the async_logger() function\n";
        std::cout << "-s, --stopwatch - run the stopwatch() function\n";
        std::cout << "-a, --async - run the async_logger() function\n";
        std::cout << "-h, --help - print this screen and exit\n";

        return 0;
    }

    if (parsed_options.count("e"))
    {
        basic_usage_example();
    }
    if (parsed_options.count("m"))
    {
        handmade_logger();
    }
    if (parsed_options.count("c"))
    {
        console_logger();
    }
    if (parsed_options.count("s"))
    {
        stopwatch();
    }
    if (parsed_options.count("a"))
    {
        async_logger();
    }

    return 0;
}
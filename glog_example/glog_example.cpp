#include "cxxopts.hpp"
#include "glog_functions.h"

int main(int argc, char* argv[]) 
{   
    init(argv[0]);

    cxxopts::Options options("spdlog-log-test", "spdlog usage example");
    options.add_options()
    ("e, basic-example", "basic example") 
    ("m, multiple-log-levels", "several log messages with different levels") 
    ("c, custom-formatting", "custom prefix formatting")
    ;
    auto parsed_options = options.parse(argc, argv);

    if (parsed_options.count("e"))
    {
        basic_usage();
    }
    if (parsed_options.count("m"))
    {
        multiple_log_levels();
    }
    if (parsed_options.count("c"))
    {
        custom_formatting();
    }
}
#include "cxxopts.hpp"
#include "glog_functions.h"

int main(int argc, char* argv[]) 
{   
    init(argv[0]);

    cxxopts::Options options("spdlog-log-test", "spdlog usage example");
    options.add_options()
    ("m, multiple-log-levels", "several log messages with different levels") 
    ("f, custom-formatting", "custom prefix formatting")
    ("c, conditional-logging", "conditional logging")
    ;

    auto parsed_options = options.parse(argc, argv);
    if (parsed_options.count("m"))
    {
        multiple_log_levels();
    }
    if (parsed_options.count("f"))
    {
        custom_formatting();
    }
    if (parsed_options.count("c"))
    {
        conditional_logging();
    }
}
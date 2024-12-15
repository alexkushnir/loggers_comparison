#include "el_functions.h"
#include "cxxopts.hpp"

int main(int argc, char* argv[]) 
{
   cxxopts::Options options("el-log-example", "spdlog usage example");
   options.add_options()
   ("b, basic-example", "basic usage example") 
   ("f, config-file", "configuration file example")
   ("c, config-class", "configuration class example") 
   ("d, conditional-logging", "conditional logging example")
   ("o, ocassional-logging", "ocassional logging example")
   ("p, printf-logging", "printf-like logging example")
   ("r, performance-tracking", "performance tracking example")
   ("e, performance-checkpoint", "performance checkpoints example")
   ("a, crash-handling", "crash handling example")
   ("u, custom-object", "custom object logging example")
   ("t, third-party-logging", "third-party object logging example")
   ;

   auto parsed_options = options.parse(argc, argv);

   if (parsed_options.count("b"))
   {
      basic_usage();
   }
   
   if (parsed_options.count("f"))
   {
      configuration_file_example();
   }
   
   if (parsed_options.count("c"))
   {
      configuration_class_example();
   }
 
   if (parsed_options.count("d"))
   {
      conditional_logging();
   }

   if (parsed_options.count("o"))
   {
      ocassional_logging();
   }

   if (parsed_options.count("p"))
   {
      printf_logging();
   }

   if (parsed_options.count("r"))
   {
      performance_logging();
   }  

   if (parsed_options.count("e"))
   {
      performance_checkpoints();
   }

   if (parsed_options.count("a"))
   {
      crash_handling();
   }

   if (parsed_options.count("u"))
   {
      custom_object_logging();
   }  

   if (parsed_options.count("t"))
   {
      third_party_logging();
   }

   return 0;
}
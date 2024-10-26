#include "spdlog/spdlog.h"
#include "spdlog/async.h" 
#include "spdlog/sinks/basic_file_sink.h"

void async_logger()
{
    auto async_file = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
    for (auto i = 1; i < 42; ++i)
    {
        async_file->info("Async message #{}", i);
    }
    
    // Under VisualStudio, this must be called before main finishes to workaround a known VS issue
    spdlog::drop_all(); 
}
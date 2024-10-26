#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void console_logger()
{
    auto logger = spdlog::stdout_color_mt("stdout");

    logger->info("This is an info log message");
}

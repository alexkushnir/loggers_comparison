#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <memory>

void handmade_logger()
{
    auto logger = std::make_shared<spdlog::logger>("handmade-logger");
    logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/basic_sink.txt"));
    logger->set_level(spdlog::level::debug);

    logger->log(spdlog::level::trace, "TRACE");
    logger->log(spdlog::level::debug, "DEBUG");
    logger->log(spdlog::level::info, "INFO");
    logger->log(spdlog::level::warn, "WARNING");
    logger->log(spdlog::level::err, "ERROR");
    logger->log(spdlog::level::critical, "CRITICAL");
}


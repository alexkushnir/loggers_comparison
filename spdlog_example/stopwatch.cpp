#include "spdlog/spdlog.h"
#include "spdlog/stopwatch.h"

#include <thread>

void stopwatch()
{
    using namespace std::literals;

    spdlog::stopwatch sw;
    spdlog::info("Elapsed {:.3}", sw);
    std::this_thread::sleep_for(3.5s);
    spdlog::info("Elapsed {}", sw);
}


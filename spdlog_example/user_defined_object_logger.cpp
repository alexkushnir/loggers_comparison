#include "spdlog/spdlog.h"
#include "spdlog/fmt/fmt.h"

#include <string>
#include <vector>
#include <iostream>

struct custom_loggable
{
    explicit custom_loggable(const std::string& input_str, const std::vector<std::uint32_t>& input_values)
        : str{ input_str }
        , values{ input_values }
    {}

    std::string str;
    std::vector<std::uint32_t> values;
};

template<>
struct fmt::formatter<custom_loggable> : fmt::formatter<std::string>
{
    auto format(custom_loggable loggable, format_context &ctx) const -> decltype(ctx.out())
    {
        std::string vector_str;
        vector_str  = "[ ";
        for (const auto& entry : loggable.values)
        {
            vector_str += std::format("{} ", entry);
        }
        
        vector_str += "]";

        return fmt::format_to(ctx.out(), "custom_loggable(str: '{}', values: {})", loggable.str, vector_str);
    }
};

void user_defined_object_logger()
{
    custom_loggable cl{ "Lost", { 4, 8, 15, 16, 23, 42 } };
    spdlog::info("user defined type: {}", cl);
}
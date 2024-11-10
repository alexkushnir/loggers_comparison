#include "glog/logging.h"
#include "glog_functions.h"

#include <ranges>
#include <iomanip>
#include <thread>
#include <iostream>

void init(const char* log_name)
{
    google::InitGoogleLogging(log_name); 
}

void multiple_log_levels()
{
    for (const auto& index  : std::views::iota(0, 10))
    {
        if (index % 3 == 0)
        {
            LOG(INFO) << "The index is now " << index << "ddd"; 
        }
        else if (index % 3 == 1)
        {
            LOG(WARNING) << "The index is now  " << index;
        }
        else if (index % 3 == 2)
        {
            LOG(ERROR) << "The index is now " << index;
        }
    }
}

static void custom_formatter(std::ostream& s, const google::LogMessage& m, void* data)
{
    s << google::GetLogSeverityName(m.severity())[0]
        << "["
        << std::setw(2) << m.time().hour() << ':'
        << std::setw(2) << m.time().min()  << ':'
        << std::setw(2) << m.time().sec() << "."
        << ' '
        << std::setfill(' ') << std::setw(5)
        << ' '
        << m.basename() << ':' << m.line() << "]";
}

static void default_formatter(std::ostream& s, const google::LogMessage& m, void* data)
{
    s << google::GetLogSeverityName(m.severity())[0]
        << std::setw(4) << 1900 + m.time().year()
        << std::setw(2) << 1 + m.time().month()
        << std::setw(2) << m.time().day()
        << ' '
        << std::setw(2) << m.time().hour() << ':'
        << std::setw(2) << m.time().min()  << ':'
        << std::setw(2) << m.time().sec() << "."
        << std::setw(6) << m.time().usec()
        << ' '
        << std::setfill(' ') << std::setw(5)
        << m.thread_id() << std::setfill('0')
        << ' '
        << m.basename() << ':' << m.line() << "]";
}

void custom_formatting()
{
    google::InstallPrefixFormatter(&custom_formatter);
    auto answer_to_everything = 42;
    LOG(INFO) << "The answer to everything is " << answer_to_everything; 
}

void conditional_logging()
{
    google::InstallPrefixFormatter(&custom_formatter);

    auto threshold = 5;

    LOG(INFO) << "=== Demonstrating conditional logging ===";
    for (const auto& temp : std::views::iota(1, 10))
    {
        LOG_IF(INFO, temp > threshold) << "LOG_IF: Alert, temperature is " << temp;
    }

    LOG(INFO) << "=== Demonstrating every Nth event logging ===";
    for (const auto& event : std::views::iota(1, 100))
    {
        LOG_EVERY_N(INFO, 25) << "LOG_IF_EVERY_N: Got event no. " << event;
    }

    LOG(INFO) << "=== Demonstrating first N times logging ===";
    for (const auto& event : std::views::iota(1, 10))
    {
        LOG_FIRST_N(INFO, 3) << "LOG_IF_FIRST_N: Got event no. " << event;
    }

    LOG(INFO) << "=== Demonstrating every 0.1s logging ===";
    using namespace std::literals;
  
    for (const auto& count : std::views::iota(1, 10))
    {
        LOG_EVERY_T(INFO, 0.1) << "The thread is still alive, count: " << count;
        std::this_thread::sleep_for(0.2s);
    }
}


struct CustomLogSink : google::LogSink 
{  
    void send(google::LogSeverity severity, const char* filename,
        const char* base_filename, int line,
        const google::LogMessageTime& timestamp, const char* message,
        std::size_t message_len) override 
    {
        std::cout << google::GetLogSeverityName(severity) << ' ' << base_filename
            << ':' << line << ' ';
        std::copy_n(message, message_len,
            std::ostreambuf_iterator<char>{std::cout});
        std::cout << '\n';
    }
};

void custom_sink_logging()
{
    CustomLogSink sink;
    google::AddLogSink(&sink);

    LOG(INFO) << "logging to MySink";

    google::RemoveLogSink(&sink);  

    LOG_TO_SINK(&sink, INFO) << "direct logging";  
    LOG_TO_SINK_BUT_NOT_TO_LOGFILE(&sink, INFO) << "direct logging but not to file";
}
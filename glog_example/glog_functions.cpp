#include "glog/logging.h"
#include "glog_functions.h"

#include <ranges>
#include <iomanip>

void init(const char* log_name)
{
    google::InitGoogleLogging(log_name); 
}

void basic_usage()
{
    auto num_cookies = 15;
    LOG(INFO) << "Found " << num_cookies << " cookies"; 
}

void multiple_log_levels()
{
    for (auto num_cookies  : std::views::iota(0, 10))
    {
        if (num_cookies % 3 == 0)
        {
            LOG(INFO) << "Found " << num_cookies << " cookies"; 
        }
        else if (num_cookies % 3 == 1)
        {
            LOG(WARNING) << "Found " << num_cookies << " cookies";
        }
        else if (num_cookies % 3 == 2)
        {
            LOG(ERROR) << "Found " << num_cookies << " cookies";
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
    auto num_cookies = 15;
    LOG(INFO) << "Found " << num_cookies << " cookies"; 
}


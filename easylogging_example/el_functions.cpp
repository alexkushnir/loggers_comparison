#include "easylogging++.h"
#include <vector>
#include <map>
#include <string>
#include <thread>

INITIALIZE_EASYLOGGINGPP

void basic_usage()
{
    LOG(INFO) << "This is the most basic usage";
}

void configuration_file_example()
{
    el::Configurations cfg{ "easylogging_example/example_config.conf" }; // Replace with the path to config
    el::Loggers::reconfigureLogger("default", cfg);

    LOG(INFO) << "Using global options";
    LOG(DEBUG) << "Using debug options";
}

void configuration_class_example()
{
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    
    defaultConf.set(el::Level::Info, el::ConfigurationType::Format, "%datetime %level %msg");
    
    el::Loggers::reconfigureLogger("default", defaultConf);
    LOG(INFO) << "Log using default file";
    
    defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %msg"); 
    el::Loggers::reconfigureLogger("default", defaultConf);

    LOG(INFO) << "Log using default file after reconfiguration";
}

void conditional_logging()
{
    for (auto i = 0; i < 10; ++i)
    {
        LOG_IF(i < 5, INFO) << "i is less than 5, " << i;  
    }
}

void ocassional_logging()
{
    LOG(INFO) << "Log every 5th time";

    for (auto i = 0; i < 10; ++i)
    {
        LOG_EVERY_N(5, INFO) << "Log every 5th time " << i;
    }

    LOG(INFO) << "Log after 5th time";

    for (auto i = 0; i < 10; ++i)
    {
        LOG_AFTER_N(5, INFO) << "i > 5 " << i;
    }
}

void printf_logging()
{
    decltype(auto) defaultLogger = el::Loggers::getLogger("default");

    std::vector<int> v;
    for (auto i = 0; i < 5; ++i)
    {
        v.push_back(i);
    }

    std::map<int, std::string> m = { { 1, "one" }, { 2, "two" }, { 3, "three" } };
    defaultLogger->warn("Printing vector: %v", v);
    defaultLogger->info("Printing map: %v", m);
}

void performance_logging()
{
    using namespace std::literals;

    TIMED_FUNC(functionTimer);
    std::vector<int> v;
    
    for (auto i = 0; i < 1'000'000; ++i);

    for (auto i = 0; i < 10; ++i)
    {
        TIMED_SCOPE(scopeTimer, "single-iteration");
        v.push_back(i);
        std::this_thread::sleep_for(150ms);
    }    
}

void performance_checkpoints()
{
    using namespace std::literals;

    TIMED_FUNC(functionTimer);
    std::vector<int> v;
    
    for (auto i = 0; i < 1'000'000; ++i);

    for (auto i = 0; i < 10; ++i)
    {
        TIMED_SCOPE(scopeTimer, "single-iteration");
        v.push_back(i);
        std::this_thread::sleep_for(150ms);
        if (i % 3 == 0 || i % 2 == 0)
        {
            PERFORMANCE_CHECKPOINT(functionTimer);
        }
    }    
}

static void crash_handler(int signal)
{
    LOG(ERROR) << "Program has crashed!";
    // void Helpers::logCrashReason(int sig, bool stackTraceIfAvailable, Level level, const char* logger) {
    // el::Helpers::logCrashReason(signal, true, el::Level::Info, "default");
    el::Helpers::crashAbort(signal);
}

void crash_handling()
{
    el::Helpers::setCrashHandler(crash_handler);
    LOG(INFO) << "Testing crash handler";

    int* p = nullptr;
    *p = 0;
}

class CustomLoggable : public el::Loggable
{
public: 
    CustomLoggable(const int integer, const float floating_point, const std::string str)
        : m_integer{ integer }
        , m_floating_point{ floating_point }
        , m_string{ str }
    {}

    void log(el::base::type::ostream_t& os) const override 
    {
        os << "Integer: [" << m_integer << "], float: [" << m_floating_point << "], string: [" << m_string << "]";
    }

private:
    int m_integer;
    float m_floating_point;
    std::string m_string;
};

void custom_object_logging()
{
    CustomLoggable cl{ 5, 3.14f, "Who am I?" };

    LOG(INFO) << cl;
}

class CustomNonLoggable
{
public: 
    CustomNonLoggable(const int integer, const float floating_point, const std::string str)
        : m_integer{ integer }
        , m_floating_point{ floating_point }
        , m_string{ str }
    {}

    std::tuple<int, float, std::string> GetMembers() const
    {
        return { m_integer, m_floating_point, m_string };
    }

private:
    int m_integer;
    float m_floating_point;
    std::string m_string;
};

inline MAKE_LOGGABLE(CustomNonLoggable, cnl, os)
{
    auto [integer, floating_point, str] = cnl.GetMembers();

    os << "Integer: [" << integer << "], float: [" << floating_point << "], string: [" << str << "]";

    return os;
}

void third_party_logging()
{
    CustomNonLoggable cnl{ 5, 3.14f, "Am I non-loggable? "};

    LOG(INFO) << cnl;
}

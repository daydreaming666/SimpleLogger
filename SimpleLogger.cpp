#include "SimpleLogger.hpp"

void SimpleLogger::printer(LogLevel logLevel, const std::string& tag, const std::string& msg) {
    std::string level;
    switch (logLevel) {
        case LogLevel::Verbose: {
            level = "VERBOSE";
            break;
        }
        case LogLevel::Debug: {
            level = "DEBUG";
            break;
        }
        case LogLevel::Info: {
            level = "INFO";
            break;
        }
        case LogLevel::Warn: {
            level = "WARN";
            break;
        }
        case LogLevel::Error: {
            level = "ERROR";
            break;
        }
        case LogLevel::Assert: {
            level = "ERROR";
            break;
        }
    }
    char tmBuffer[64];
    time_t time1 = time(nullptr);
    auto pid = std::this_thread::get_id();
    strftime(tmBuffer, 64, "%m-%e %H:%M:%S", gmtime(&time1));
    fprintf(_fp, "[%6s] %s %I64u /%s %c/%s: %s \n",
            level.c_str(), tmBuffer , *(std::uint64_t*)&pid, _appName.c_str(),
            level.c_str()[0], tag.c_str(), msg.c_str());
    fflush(_fp);
}

SimpleLogger::SimpleLogger(FILE* fp) : SimpleLogger(fp, "?") {}

SimpleLogger::SimpleLogger() : SimpleLogger(stderr, "?") {}

SimpleLogger::SimpleLogger(FILE* fp, std::string appName) : _fp(fp), _appName(std::move(appName)) {}


void SimpleLogger::v(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Verbose, tag, msg);
}

void SimpleLogger::d(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Debug, tag, msg);
}

void SimpleLogger::i(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Info, tag, msg);
}

void SimpleLogger::w(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Warn, tag, msg);
}

void SimpleLogger::e(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Error, tag, msg);
}

void SimpleLogger::wtf(const std::string& tag, const std::string& msg) {
    printer(LogLevel::Assert, tag, msg);
}


#ifndef SIMPLELOGGER_SIMPLELOGGER_HPP
#define SIMPLELOGGER_SIMPLELOGGER_HPP

#include <cstdio>
#include <string>
#include <ctime>
#include <thread>

/**
 * @brief A Simple Logger
 * @usage
 * @code
 * SimpleLogger Logger;
 * Logger.v("TAG","MESSAGE"); // print verbose message to stderr
 */
class SimpleLogger {
private:
    enum class LogLevel{
        Verbose = 0,
        Debug = 1,
        Info = 2,
        Warn = 3,
        Error = 4,
        Assert = 5
    };

    FILE * _fp;
    std::string _appName;

    void printer(LogLevel logLevel, const std::string&  tag, const std::string&  msg);
public:
    explicit SimpleLogger(FILE * fp);

    SimpleLogger(FILE * fp, std::string appName);

    SimpleLogger();

    // Verbose
    void v(const std::string &tag, const std::string &msg);

    // Debug
    void d(const std::string &tag, const std::string &msg);

    // Info
    void i(const std::string &tag, const std::string &msg);

    // Warn
    void w(const std::string &tag, const std::string &msg);

    // Error
    void e(const std::string &tag, const std::string &msg);

    // WTF
    void wtf(const std::string &tag, const std::string &msg);
};

#endif //SIMPLELOGGER_SIMPLELOGGER_HPP

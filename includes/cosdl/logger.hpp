#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    static void log(std::string sender, std::string message);

    static void warn(std::string sender, std::string message);
};

#endif

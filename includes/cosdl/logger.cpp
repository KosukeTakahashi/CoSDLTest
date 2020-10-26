#include <iostream>
#include <string>
#include "./logger.hpp"

void Logger::log(std::string sender, std::string message) {
    std::cout << "LOG :: [" << sender << "] " << message << std::endl;
}

void Logger::warn(std::string sender, std::string message) {
    std::cout << "WRN :: [" << sender << "] " << message << std::endl;
}

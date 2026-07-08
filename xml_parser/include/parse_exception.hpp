#pragma once
#include <string>

struct ParseException : public std::exception {
private:
    std::string message;
public:
    explicit ParseException(std::string msg) : message(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

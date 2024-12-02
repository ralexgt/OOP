#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

class PlayerException final : public std::exception {
private:
    std::string msg;
public:
    explicit PlayerException(std::string  message) : msg(std::move(message)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

class GameException final : public std::exception {
private:
    std::string msg;
public:
    explicit GameException(std::string  message) : msg(std::move(message)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

class CharacterException final : public std::exception {
private:
    std::string msg;
public:
    explicit CharacterException(std::string  message) : msg(std::move(message)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif // EXCEPTIONS_H

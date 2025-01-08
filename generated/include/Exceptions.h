#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

// Base exception to derive all other exceptions from
class BaseGameException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Base game exception";
    }
};

// Player name can't be empty exception
class NonNullNameException final : public BaseGameException {
public:
    const char* what() const noexcept override {
        return "Must select a player name, it can not be empty.";
    }
};

// Other character than the 3 predefined were chosen
class InvalidCharacterException final : public BaseGameException {
public:
    const char* what() const noexcept override {
        return "Must input \"Swordsman\", \"Archer\" or \"Mage\"";
    }
};

// game state should never happen
class InvalidGameState final : public BaseGameException {
public:
    const char* what() const noexcept override {
        return "Got into a broken game state";
    }
};

#endif // EXCEPTIONS_H

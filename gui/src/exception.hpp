/*
** EPITECH PROJECT, 2023
** B-CCP-400-MAR-4-1-theplazza-gianni.calamita
** File description:
** exepction
*/

#pragma once

#include <exception>
#include <string>

namespace gui
{
    class exception : public std::exception {
        public:
            exception(const std::string &message) : _message(message) {}
            ~exception() = default;

            const char *what() const noexcept override { return _message.c_str(); }
            const int getErrorCode() const noexcept { return 84; }
        private:
            std::string _message;
    };
} // namespace plazza

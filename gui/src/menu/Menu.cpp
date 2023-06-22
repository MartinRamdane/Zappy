/*
** EPITECH PROJECT, 2023
** Menu.cpp
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{
} // t'avais une tentative de merge ou pas N? 

void Menu::setState(MenuState state)
{
    this->_previousState = this->_currentState;
    this->_currentState = state;
}
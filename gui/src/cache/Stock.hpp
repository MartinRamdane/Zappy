/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Stock
*/

#pragma once

class Stock {
    public:
        int food = 0;
        int linemate = 0;
        int deraumere = 0;
        int sibur = 0;
        int mendiane = 0;
        int phiras = 0;
        int thystame = 0;
        Stock(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
        Stock();
        ~Stock();
        int getTotalGem();
};

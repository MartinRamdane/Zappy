#pragma once

#include "Tile.hpp"
#include <tuple>
#include <map>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Display
{
    private:
        std::map<std::tuple<double, double>, Tile> tile;
    public:
        Display(/* args */);
        ~Display();
        
};
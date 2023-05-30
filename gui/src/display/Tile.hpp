#pragma once

#include "stock.hpp"

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Tile
{
    private:
        Stock stock;
    public:
        Tile(/* args */);
        ~Tile();
        
};


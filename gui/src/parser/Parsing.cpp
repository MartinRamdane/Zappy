/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Parsing.cpp
*/

#include "Parsing.hpp"

Parsing::Parsing()
{
    if (!death.openFromFile("gui/assets/sounds/mort.ogg"))
        exit(84);
    if (!push.openFromFile("gui/assets/sounds/push.ogg"))
        exit(84);
}

Parsing::~Parsing()
{
}

void Parsing::parse(std::string str)
{
    std::string delimiter = " ";
    int pos = str.find(delimiter);
    std::string cmd = str.substr(0, pos);
    std::string arg = str.substr(4, str.length() - 1);
    if (cmd == "msz")
        msz(arg);
    if (cmd == "bct")
        bct(arg);
    if (cmd == "tna")
        tna(arg);
    if (cmd == "pnw")
        pnw(arg);
    if (cmd == "ppo")
        ppo(arg);
    if (cmd == "plv")
        plv(arg);
    if (cmd == "pin")
        pin(arg);
    if (cmd == "pex")
        pex(arg);
    if (cmd == "pbc")
        pbc(arg);
    if (cmd == "pic")
        pic(arg);
    if (cmd == "pie")
        pie(arg);
    if (cmd == "pfk")
        pfk(arg);
    if (cmd == "pdr")
        pdr(arg);
    if (cmd == "pgt")
        pgt(arg);
    if (cmd == "pdi")
        pdi(arg);
    if (cmd == "enw")
        enw(arg);
    if (cmd == "ebo")
        ebo(arg);
    if (cmd == "edi")
        edi(arg);
    if (cmd == "sst")
        sst(arg);
    if (cmd == "sgt")
        sgt(arg);
    if (cmd == "seg")
        seg(arg);
    if (cmd == "smg")
        smg(arg);
    if (cmd == "suc")
        suc(arg);
    if (cmd == "sbp")
        sbp(arg);
}

void Parsing::msz(std::string arg)
{
    std::string delimiter = " ";
    int pos = arg.find(delimiter);
    mapt.setX(std::stoi(arg.substr(0, pos)));
    mapt.setY(std::stoi(arg.substr(pos + 1, arg.length())));
}

void Parsing::bct(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(std::stoi(parts[2]), std::stoi(parts[3]), std::stoi(parts[4]), std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]), std::stoi(parts[8]));
    Tile tile(stock);
    std::tuple<double, double> tuple = std::make_tuple(std::stoi(parts[0]), std::stoi(parts[1]));
    mapt.setTile(tuple, tile);
}

void Parsing::tna(std::string arg)
{
    ;
}

void Parsing::pnw(std::string arg)
{
    arg = arg.substr(0, arg.length());
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(0, 0, 0, 0, 0, 0, 0);
    Trantorian trantorian(stock, std::stoi(parts[0]), std::stoi(parts[3]), std::stoi(parts[4]), false, std::stoi(parts[1]), std::stoi(parts[2]), parts[5]);
    mapt.addTrantorian(trantorian);
}

void Parsing::ppo(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianPos(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]), std::stoi(parts[3]));
}

void Parsing::plv(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianLvl(std::stoi(parts[0]), std::stoi(parts[1]));
}

void Parsing::pin(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    Stock stock(std::stoi(parts[3]), std::stoi(parts[4]), std::stoi(parts[5]), std::stoi(parts[6]), std::stoi(parts[7]), std::stoi(parts[8]), std::stoi(parts[9]));
    mapt.setTrantorianStock(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]), stock);
}

void Parsing::pex(std::string arg)
{
    if (death.getStatus() != sf::Music::Playing) {
        death.play();
    }
    mapt.setTrantorianEjection(std::stoi(arg), true);
}

void Parsing::pbc(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    while (ss >> part) {
        parts.push_back(part);
    }
    mapt.setTrantorianMessage(std::stoi(parts[0]), parts[1]);
}

void Parsing::pic(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    Tile tile = mapt.getTile(std::stoi(parts[0]), std::stoi(parts[1]));
    std::vector<int> trantorian;
    for (int i = 3; i < parts.size(); i++) {
        trantorian.push_back(std::stoi(parts[i]));
    }
    tile.setPlayers(trantorian);
    tuple = std::make_tuple(std::stoi(parts[0]), std::stoi(parts[1]));
    mapt.setTile(tuple, tile);
    for (int i = 3; i < parts.size(); i++) {
        mapt.setTrantorianCanEvolve(std::stoi(parts[i]), true);
    }
}

void Parsing::pie(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    std::vector<Trantorian> trantorian = mapt.getTrantorians();
    for (auto &tranto : trantorian) {
        if (tranto.getX() == std::stoi(parts[0]) && tranto.getY() == std::stoi(parts[1])) {
            if (tranto.getCanEvolve() == true) {
                if (std::stoi(parts[2]) == 1) {
                    mapt.setTrantorianLvl(tranto.getId(), tranto.getLvl() + 1);
                    mapt.setTrantorianCanEvolve(tranto.getId(), false);
                } else {
                    mapt.setTrantorianCanEvolve(tranto.getId(), false);
                }
            }
        }
    }
}

void Parsing::pfk(std::string arg)
{
    ;
}

void Parsing::pdr(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    int x = mapt.getTrantorian(std::stoi(parts[0])).getX();
    int y = mapt.getTrantorian(std::stoi(parts[0])).getY();
    Stock stockT = mapt.getTile(x, y).getStock();
    Stock stock = mapt.getTrantorian(std::stoi(parts[0])).getStock();
    if (parts[1] == "0") {
        stockT.linemate ++;
        stock.linemate --;
    }
    if (parts[1] == "1") {
        stockT.deraumere ++;
        stock.deraumere --;
    }
    if (parts[1] == "2") {
        stockT.sibur ++;
        stock.sibur --;
    }
    if (parts[1] == "3") {
        stockT.mendiane ++;
        stock.mendiane --;
    }
    if (parts[1] == "4") {
        stockT.phiras ++;
        stock.phiras --;
    }
    if (parts[1] == "5") {
        stockT.thystame ++;
        stock.thystame --;
    }
    if (parts[1] == "6") {
        stockT.food ++;
        stock.food --;
    }
    mapt.getTrantorian(std::stoi(parts[0])).setStock(stock);
}

void Parsing::pgt(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    int x = mapt.getTrantorian(std::stoi(parts[0])).getX();
    int y = mapt.getTrantorian(std::stoi(parts[0])).getY();
    Stock stockT = mapt.getTile(x, y).getStock();
    Stock stock = mapt.getTrantorian(std::stoi(parts[0])).getStock();
    if (parts[1] == "0") {
        stockT.linemate --;
        stock.linemate ++;
    }
    if (parts[1] == "1") {
        stockT.deraumere --;
        stock.deraumere ++;
    }
    if (parts[1] == "2") {
        stockT.sibur --;
        stock.sibur ++;
    }
    if (parts[1] == "3") {
        stockT.mendiane --;
        stock.mendiane ++;
    }
    if (parts[1] == "4") {
        stockT.phiras --;
        stock.phiras ++;
    }
    if (parts[1] == "5") {
        stockT.thystame --;
        stock.thystame ++;
    }
    if (parts[1] == "6") {
        stockT.food --;
        stock.food ++;
    }
    mapt.getTrantorian(std::stoi(parts[0])).setStock(stock);
}

void Parsing::pdi(std::string arg)
{
    if (death.getStatus() != sf::Music::Playing) {
        death.play();
    }
    mapt.setTrantorianDeath(std::stoi(arg));
}

void Parsing::enw(std::string arg)
{
    std::vector<std::string> parts;
    std::stringstream ss(arg);
    std::string part;
    std::tuple<double, double> tuple;
    while (ss >> part) {
        parts.push_back(part);
    }
    Egg e(std::stoi(parts[0]), std::stoi(parts[2]), std::stoi(parts[3]));
    mapt.addEgg(e);
}

void Parsing::ebo(std::string arg)
{
    mapt.removeEgg(std::stoi(arg));
}

void Parsing::eht(std::string arg)
{
    mapt.setHasHatched(std::stoi(arg));
}

void Parsing::edi(std::string arg)
{
    mapt.removeEgg(std::stoi(arg));
}

void Parsing::sgt(std::string arg)
{
    mapt.setFrequency(std::stod(arg));
}

void Parsing::sst(std::string arg)
{
    mapt.setFrequency(std::stod(arg));
}

void Parsing::seg(std::string arg)
{
    mapt.setWinner(arg);
}

void Parsing::smg(std::string arg)
{
    ;
}

void Parsing::suc(std::string arg)
{
    std::cout << "unknow command" << std::endl;
}

void Parsing::sbp(std::string arg)
{
    std::cout << "bad parameter" << std::endl;
}

MapT Parsing::getMap()
{
    return mapt;
}

MapT *Parsing::getMapPtr()
{
    return &mapt;
}

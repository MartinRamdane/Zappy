/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Parsing.cpp
*/

#include "Parsing.hpp"

Parsing::Parsing()
{
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
    std::cout << "Map size: " << arg.substr(0, pos) << " " << arg.substr(pos + 1, arg.length()) << std::endl;
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
    std::cout << "Tile " << parts[0] << " " << parts[1] << " has " << parts[2] << " " << parts[3] << " " << parts[4] << " " << parts[5] << " " << parts[6] << " " << parts[7] << " " << parts[8] << std::endl;
}

void Parsing::tna(std::string arg)
{
    std::cout << "Teams names: " << arg << std::endl;
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
    std::cout << "Trantorian " << parts[0] << " is born with orientation" << parts[3][0] << std::endl;
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
    std::cout << "Trantorian " << parts[0] << " is at " << parts[1] << " " << parts[2] << " " << parts[3] << std::endl;
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
    std::cout << "lvl of " << parts[0] << " is " << parts[1] << std::endl;
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
    std::cout << "inventory of" << parts[0] << std::endl;
}

void Parsing::pex(std::string arg)
{
    mapt.setTrantorianEjection(std::stoi(arg), true);
    std::cout << "Trantorian " << arg << " is explused" << std::endl;
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
    std::cout << "message envoyé par " << part[0] << std::endl;
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
    std::cout << "incantation from";
    for (int i = 3; i < parts.size(); i++) {
        mapt.setTrantorianCanEvolve(std::stoi(parts[i]), true);
        std::cout << " " << parts[i];
    }
    std::cout << " to lvl " << parts[2] << std::endl;
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
    Tile tile = mapt.getTile(std::stoi(parts[0]), std::stoi(parts[1]));
    if (parts[2] == "1") {
        for (int i = 0; i < tile.getPlayers().size(); i++) {
            mapt.setTrantorianLvl(tile.getPlayers()[i], tile.getLvlEvo());
        }
    } else {
        for (int i = 0; i < tile.getPlayers().size(); i++) {
            mapt.setTrantorianCanEvolve(tile.getPlayers()[i], false);
        }
    }
    std::cout << "fin incantation" << std::endl;
}

void Parsing::pfk(std::string arg)
{
    std::cout << "inutile" << std::endl;
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
    std::cout << "item recupéré" << std::endl;
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
    std::cout << "item posé" << std::endl;
}

void Parsing::pdi(std::string arg)
{
    mapt.removeTrantorian(std::stoi(arg));
    std::cout << "mort" << std::endl;
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
    std::cout << "egg spawn" << std::endl;
}

void Parsing::ebo(std::string arg)
{
    mapt.removeEgg(std::stoi(arg));
    std::cout << "egg born" << std::endl;
}

void Parsing::eht(std::string arg)
{
    mapt.setHasHatched(std::stoi(arg));
    std::cout << "egg hatched" << std::endl;
}

void Parsing::edi(std::string arg)
{
    mapt.removeEgg(std::stoi(arg));
    std::cout << "egg dead" << std::endl;
}

void Parsing::sgt(std::string arg)
{
    std::cout << "frequency : " << arg << std::endl;
    mapt.setFrequency(std::stod(arg));
}

void Parsing::sst(std::string arg)
{
    std::cout << "frequency : " << arg << std::endl;
    mapt.setFrequency(std::stod(arg));
}

void Parsing::seg(std::string arg)
{
    mapt.removeTeam(arg);
    std::cout << "team " << arg << " dead" << std::endl;
}

void Parsing::smg(std::string arg)
{
    std::cout << "message : " << arg << std::endl;
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

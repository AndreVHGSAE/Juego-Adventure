#pragma once
#include "Character.h"
class Player :
    public Character
{
private:
    int strenght;
    int agility;
    int intelligence;
    int luck;
    int dexterity;
public:
    Player();
    void InitPlayer(std::string name);
    void PrintPlayerStats();
    ~Player();
};


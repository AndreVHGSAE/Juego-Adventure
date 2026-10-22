#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:
public:
    Enemy();
    Enemy(std::string name, int l, int hp, int damage,
        int defence, int exp);
    ~Enemy();
    void InitEnemy();
    void PrintEnemyStats();
    
};


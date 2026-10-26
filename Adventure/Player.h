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

    int MaxEXP;
    int SkillPoints;
public:
    Player();
    void InitPlayer(std::string name);
    void PrintPlayerStats();
    ~Player();
    void LevelUp();
    void AddStats(int stat, int value);
    void UpdateValues();

    //Get
    int GetStrenght() { return strenght; }
    int GetAgility() { return agility; }
    int GetIntelligence() { return intelligence; }
    int GetLuck() { return luck; }
    int GetDexterity() { return dexterity; }

    int GetSkillPoints() { return SkillPoints; }

    //Set
    void SetStrenght(int s) {strenght = s; }
    void SetAgility(int a) {agility = a; }
    void SetIntelligence(int i) {intelligence = i; }
    void SetLuck(int l) {luck = l; }
    void SetDexterity(int d) {luck = d; }
};


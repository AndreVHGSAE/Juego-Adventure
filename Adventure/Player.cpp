#include "Player.h"

Player::Player() :Character()
{
	this->strenght = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;
	this->dexterity = 5;
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetExp(0);
	SetHP((this->intelligence*2) / (this->dexterity-2));
	SetDamageMin(this->strenght - 2);
	SetDamageMax(this->strenght * 2);
	SetDefence((this->agility * 2) / (this->luck - 2));
}

Player::~Player()
{
}

void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "--------------------" << std::endl;
	std::cout << "Strenght: " << this->strenght << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
}
#include "Character.h"

Character::Character()
{
	this->name = "";
	this->level = 0;
	this->hp = 0;
	this->exp = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
}

Character::~Character()
{

}

void Character::InitCharacter(std::string n)
{
	this->name = n;
}

void Character::PrintStats()
{
	std::cout << "----" << this->name << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "HP: " << this->hp << std::endl;
	std::cout << "Exp: " << this->exp << std::endl;
	std::cout << "Damage: " << this->damageMin << "/" << this->damageMax << std::endl;
	std::cout << "Defence: " << this->defence << std::endl;
}

void Character::TakeDamage(int d)
{
	this->hp -= d;
}

const int Character::DoDamage()
{
	int Damage = (rand() % (this->damageMax - this->damageMin + 1)) + this->damageMin;
	std::cout << "hit with " << Damage << " damage" << std::endl;
	return Damage;
}

bool Character::IsAlive()
{
	return (this->hp > 0);
}

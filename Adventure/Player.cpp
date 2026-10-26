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
	this->MaxEXP = 10;
}

Player::~Player()
{
}

void Player::LevelUp()
{
	while (GetEXP() >= MaxEXP)
	{
		SetExp(GetEXP() - MaxEXP);
		SetLevel(GetLevel() + 1);
		MaxEXP = GetLevel() * 10;
		SkillPoints++;
	}
	if (GetEXP() < MaxEXP)
	{
		std::cout << "Not Enough EXP" << std::endl;
	}
}

void Player::AddStats(int stat, int value)
{
	if (SkillPoints < value)
	{
		
	}
	else
	{
		switch (stat)
		{
		case 1:
			this->strenght += value;
			SkillPoints -= value;
			UpdateValues();
			break;
		case 2:
			this->agility += value;
			SkillPoints -= value;
			UpdateValues();
			break;
		case 3:
			this->intelligence += value;
			SkillPoints -= value;
			UpdateValues();
			break;
		case 4:
			this->luck += value;
			SkillPoints -= value;
			UpdateValues();
			break;
		case 5:
			this->dexterity += value;
			SkillPoints -= value;
			UpdateValues();
			break;
		default:
			std::cout << "This stat does not exist" << std::endl;
			break;
		}
	}
}

void Player::UpdateValues()
{
	SetHP((this->intelligence * 2) / (this->dexterity - 2));
	SetDamageMin(this->strenght - 2);
	SetDamageMax(this->strenght * 2);
	SetDefence((this->agility * 2) / (this->luck - 2));
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
	std::cout << "Exp for the next level: " << this->MaxEXP << std::endl;
}
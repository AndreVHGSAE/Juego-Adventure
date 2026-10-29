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

void Player::LoadStats(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		return;
	}
	std::string name = "";
	int l;
	int hp;
	int xp;
	int maxXp;
	int dmin;
	int dmax;
	int d;
	//std::getline(inFile, name);
	inFile >> name
		>> l
		>> xp
		>> hp
		>> dmax
		>> dmin
		>> d
		>> strenght
		>> agility
		>> intelligence
		>> luck
		>> dexterity
		>> SkillPoints
		>> maxXp;
	inFile.close();

	SetLevel(l);
	SetHP(hp);
	SetExp(xp);
	SetDamageMin(dmin);
	SetDamageMax(dmax);
	SetDefence(d);
}

std::string Player::SaveStats()
{
	return this->GetName() + " " +
		std::to_string(this->GetLevel()) + " " +
		std::to_string(this->GetEXP()) + " " +
		std::to_string(this->GetHP()) + " " +
		std::to_string(this->GetDamageMin()) + " " +
		std::to_string(this->GetDamageMax()) + " " +
		std::to_string(this->GetDefence()) + " " +
		std::to_string(this->GetStrenght()) + " " +
		std::to_string(this->GetAgility()) + " " +
		std::to_string(this->GetIntelligence()) + " " +
		std::to_string(this->GetLuck()) + " " +
		std::to_string(this->GetDexterity()) + " " +
		std::to_string(this->GetSkillPoints()) + " " +
		std::to_string(this->GetMaxEXP()) + " ";
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
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(std::string name, int l, int hp, int damage, int defence, int exp, int modifier)
{
	if (modifier <= 0)
		modifier = 1;
	InitCharacter(name);
	SetLevel(l);
	SetHP(hp * modifier);
	SetDamageMin(damage / 2);
	SetDamageMax(damage * 2);
	SetDefence(defence);
	SetExp(exp * modifier);
}

Enemy::~Enemy()
{
}

void Enemy::InitEnemy()
{
}

void Enemy::PrintEnemyStats()
{
	PrintStats();
}

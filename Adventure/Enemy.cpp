#include "Enemy.h"

Enemy::Enemy(std::string name, int l, int hp, int damage, int defence, int exp)
{
	InitCharacter(name);
	SetLevel(l);
	SetHP(hp);
	SetDamageMin(damage / 2);
	SetDamageMax(damage * 2);
	SetDefence(defence);
	SetExp(exp);
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

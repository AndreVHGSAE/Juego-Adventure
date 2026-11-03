#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"

class Event
{
private:
	int numOfEvents;
	Enemy* baseEnemy;
	Enemy* Enemy1;
	Enemy* Enemy2;
	Enemy* Enemy3;
public:
	Event();
	~Event();
	
	Enemy * GetRandomEnemy(Player& p);

	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p);

};


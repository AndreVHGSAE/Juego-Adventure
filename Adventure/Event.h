#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Revuelto.h"
#include "Ahorcado.h"
#include "Gato.h"

class Event
{
private:
	int numOfEvents;
	Enemy* baseEnemy;
public:
	Event();
	~Event();
	
	Enemy * GetRandomEnemy(Player& p);

	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p);

};


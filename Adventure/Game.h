#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
class Game
{
private:
	Player player;
	Enemy* enemy;
	int choice;
	bool playing;
public:
	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	bool GetPlaying();
};


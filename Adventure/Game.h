#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Event.h"
#include <fstream>
class Game
{
private:
	Player player;
	Enemy* enemy;
	Event v;
	int choice;
	bool playing;
public:
	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void LevelUp();
	void SkillUp();

	void Travel();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	bool GetPlaying();
};


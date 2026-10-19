#include "Game.h"


Game::Game()
{
	this->playing = true;
}

Game::~Game()
{

}

void Game::InitGame()
{
	std::cout << "Starting the game" << std::endl;
	NewPlayer();
}

void Game::mainMenu()
{
	std::cout << "-----------MAIN MENU-----------" << std::endl;
	std::cout << " 0: Quit Game" << std::endl;
	std::cout << " 1: Player Stats" << std::endl;
	std::cout << " 2: Enemy Stats" << std::endl;
	
	std::cout << "Enter Choice" << std::endl;
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::SavePlayer()
{

}

void Game::LoadPlayer()
{

}

void Game::NewPlayer()
{
	player.InitPlayer("Warcogro");
}

void Game::NewEnemy()
{
	srand(static_cast<unsigned int>(time(0)));
	std::string name = "slime";
	int level = (rand() % 10 - 1 + 1);
	int damage = (rand() % 100 - 1 + 1);
	int hp = (rand() % 100 - 1 + 1);
	int xp = (rand() % 1000 - 1 + 1);
	int defence = (rand() % 50 - 1 + 1);
	enemy = new Enemy(name, level, hp, damage, defence, xp);
	enemy->PrintEnemyStats();
}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}

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
	std::cout << " 3: Travel" << std::endl;
	std::cout << " 4: Level Up" << std::endl;
	std::cout << " 5: Skill Up" << std::endl;
	std::cout << " 6: Save Game" << std::endl;
	std::cout << " 7: Load Game" << std::endl;
	
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
	case 3:
		Travel();
		break;
	case 4:
		LevelUp();
		break;
	case 5:
		SkillUp();
		break;
	case 6:
		SavePlayer();
		break;
	case 7:
		LoadPlayer();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::LevelUp()
{
	player.LevelUp();
}

void Game::SkillUp()
{
	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints()
			<< " point(s) to use" << std::endl;
		std::cout << "--------Stats--------" << std::endl;
		std::cout << " 1: Strenght" << std::endl;
		std::cout << " 2: Agility" << std::endl;
		std::cout << " 3: Intelligence" << std::endl;
		std::cout << " 4: Luck" << std::endl;
		std::cout << " 5: Dexterity" << std::endl;
		std::cin >> choice;
		player.AddStats(choice, 1);
	}
	if (player.GetSkillPoints() <= 0)
	{
		std::cout << "Not Enough Points" << std::endl;
	}
}

void Game::Travel()
{
	v.GenerateEvent(player);
}

void Game::SavePlayer()
{
	std::string fileName;
	std::ofstream outFile("savePlayer.txt");
	if (outFile.is_open())
	{
		outFile << player.SaveStats() << " ";
	}
	else
	{
		std::cout << "An error occured, wasn't able to save" << std::endl;
	}
	outFile.close();
	std::cout << "Game succesfully saved" << std::endl;
}

void Game::LoadPlayer()
{
	std::string fileName = "savePlayer.txt";
	player.LoadStats(fileName);
	std::cout << "Game succesfully loaded" << std::endl;
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
	int damage = (rand() % 10 - 1 + 1);
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

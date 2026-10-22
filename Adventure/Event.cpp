#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;
	switch (i)
	{
	case 7:
		std::cout << "Keep traveling..." << std::endl;
		break;
	case 5:
		std::cout << "Puzzle Encounter" << std::endl;
		break;
	default:
		std::cout << "Enemy Encounter" << std::endl;
		EnemyEncounter(p);
		break;
	}
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool escaped = false;
	bool playerTurn = false;
	bool playerDefend = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 - p.GetLuck())
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "------New Enemy Encounter------" << std::endl;

	int level = p.GetLevel();
	int hp = level * 10;
	int damageMin = (rand() % level + 1);
	int damageMax = (rand() % level + 1)*2;
	int currentDamage = rand() / (damageMax - damageMin + 1);
	int defence = rand() % level;
	int exp = rand() % level * 10;
	baseEnemy = new Enemy("Duende", level, hp, currentDamage, defence, exp);
	while (!playerDefeated || !enemyDefeated || !escaped)
	{
		if (playerTurn)
		{
			std::cout << "----------PLAYER TURN----------" << std::endl;
			std::cout << "Choose your action" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;
			std::cout << "0: Escape" << std::endl;

			std::cin >> choice;
			int escapeRand = 0;
			int attackRoll = 0;
			switch (choice)
			{
			case 0:
				escapeRand = (rand() % 100) + p.GetLuck();
				if (escapeRand > 25)
				{
					std::cout << "Escaped..." << std::endl;
					escaped = true;
				}
				break;
			case 1:
				std::system("cls");
				attackRoll = rand() % 100 + 1;
				if (attackRoll > (50 - p.GetStrenght()))
				{
					std::cout << "Player hit Enemy" << std::endl;
					baseEnemy->TakeDamage(p.DoDamage());
				}
				break;
			case 2:
				playerDefend = true;
				break;
			case 3:
				p.PrintPlayerStats();
				break;
			case 4:
				baseEnemy->PrintStats();
				break;
			default:
				std::cout << "Invalid Option" << std::endl;
				break;
			}
			playerTurn = false;
		}
		else
		{
			std::cout << "----------ENEMY TURN----------" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy Defeated" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetEXP() << std::endl;
			}
			else
			{
				int enemyAttackRoll = rand() % 100 + 1;
				if (playerDefend)
				{
					if (enemyAttackRoll > 75)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;
					}
				}
				else
				{
					if (enemyAttackRoll > 45)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;
					}
				}
			}
			playerTurn = true;
		}
	}
}

void Event::PuzzleEncounter(Player& p)
{
}

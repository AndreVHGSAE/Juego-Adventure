#include "Event.h"


Event::Event()
{
}

Event::~Event()
{
}

Enemy* Event::GetRandomEnemy(Player& p)
{
	int level = p.GetLevel();
	int hp = level;
	int currentDamage = (rand() % p.GetDamageMin() + 1);
	int defence = rand() % level;
	int exp = level*3;
	int modifier = (p.GetLevel()/10)+1;
	
	int RE = rand() % 3 + 1;
	switch (RE)
	{
	case 1:
		return new Enemy("Duende", level, hp+10, currentDamage, defence, exp*2, modifier);
	case 2:
		return new Enemy("Ogro", level+1, hp+15, currentDamage*1.2f, defence+1, exp*3, modifier+0.1f);
	case 3:
		return new Enemy("Dragon", level+2, hp+30, currentDamage*1.5f, defence+2, exp*5, modifier+0.2);
	default:
		std::cout << "Not possible" << std::endl;
		break;
	}
	return nullptr;
}

void Event::GenerateEvent(Player& p)
{
	std::system("cls");
	srand(static_cast<unsigned int>(time(0)));
	//int RT = 6;
	int RT = rand() % 10;
	int i = 0;
	if (RT > 8)
	{
		i = 1;
	}
	else if (RT > 6)
	{
		i = 2;
	}
	else if (RT > 4)
	{
		i = 3;
	}
	else
	{
		i = 0;
	}
	int heal = (rand() % 15 + 5);
	switch (i)
	{
	case 1:
		std::cout << "Keep traveling..." << std::endl;
		break;
	case 2:
		PuzzleEncounter(p);
		break;
	case 3:
		std::cout << "HP Healing Hotspring" << std::endl;
		std::cout << "You healed " << heal << " HP!" << std::endl;
		p.TakeDamage(-heal);
		break;
	default:
		EnemyEncounter(p);
		break;
	}
}

void Event::EnemyEncounter(Player& p)
{
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

	baseEnemy = GetRandomEnemy(p);

	

	while (!playerDefeated && !enemyDefeated && !escaped)
	{
		if (playerTurn)
		{
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "ENEMY DEFEATED" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetEXP() << std::endl;
				p.AddExp(baseEnemy->GetEXP());
				return;
			}
			if (!p.IsAlive())
			{
				playerDefeated = true;
				std::cout << "YOU LOST" << std::endl;
				std::cout << "Resseting to last save" << std::endl;
				p.LoadStats("savePlayer.txt");
				return;
			}
			
			p.PrintPlayerStats();
			baseEnemy->PrintStats();
			
			std::cout << "----------PLAYER TURN----------" << std::endl;
			std::cout << "Choose your action" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Heal" << std::endl;
			std::cout << "0: Escape" << std::endl;

			std::cin >> choice;
			int escapeRand = 0;
			int attackRoll = 0;

			int heal = (rand() % 15 + 5);

			std::system("cls");

			switch (choice)
			{
			case 0:
				escapeRand = (rand() % 100) + p.GetLuck();
				if (escapeRand > 25)
				{
					std::cout << "Escaped..." << std::endl;
					escaped = true;
				}
				else
				{
					std::cout << "Couldn't escape" << std::endl;
				}
				break;
			case 1:
				attackRoll = rand() % 100 + 1;
				if (attackRoll > (50 - p.GetStrenght()))
				{
					std::cout << "Player ";
					baseEnemy->TakeDamage(p.DoDamage());
				}
				else
				{
					std::cout << "Player miss Enemy" << std::endl;
				}
				break;
			case 2:
				playerDefend = true;
				break;
			case 3:
				std::cout << "You healed " << heal << " HP!" << std::endl;
				p.TakeDamage(-heal);
				break;
			case 4:
				std::cout << "You did nothing" << std::endl;
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
				std::cout << "ENEMY DEFEATED" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetEXP() << std::endl;
				p.AddExp(baseEnemy->GetEXP());
				return;
			}
			if (!p.IsAlive())
			{
				playerDefeated = true;
				std::cout << "YOU LOST" << std::endl;
				std::cout << "Resseting to last save" << std::endl;
				p.LoadStats("savePlayer.txt");
				return;
			}
			else
			{
				int enemyAttackRoll = rand() % 100 + 1;
				if (playerDefend)
				{
					if (enemyAttackRoll > 75)
					{
						std::cout << "Enemy ";
						p.TakeDamage(baseEnemy->DoDamage()-p.GetDefence());
						std::cout << "But the player defended, so the damage is mitigated by defense stat" << std::endl;
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
						std::cout << "Enemy ";
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
	Revuelto r = Revuelto();
	Ahorcado a = Ahorcado();
	Gato g = Gato();
	
	std::system("cls");
	std::cout << "------Puzzle Encounter------" << std::endl;
	std::cout << "Solve the minigame to get EXP Reward!" << std::endl;

	int RP = rand() % 3 + 1;
	//int RP = 3;
	switch (RP)
	{
	case 1:
	{
		std::cout << "------Word Scramble------" << std::endl;
		int Reward = r.RevueltoGame();
		std::cout << "You got " << Reward << " XP!" << std::endl;
		p.AddExp(Reward);
		break;
	}
	case 2:
	{
		std::cout << "------Word Guess------" << std::endl;
		int Reward = a.AhorcadoGame();
		std::cout << "You got " << Reward << " XP!" << std::endl;
		p.AddExp(Reward);
		break;
	}
	case 3:
	{
		std::cout << "------Tic-tac-toe------" << std::endl;
		int Reward = g.GatoGame();
		std::cout << "You got " << Reward << " XP!" << std::endl;
		p.AddExp(Reward);
		break;
	}
	default:
	{
		std::cout << "Not possible" << std::endl;
		break;
	}
	}
}

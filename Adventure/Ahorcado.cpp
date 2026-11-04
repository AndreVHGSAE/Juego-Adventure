#include "Ahorcado.h"
// Ahorcado Clase 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


Ahorcado::Ahorcado()
{
}

int Ahorcado::AhorcadoGame()
{
    words.push_back("DREAM");
    words.push_back("WARCOS");
    words.push_back("HIPOPOTAMUS");
    words.push_back("PENCIL");
    words.push_back("HEADPHONES");
    
    std::cout << "Word Guess" << std::endl;
    std::cout << "Guess the  word without failing 5 times" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(words.begin(), words.end());

    const std::string theWord = words[0];
    std::string wordToGuess(theWord.size(), '_');
    std::string used = "";

    while (wordToGuess != theWord && Lives > 0)
    {
        std::cout << "you used this letters: " << used << std::endl;
        std::cout << "Lives left: " << Lives << std::endl;
        std::cout << wordToGuess << std::endl;
        char lettertoGuess;
        std::cin >> lettertoGuess;
        NumGuesses++;
        lettertoGuess = std::toupper(lettertoGuess);

        if (theWord.find(lettertoGuess) != std::string::npos)
        {
            for (int i = 0; i < theWord.size(); i++)
            {
                if (theWord[i] == lettertoGuess)
                {
                    wordToGuess[i] = lettertoGuess;
                }
            }
        }
        else
        {
            used += lettertoGuess;
            Lives--;
            std::cout << "Not in the word" << std::endl;

        }
    }

    std::cout << "------------------------------------------------------" << std::endl;

    if (Lives <= 0)
    {
        std::cout << "Game Over" << std::endl;
    }
    else
    {
        std::cout << "You won!" << std::endl;
        std::cout << "With " << NumGuesses << " guesses" << std::endl;
    }
    Lives * 5;
    return Lives;
}




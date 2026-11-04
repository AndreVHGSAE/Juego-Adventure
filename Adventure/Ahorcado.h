#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Ahorcado
{
public:
    Ahorcado();
    int AhorcadoGame();
private:
    std::vector <std::string> words;

    int Lives = 5;
    int NumGuesses = 0;
};


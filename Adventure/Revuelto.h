#pragma once
#include <iostream>
using namespace std;

class Revuelto
{
public:
	int RevueltoGame();
	Revuelto();
private:
	int score;
	int turn;
	enum Fields { WRD, HINT, NUM_FIELDS };
	string wordsHint[3][NUM_FIELDS]
	{
	{"Mouse","It's a small animal."},
	{"Videogame","It's something digital you play"},
	{"Blue","A cold color you associate with water"}
	};


};


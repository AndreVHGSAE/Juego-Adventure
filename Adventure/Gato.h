#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Gato
{
public:
	Gato();
	int GatoGame();
	
	void Instructions();
	void DisplayBoard(const std::vector<char>* board);

	int MovePlayer(std::vector<char> board);
	int MoveCPU(std::vector<char> board, char piece);

	char Winner(std::vector<char> board);

	char PlayerPiece();
	char CPUPiece(char piece);

	bool IsEmpty(int pos, const std::vector<char>* board);


private:
	
	static constexpr char EMPTY = ' ';
	static constexpr char X = 'X';
	static constexpr char O = 'O';
	static constexpr char TIE = 'T';
	static constexpr char NOTIE = 'N';

	static constexpr int NUM_SPACE = 9;

};


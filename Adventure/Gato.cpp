#include "Gato.h"


Gato::Gato()
{
}

int Gato::GatoGame()
{
    
    Instructions();

    std::vector<char> board(NUM_SPACE, EMPTY);
    DisplayBoard(&board);
    char human = PlayerPiece();
    char CPU = CPUPiece(human);
    char turn = X;

    std::cout << "Player use: " << human << " CPU use: " << CPU << std::endl;

    while (Winner(board) == NOTIE)
    {
        if (turn == human)
        {
            board[MovePlayer(board)] = human;
        }
        else
        {
            board[MoveCPU(board, CPU)] = CPU;
        }
        if (turn == X)
            turn = O;
        else
            turn = X;

        DisplayBoard(&board);
    }
    
    char result = Winner(board);

    if (result == human)
    {
        std::cout << "You won the game!" << std::endl;
        return 10;
    }
    else if (result == CPU)
    {
        std::cout << "You lost" << std::endl;
        return 0;
    }
    else if (result == TIE)
    {
        std::cout << "It's a tie" << std::endl;
        return 5;
    }

}

void Gato::Instructions()
{
    std::cout << "You will play against an opponent in tic-tac-toe" << std::endl;
    std::cout << "First you will choose if you will go first or not" << std::endl;
    std::cout << "Then when it's your turn enter the number of the tile you want" << std::endl;
    std::cout << "The tile each number represents is shown below this instructions" << std::endl;
    std::cout << "Don't put a number that's not a tile or the program will crash" << std::endl;
    std::cout << "Your objective is lining 3 of your pieces up to win" << std::endl;
    std::cout << "If the opponent lines 3 of their pieces up you lose" << std::endl;

    std::cout << std::endl;
    std::cout << "0" << "|" << "1" << "|" << "2" << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << "3" << "|" << "4" << "|" << "5" << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << "6" << "|" << "7" << "|" << "8" << std::endl;
    std::cout << std::endl;
}

void Gato::DisplayBoard(const std::vector<char>* board)
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << (*board)[0] << "|" << (*board)[1] << "|" << (*board)[2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << (*board)[3] << "|" << (*board)[4] << "|" << (*board)[5] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << (*board)[6] << "|" << (*board)[7] << "|" << (*board)[8] << std::endl;
    std::cout << std::endl;
}

int Gato::MovePlayer(std::vector<char> board)
{
    int move;
    std::cout << "Where do you want to put your piece?" << std::endl;
    std::cin >> move;
    while (!IsEmpty(move, &board))
    {
        std::cout << "Is already occupied" << std::endl;
        std::cin >> move;
    }

    return move;
}

int Gato::MoveCPU(std::vector<char> board, char piece)
{
    std::vector<char> testBoard = board;
    const char oponent = (piece == 'X') ? 'O' : 'X'; //Esto es un if mas simplificado

    static const int bestMove[] = { 4,0,2,6,8,1,3,5,7 };
    int i = 0;
    int move = 0;
    bool found = false;

    while (!found && move < board.size())
    {
        if (IsEmpty(move, &board))
        {
            board[move] = oponent;
            found = (Winner(board)) == oponent;
            board[move] = EMPTY;
        }
        if (!found)
            move++;
    }

    while (!found && move < board.size())
    {
        if (IsEmpty(move, &board))
        {
            board[move] = piece;
            found = (Winner(board)) == piece;
            board[move] = EMPTY;
        }
        if (!found)
            move++;
    }
    if (!found)
    {
        move = 0;
        while (i < board.size())
        {
            move = bestMove[i];
            if (IsEmpty(move, &board))
            {
                return move;
            }
            i++;
        }
    }
    return move;
}

char Gato::Winner(std::vector<char> board)
{
    const int WINNING_ROWS[8][3] =
    {
        { 0,1,2 },
        { 3,4,5 },
        { 6,7,8 },
        { 0,3,6 },
        { 1,4,7 },
        { 2,5,8 },
        { 0,4,8 },
        { 2,4,6 }
    };

    for (int i = 0; i < 8; i++)
    {
        if (board[WINNING_ROWS[i][0]] != EMPTY &&
            board[WINNING_ROWS[i][0]] == board[WINNING_ROWS[i][1]] &&
            board[WINNING_ROWS[i][1]] == board[WINNING_ROWS[i][2]])
        {
            return board[WINNING_ROWS[i][0]];
        }
    }
    if (std::count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;
    else
        return NOTIE;
}

char Gato::PlayerPiece()
{
    std::cout << "You go first" << std::endl;

        return X;
}

char Gato::CPUPiece(char piece)
{
    if (piece == X)
        return O;
    else
        return X;
}

bool Gato::IsEmpty(int pos, const std::vector<char>* board)
{
    return ((*board)[pos] == EMPTY);
}



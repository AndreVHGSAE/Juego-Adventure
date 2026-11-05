#include "Revuelto.h"

Revuelto::Revuelto()
{
}

    int Revuelto::RevueltoGame()
    {
        int turn = 0;
        int score = 0;
        cout << "Let's play a word guessing name " << endl;
        cout << "START " << endl;
        string guess = "";
        while (turn <= 4)
        {
            srand(static_cast<unsigned int>(time(0)));
            int value = (rand() % 3);
            string wrd = wordsHint[value][WRD];
            string hint = wordsHint[value][HINT];

            string s = wrd;
            int lenght = (int)s.size();

            for (int i = 0; i < lenght; i++)
            {
                int a = (rand() % lenght);
                int b = (rand() % lenght);

                char tmp = s[a];
                s[a] = s[b];
                s[b] = tmp;
            }
            cout << s << endl;
            cin >> guess;
            if (guess == "hint")
            {
                cout << hint << endl;
            }
            else if (guess != wrd)
            {
                cout << "not the word" << endl;
            }
            if (wrd == guess)
            {
                score++;
                cout << "You guessed it!" << endl << "Score: " << score << endl;
            }
            guess = "";
            turn++;    
        }
        score = score * 2;
        return score;
    }



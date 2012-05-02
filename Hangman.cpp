#include "Hangman.h"

using namespace std;

string guessed = "";
string board;
string HangWord;
char guess;
int gmax = 0;
char HangmanArray[7][6] = {{' ','_','_','_','_',' '},
						   {' ','|',' ',' ','|',' '},
						   {' ','|',' ',' ',' ',' '},
						   {' ','|',' ',' ',' ',' '},
						   {' ','|',' ',' ',' ',' '},
						   {' ','|',' ',' ',' ',' '},	
						   {'_','|','_','_','_',' '}};

void ArraySet()
{
	if(gmax == 1)
		HangmanArray[2][4] = 'O';
	else if(gmax == 2)
		HangmanArray[3][4] = '|';
	else if(gmax == 3)
		HangmanArray[4][4] = '|';
	else if(gmax == 4)
		HangmanArray[5][3] = '/';
	else if(gmax == 5)
		HangmanArray[5][5] = '\\';
	else if(gmax == 6)
		HangmanArray[2][3] = '\\';
	else if(gmax == 7)
		HangmanArray[2][5] = '/';
}
					
void CrudeClear()
{
	for (int i = 0; i < 50; i++)
		cout << endl;
}

void Reset()
{
	HangWord = "";
	board = "";
	guessed = "";
	CrudeClear();
	gmax = 0;

	HangmanArray[2][4] = ' ';
	HangmanArray[3][4] = ' ';
	HangmanArray[4][4] = ' ';
	HangmanArray[5][3] = ' ';
	HangmanArray[5][5] = ' ';
	HangmanArray[2][3] = ' ';
	HangmanArray[2][5] = ' ';
}

void PrintBoard()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << HangmanArray[i][j];
		cout << endl;
	}
	cout << "\n\n";
	for (unsigned int i = 0; i < board.length(); i++)
	{
		if(board[i] == ' ')
			cout << " ";
		else if (board[i] == '_')
			cout << "_ ";
		else
			cout << board[i] << " ";
	}
}

bool CheckBoard()
{
	for (unsigned int i = 0; i < board.length(); i++)
	{
		if(board[i] == '_')
			return false;
	}
	return true;
}

void AddToGuessed()
{
	int trigger = 0;
	for (unsigned int i = 0; i < guessed.length(); i++)
	{
		if (guessed[i] == guess)
			trigger = 1;
	}
	if (trigger == 0)
	{
		guessed += guess;
		gmax++;
	}
}

void Guess()
{
	int counter = 0;
	for (unsigned int i = 0; i < board.length(); i++)
	{
		if(HangWord[i] == guess)
		{
			board[i] = guess;
			counter ++;
		}
		else if (HangWord[i] == guess - ' ')
		{
			board[i] = guess - ' ';
			counter ++;
		}
		else if(HangWord[i] == guess + ' ')
		{
			board[i] = guess + ' ';
			counter ++;
		}
	}
	if (counter == 0)
		AddToGuessed();
	ArraySet();

	}

bool checkword(string word)
{
	unsigned int i = 0;
	if (word.length() == 0) return false;
		while(i < word.length())
		{
			if(word[i] != ' ')
				if(!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
					return false;
			i++;
		}
	return true;

}

void InitialWord()
{
	while(1)
	{
		cout << "Welcome to Hangman! Please enter a word or phrase: " << endl;
		getline(cin, HangWord);
		if(checkword(HangWord))
		{
			break;
		}
		else
		{
			CrudeClear();
			cout << "Bad input. Use at least one letter and no other symbols." << endl;
		}
	}
}

void TheGame()
{
	while(1)
	{
		InitialWord();
		CrudeClear();
		for (unsigned int i = 0; i < HangWord.length(); i++)
		{
			if(HangWord[i] == ' ')
				board += ' ';
			else
				board += '_';
		}
		PrintBoard();
		cout << endl;

		while (!CheckBoard())
		{
			cout << "Enter a letter: " << endl;
			cin >> guess;
			if ((guess >= 'A' && guess <= 'Z') || (guess >= 'a' && guess <= 'z'))
			{
				CrudeClear();
				Guess();
				PrintBoard();
				cout << "\n\n" << "Wrong Guesses: " << guessed << endl << endl;
			}
			else
				cout << "You must enter a valid letter." << endl;
			if (gmax >= 7)
				break;
		}
		if (gmax >= 7)
			cout << "LOSER! Press enter to play again." << endl;
		else
			cout << "WINNER! Press enter to play again." << endl;
		cin.get();
		cin.get();
		Reset();

	}
}
			
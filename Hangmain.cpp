#include <iostream>
#include <string>

using namespace std;
string guessed = "";
string board;
string HangWord;
char guess;
int gmax = 0;

void Reset()
{
	HangWord = "";
	board = "";
	guessed = "";
	system("CLS");
	gmax = 0;
}

void PrintBoard()
{
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

}
bool checkword(string word)
{
	unsigned int i = 0;
	if (word.length() == 0) return false;
	while(i < word.length())
	{
		if(!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))) 
			return false;
		i++;
	}
	return true;

}

int main()
{
	while(1)
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
					system("CLS");
					cout << "Bad input.  Use at least one letter and no other symbols." << endl;
				}
			}
			system("CLS");
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
					system("CLS");
					Guess();
					PrintBoard();
					cout << endl << guessed << endl;
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
		return 0;
}
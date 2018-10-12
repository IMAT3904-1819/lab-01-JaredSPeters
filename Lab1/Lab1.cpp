// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int randomValue, userGuess, remainingGoes;
void ChooseRandom();
bool CheckNumber(int number);

int main()
{
	srand(time(NULL)); //Seed rand

	remainingGoes = 5;

	ChooseRandom();
	cout << "Number is between 1 and 100 - you have 5 guesses!" << endl;
	cin >> userGuess;

	while (!CheckNumber(userGuess))
	{
		cin >> userGuess;
	}

	system("PAUSE");
    return 0;
}

void ChooseRandom()
{
	randomValue = rand() % 100 + 1;
	cout << "Random value chosen..." << endl;
}

bool CheckNumber(int number)
{
	remainingGoes--;

	if (remainingGoes != 0)
	{
		if (number < randomValue)
		{
			cout << "Higher! Make a new guess..." << endl;
			return false;
		}
		else if (number > randomValue)
		{
			cout << "Lower! Make a new guess..." << endl;
			return false;
		}
	}

	if (number == randomValue)
	{
		cout << "You guessed it! The number was " << number << "!" << endl;
		return true;
	}

	cout << "You've run out of goes! GAME OVER" << endl;
	return true;
}


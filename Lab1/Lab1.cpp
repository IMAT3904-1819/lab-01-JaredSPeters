// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int randomValue, userGuess, remainingGoes;
void ChooseRandom(), GetUserInput();
bool CheckNumber(int number);

int main()
{
	srand(time(NULL)); //Seed rand

	remainingGoes = 5;

	ChooseRandom();
	cout << "Number is between 1 and 100 - you have 5 guesses!" << endl;
	GetUserInput();

	while (!CheckNumber(userGuess))
	{
		GetUserInput();
	}

	system("PAUSE");
    return 0;
}

void GetUserInput()
{
	cout << "Remaining goes: " << remainingGoes << endl;

	cin >> userGuess;

	if (!cin) //If input is not valid (not int)
	{
		cin.clear(); //Reset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Remove last input
		cout << "INVALID INPUT. Please choose a NUMBER: " << endl;
		GetUserInput(); //Recursion
	}
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
	cout << "The number was " << randomValue << endl;
	return true;
}


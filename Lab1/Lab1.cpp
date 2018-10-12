// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int randomValue, userGuess;
void ChooseRandom();
bool CheckNumber(int number);

int main()
{
	srand(time(NULL)); //Seed rand

	ChooseRandom();
	cout << "Number is 1 to 100. Make a guess!" << endl;
	cin >> userGuess;

	while (!CheckNumber(userGuess))
	{
		cin >> userGuess;
	}

	cout << "You did it yay!" << endl;

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
	else if (number == randomValue)
	{
		cout << "You guessed it! The number was " << number << "!" << endl;
		return true;
	}
}


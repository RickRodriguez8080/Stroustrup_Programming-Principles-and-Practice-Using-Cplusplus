// guessing_game.cpp
// Ricardo Rodriguez
// This program will try to identify a users number from 1 to 100
// in 7 guesses or less.

#include "../../../std_lib_facilities.h"

int main()
{
	
	const int MAX_VALUE = 100;
	const int MIN_VALUE = 1;
	
	int high = MAX_VALUE;
	int low = MIN_VALUE;
	int guess = high / 2;
	bool correct_guess = false;
	string response = "";

	cout << "Is your guess higher or lower than " << guess << "?\n"
		<< "(type in all lowercase): ";
	cin >> response;

	if (response != "higher" && response != "lower")
	{
		cout << "Are you sure you entered a response correctly?\n";
		correct_guess = true;
	}
	
	while (correct_guess == false)
	{		
		if (response == "higher")
		{
			low = guess + 1;
			guess = (high + low) / 2;
			
			if (high == low)
			{
				break;
			}
		}
		else if (response == "lower")
		{
			high = guess - 1;
			guess = (high + low) / 2;

			if (high == low)
			{
				break;
			}
		}
		else
		{
			break;
		}

		cout << "Is your guess higher or lower than " << guess << "?\n"
			<< "(type in all lowercase): ";
		cin >> response;
	}

	cout << "Your number is " << guess;

	return 0;
}

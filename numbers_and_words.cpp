// numbers_and_words.cpp
// Ricardo Rodriguez
// Ch4 Exercise 6
// Type in a digit and its word form will be given
// Type the word form of a number and its digit will be given

#include "std_lib_facilities.h"

// function declarations

// This function will take an integer and, if the integer is between
// 0 and 9, inclusive, it will return the word form of that digit.
// Otherwise, it will return an error in the form of a string.
void wordform(int number);

// This function will take a string and compare it to the digits
// 0 thru 9.  If the string is one of those digits, it will return
// the digit.  Otherwise it will return -1.
void digit(string word);

int main()
{
	string word = " ";
	int number = 0;
	char response = 'y';

	while (response == 'y')
	{
		cout << "Please type if you are entering a number as a digit or a word (type \"digit\" or \"word\"): ";
		string input;
		cin >> input;

		while (input != "digit" && input != "word")
		{
			cout << "Unknown response. Please try again: ";
			cin >> input;
		}

		if (input == "digit")
		{
			cout << "Enter a digit (from 0 to 9) and I will display its word form: ";
			cin >> number;
			wordform(number);
		}
		else
		{
			cout << "Enter a number (from zero to nine) and I will display it as a digit: ";
			cin >> word;
			digit(word);
		}

		cout << "Would you like to try again? (y or n): ";
		cin >> response;
	}

	return 0;
}

// function definitions
void wordform(int number)
{
	vector<string> word_form = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int i = 0;
	while (i < word_form.size()) // As you traverse the vector...
	{
		if (i == number) // If "i" is the same as the number parameter...
		{
			cout << "You entered " << word_form[i] << ".\n"; // print the word version of that number
			break;
		}
		++i;
	}
}

void digit(string word)
{
	vector<string> word_form = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<int> standard_form = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	
	while (i < word_form.size()) // as you traverse the word_form vector...
	{
		if (word == word_form[i]) // Check the word parameter against the string in the word_form element
		{
			cout << "You entered " << standard_form[i] << ".\n";  // display the digit of the inputted string
			break;
		}
		++i;
	}
}

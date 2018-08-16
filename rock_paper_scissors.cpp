// rock_paper_scissors.cpp
// Ricardo Rodriguez
// Ch 4, Exercise #10

/*
This program will play rock, paper, scissors.  The program
has a 5 vectors that play differently to show an illusion
of randomness.
*/

#include "../../../std_lib_facilities.h"

// function declaration(s)

vector<string> game_number(int number);
void game_play(vector<string> game_number);

int main()
{
	cout << "Paper, Rock, Scissors\n"
		<< "*********************\n\n"
		<< "Please enter a game number (1, 2, 3, 4, or 5): ";

	int input;
	cin >> input;
	
	vector<string> game = game_number(input);

	while (game[0] == "Unknown game.")
	{
		cout << game[0] << " Try again.\n";
		cin >> input;
		vector<string> game = game_number(input);
	}

	char response = 'y';

	while (response == 'y')
	{
		game_play(game);

		cout << "Play again? (y OR n): ";
		cin >> response;
	}
	return 0;
}

vector<string> game_number(int number)
{
	vector<string> game_1 = { "rock", "paper", "scissors", "rock", "scissors", "paper", "rock", "paper", "scissors", "rock" };
	vector<string> game_2 = { "paper", "paper", "paper", "rock", "scissors", "rock", "scissors", "rock", "scissors", "paper" };
	vector<string> game_3 = { "rock", "paper", "rock", "rock", "scissors", "paper", "scissors", "scissors", "scissors", "rock" };
	vector<string> game_4 = { "scissors", "scissors", "scissors", "scissors", "paper", "paper", "paper", "rock", "rock", "rock" };
	vector<string> game_5 = { "paper", "rock", "paper", "scissors", "scissors", "rock", "paper", "paper", "scissors", "rock" };
	vector<string> chosen_game;
	
	switch (number)
	{
		case 1:
			chosen_game = game_1;
			break;
		case 2:
			chosen_game = game_2;
			break;
		case 3:
			chosen_game = game_3;
			break;
		case 4:
			chosen_game = game_4;
			break;
		case 5:
			chosen_game = game_5;
			break;
		default:
			chosen_game[0] = "Unknown game.";
			break;
	}
	return chosen_game;
}

void game_play(vector<string> game_number)
{
	char input = 'n';
	int user_counter = 0;
	int computer_counter = 0;

	for (int i = 0; i < game_number.size(); ++i)
	{
		cout << "Press 'r' for rock, 'p' for paper, and 's' for scissors:\n";
		cin >> input;

		switch (input)
		{
			case 'r':

				cout << "You entered rock.\n";
				if (game_number[i] == "rock")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "Tie.\n";
				}
				else if (game_number[i] == "paper")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You lose.\n";
					++computer_counter;
				}
				else
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You win.\n";
					++user_counter;
				}
				break;

			case 'p':

				cout << "You entered paper.\n";
				if (game_number[i] == "rock")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You win.\n";
					++user_counter;
				}
				else if (game_number[i] == "paper")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "Tie.\n";
				}
				else
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You lose.\n";
					++computer_counter;
				}
				break;

			case 's':

				cout << "You entered scissors.\n";
				if (game_number[i] == "rock")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You lose.\n";
					++computer_counter;
				}
				else if (game_number[i] == "paper")
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "You win.\n";
					++user_counter;
				}
				else
				{
					cout << "Computer enters " << game_number[i] << ".\n"
						<< "Tie.\n";
				}
				break;
		}

		cout << "\nYou have " << user_counter << " points.\n"
			<< "Computer has " << computer_counter << " points.\n\n";
	}
}

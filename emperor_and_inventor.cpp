// emperor_and_inventor.cpp
// by Ricardo Rodriguez
// Ch 4, exercise 8

/*
This exercise deals with the story of the emperor who thanked the
inventor of chess and asked him to name a reward. The inventor asked
for one grain on the first square, 2 for the second, 4 for the third
and so forth. The program will determine and display when the grains reach
1,000, 1,000,000 and 1,000,000,000 grains.
*/

#include "../../../std_lib_facilities.h"

int main()
{
	constexpr int CHESS_BOARD_SQUARES = 64;
	int current_square = 1;
	double number_of_grains = 1.0;
	double total = 1.0;

	char trigger_one_thousand = 'n';
	char trigger_one_million = 'n';
	char trigger_one_billion = 'n';

	while (current_square <= CHESS_BOARD_SQUARES)
	{
		
		if (total > 1000 && trigger_one_thousand == 'n')
		{
			cout << "It will take " << current_square
				<< " squares to reach at least 1000 grains of rice.\n";
			trigger_one_thousand = 'y';
		}
		
		if (total > 1000000 && trigger_one_million == 'n')
		{
			cout << "It will take " << current_square
				<< " squares to reach at least 1,000,000 grains of rice.\n";
			trigger_one_million = 'y';
		}

		if (total > 1000000000 && trigger_one_billion == 'n')
		{
			cout << "It will take " << current_square
				<< " squares to reach at least 1,000,000,000 grains of rice.\n";
			trigger_one_billion = 'y';
		}

		
		++current_square;
		number_of_grains = pow(2,(current_square - 1));
		total += number_of_grains;
	}
	return 0;
}


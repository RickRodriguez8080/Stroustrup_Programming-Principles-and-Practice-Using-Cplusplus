// smallest_highest_integers.cpp
// by: Ricardo Rodriguez
// part of "Try This" pg. 126

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter some integers: ";
	int integer;
	int smallest_value = 0;
	int largest_value = 0;

	int counter = 0;
	while (cin >> integer)
	{
		if (counter == 0) // We need this to read in a second int to compare
		{
			int temp;
			temp = integer;  //assign the first integer to temp
			cin >> integer; // read in the next integer to compare

			if (temp < integer)  // compare and assign to smallest_value and largest_value
			{
				smallest_value = temp;
				largest_value = integer;
			}
			else
			{
				smallest_value = integer;
				largest_value = temp;
			}

			++counter;  // We add to the counter so that this happens only during the first iteration
			cin >> integer; // read in the next integer once more
		}

		// compare the remaining integers on the list
		if (integer < smallest_value)
		{
			smallest_value = integer;
		}

		if (integer > largest_value)
		{
			largest_value = integer;
		}
	}

	cout << "The smallest integer is: " << smallest_value << "\n"
		<< "The largest integer is: " << largest_value << "\n";

	return 0;
}

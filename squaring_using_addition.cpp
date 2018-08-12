// squaring_using_addition.cpp
// from "Try This" on page 116
// We will square numbers using repeated addition

#include "std_lib_facilities.h"

// function declaration

int square_using_addition(int);


int main()
{

	for (int number = 0; number <= 10; ++number)
	{
		int result = 0;
		result = square_using_addition(number);
		cout << result << "\n";
	}

	return 0;
}


// function definitions

int square_using_addition(int num)
{
	if (num == 0)
	{
		cout << "0 is ";
		return 0;
	}
	else if (num == 1)
	{
		cout << "1 is ";
		return 1;
	}
	else
	{
		for (int repeated_addend = 1; repeated_addend < num; ++repeated_addend)
		{
			cout << num << " + ";
		}

		cout << num << " = ";

		int sum = 0;

		for (int repeated_addend = 1; repeated_addend <= num; ++repeated_addend)
		{
			sum += num;
		}

		return sum;
	}
}

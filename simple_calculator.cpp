// simple_calculator.cpp
// Ricardo Rodriguez
// Ch 4, Exercise 5
// Program takes two doubles and an operator, calculates it, and displays the result

#include "std_lib_facilities.h"

int main()
{
	cout << "Simple Calculator\n"
		<< "*****************\n\n"
		<< "Enter a number, then an operator (+, -, *, or /)\n"
		<< "followed by another number and it will calculate it.\n\n";

	double operand1 = 0.0;
	double operand2 = 0.0;
	char operator_sign = ' ';
	double result = 0.0;
	char response = 'y';
		
	while (response == 'y')
	{
		cout << "Enter expression to be calculated: ";
		cin >> operand1 >> operator_sign >> operand2;

		switch (operator_sign)
		{
			case '+':
				result = operand1 + operand2;
				cout << operand1 << " + " << operand2 << " = " << result << "\n";
				break;
			case '-':
				result = operand1 - operand2;
				cout << operand1 << " - " << operand2 << " = " << result << "\n";
				break;
			case '*':
				result = operand1 * operand2;
				cout << operand1 << " * " << operand2 << " = " << result << "\n";
				break;
			case '/':
				result = operand1 / operand2;
				cout << operand1 << " / " << operand2 << " = " << result << "\n";
				break;
			default:
				cout << "Unable to compute.\n";
				break;
		}
		cout << "Care to try another? (y OR n): ";
		cin >> response;
	}

	return 0;
}

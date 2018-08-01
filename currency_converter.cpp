/*	currency_converter.cpp
/	This program will convert yen, kroner and pounds into dollars.
/	Using the conversion rates from Wednesday, Aug 1, 2018
/
/	I also included some error handling
*/

#include "../../../std_lib_facilities.h"

int main()
{
	double amount = 0.0;

	cout << "Currency converter\n"
		<<  "******************\n\n"
		<< "Please choose an option to convert to dollars\n"
		<< "(y for yen)  (k for kroner)  (p for pounds): ";
	
	char currency;
	cin >> currency;

	while (currency != 'y' && currency != 'k' && currency != 'p') {
		cout << "Please try again.\n"
			<< "(y for yen)  (k for kroner)  (p for pounds): ";
		cin >> currency;
	}

	char response = 'y';

	while (response == 'y') {

		if (currency == 'y') {
			//string yen_symbol = "\u00A5"; // could't quite get the right code for this.  Keeps giving me spanish N (enye).
			cout << "Enter the amount of currency in yen: ";
			cin >> amount;

			amount /= 111.6;

			cout << "You have $" << amount << ".\n";
		}
		else if (currency == 'k') {
			cout << "Enter the amount of currency in kroner: ";
			cin >> amount;

			amount /= 8.17;

			cout << "You have $" << amount << ".\n";
		}
		else if (currency == 'p') {
			cout << "Enter the amount of currency in pounds: ";
			cin >> amount;

			amount *= 1.31;

			cout << "You have $" << amount << ".\n";
		}

		cout << "Would you like to perform another conversion? (y OR n): ";
		cin >> response;

		while (response != 'y' && response != 'n') {
			cout << "Please try again.  Would you like to perform another conversion? (y OR n): ";
			cin >> response;
		}

		if (response == 'y') {
			cout << "Please choose an option to convert to dollars\n"
				<< "(y for yen)  (k for kroner)  (p for pounds): ";
			currency = ' ';
			cin >> currency;
		}
		else {
			break;
		}
	}

	return 0;
}
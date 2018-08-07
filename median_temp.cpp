// median_temp.cpp
// Ch 4, Ex 2

#include "../../../std_lib_facilities.h"

//function declarations

// Asks for the user to input C or F for the temperature measurement
// Returns a char value
char temp_unit();

// Creates a vector to store converted temperatures
// Takes a vector and the unit of measurement
// Returns a vector that has converted degree units so that the user possesses both C and F vectors
vector<double> temp_conversion(vector<double> temp, char unit);

// Calculates the median temperature
// Returns a median temperature
double median_temp(vector<double> temp);

// Takes two vectors and two median temperatures
// Prints the vectors and median temps vertically on the display
void print_temp(vector<double> temp1, vector<double> temp2, double median_temp1, double median_temp2);


int main()
{
	char unit_of_measure;
	unit_of_measure = temp_unit();

	cout << "Enter the temperatures you would like to convert (followed by a letter): \n";
	int counter = 0;
	vector<double> tempC;
	vector<double> tempF;
	double median_celcius = 0.0;
	double median_farenheit = 0.0;
	
	if (unit_of_measure == 'c' || unit_of_measure == 'C') {
		double temp;
		while (cin >> temp) // read in the deg C inputs
		{
			tempC.push_back(temp); //grow the deg C vector
		}
		tempF = temp_conversion(tempC, unit_of_measure); // call to convert the temps and create a 
														 // similar vector for deg F
	}

	if (unit_of_measure == 'f' || unit_of_measure == 'F') {
		double temp;
		while (cin >> temp) // read in the deg F inputs
		{
			tempF.push_back(temp); //grow the deg F vector
		}
		tempC = temp_conversion(tempF, unit_of_measure); // call to convert the temps and create a 
														 // similar vector for deg C
	}

	sort(tempC);
	sort(tempF);
	median_celcius = median_temp(tempC);
	median_farenheit = median_temp(tempF);
	print_temp(tempC, tempF, median_celcius, median_farenheit);
	return 0;
}

//function definitions

// Asks for the user to input C or F for the temperature measurement
// Returns a char value
char temp_unit()
{
	cout << "Enter the degree measurement you would like to use (C or F): ";
	char unit;
	cin >> unit;
	while (unit != 'c' && unit != 'C' && unit != 'f' && unit != 'F') {
		cout << "Please try again (enter C or F): ";
		cin >> unit;
	}
	return unit;
}

// Creates a vector to store converted temperatures
// Takes a vector and the unit of measurement
// Returns a vector that has converted degree units so that the user possesses both C and F vectors
vector<double> temp_conversion(vector<double> temp, char unit) 
{
	vector<double> converted_temp;
	double temperature;

	if (unit == 'c' || unit == 'C') { // convert to F
		for (int i = 0; i < temp.size(); ++i) // as we go thru deg C vector...
		{
			temperature  = (temp[i] * 9.0 / 5.0) + 32; // convert each element into deg F
			converted_temp.push_back(temperature); // assign it to a new vector of deg F
		}
	}

	if (unit == 'f' || unit == 'F') { // convert to C
		for (int i = 0; i < temp.size(); ++i) // as we go thru deg F vector
		{
			temperature = (temp[i] - 32) * 5.0 / 9.0; // convert each element into deg C
			converted_temp.push_back(temperature); // assign it to a new vector of deg C
		}
	}

	return converted_temp;
}

// Calculate the median temperature
// Returns a median temperature
double median_temp(vector<double> temp)
{
	double median_value = 0.0;

	if (temp.size() % 2 == 0) // if there are an even number of elements
	{
		median_value = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2;
	}
	else  // if there are an odd number of elements
	{
		median_value = temp[temp.size() / 2];
	}
	return median_value;
}

// Takes two vectors
// Prints the vectors vertically on the display
void print_temp(vector<double> temp1, vector<double> temp2, double median_temp1, double median_temp2)
{
	cout << " Input #      Deg C        Deg F\n"
		<< " *******************************\n";

	cout << fixed << setprecision(1);
	for (int i = 0; i < temp1.size(); ++i)
	{
		cout << "    " << i + 1 << "          " << temp1[i] << "        " << temp2[i] << "\n";
	}
	cout << "Median temps:  " << median_temp1 << "        " << median_temp2 << "\n";
}
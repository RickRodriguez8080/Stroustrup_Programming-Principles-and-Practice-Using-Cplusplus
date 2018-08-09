// city_routes.cpp
// This program reads a series of doubles into a vector.
// It will compute and print the total distance as well as
// print the smallest and longest distances between 
// neighboring cities.

#include "../../../std_lib_facilities.h"

// function declarations

// Asks the user for a series of distances
// Returns a vector of type double with those distances
vector<double> distances();

// Takes in a vector of type double
// Returns the total distance
double total_distance(vector<double> temp);

// Takes in a vector of type double
// Returns the shortest distance
double shortest_distance(vector<double> temp);

// Takes in a vector of type double
// Returns the longest distance
double longest_distance(vector<double> temp);

// Takes in a vector of type double
// Returns the average distance
double avg_distance(vector<double> temp);

// Displays total, shortest, longest, and mean distances
void print_results(double total_dist, double shortest_dist, double longest_dist, double avg_dist);


int main()
{
	vector<double> route_distances;
	route_distances = distances();
	
	double total_length;
	total_length = total_distance(route_distances);

	double shortest_length;
	shortest_length = shortest_distance(route_distances);

	double longest_length;
	longest_length = longest_distance(route_distances);

	double average_length;
	average_length = avg_distance(route_distances);

	print_results(total_length, shortest_length, longest_length, average_length);
	
	return 0;
}

vector<double> distances()
{
	vector<double> route_dist;
	
	cout << "Enter the distances from each point (type a letter to end): ";
	for (double distance; cin >> distance;)
	{
		route_dist.push_back(distance);
	}
	return route_dist;
}

double total_distance(vector<double> temp)
{
	double total_dist = 0.0;

	for (int i = 0; i < temp.size(); ++i)
	{
		total_dist += temp[i];
	}
	return total_dist;
}

double shortest_distance(vector<double> temp)
{
	sort(temp);
	return temp[0];
}

double longest_distance(vector<double> temp)
{
	sort(temp);
	return temp[temp.size() - 1];
}

double avg_distance(vector<double> temp)
{
	double total = 0.0;

	for (int i = 0; i < temp.size(); ++i)
	{
		total += temp[i];
	}
	return total / temp.size();
}

void print_results(double total_dist, double shortest_dist, double longest_dist, double avg_dist)
{
	cout << fixed << setprecision(1);
	cout << "   Total distance: " << total_dist << "\n"
		<<  "Shortest distance: " << shortest_dist << "\n"
		<<  " Longest distance: " << longest_dist << "\n"
		<<  " Average distance: " << avg_dist;
}
// This program demonstrates a two-dimensional array.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.
	ofstream file;
	string filename;


	cout << "This program will calculate the total sales of\n";
	cout << "all the company's divisions.\n";

	cout << "Enter filename: ";
	cin >> filename;

	file.open(filename, ios::app);


	cout << "Enter the following sales information:\n\n";

	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			cout << "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
		}
		cout << endl; // Print blank line.
	}

	file << fixed << showpoint << setprecision(2);
	file << "The sales for the company is: $" << endl;
	file << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


	// Nested loops to display the quarterly sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		file << div + 1 << "\t";
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			double temp = sales[div][qtr];
			file << "$" << temp << "\t";
			totalSales += temp;
		}
		file << endl; // Print blank line.
	}

	file << endl;
	file << "The total sales for the company are: $";
	file << totalSales << endl;
	file.close();

	return 0;
}
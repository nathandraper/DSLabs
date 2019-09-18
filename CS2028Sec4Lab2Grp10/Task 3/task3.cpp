// This program produces a sales report for DLC, Inc.
// This program has been modified to use a class
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // for sort function
#include "Product.h"

using namespace std;

// Function prototypes
bool compareSales(Product product1, Product product2); // comparison function to be used to sort products vector
string getSubstring(string str, string delimiter); // function to return data substring from input file strings
void outputOrder(vector<Product> products, ofstream& file); // functions to write sales to output file
void outputTotals(vector<Product> products, ofstream& file);

// Arbitrarily defined delimiting string constant in data input file
const string DATA_DELIMITER = ": ";

int main()
{
	// open input file
	ifstream file;
	string filename;
	string input;
	
	cout << "enter input filename: ";
	cin >> filename;
	file.open(filename);

	if (!file.is_open()) {
		cout << "file does not exist." << endl;
		return 0;
	}

	// strip empty lines until there is a non empty string or the eof is reached
	// if eof is reached before a non empty line is found, the file is empty and conatins no data.
	getline(file, input);
	while (input == "" && !file.eof()) {
		getline(file, input);
	}

	if (file.eof()) {
		cout << "file contains no data." << endl;
		return 0;
	}
	
	// Empty vector of product objects
	vector<Product> products;
	
	// Loop through data input file and get product values, create product object, and push to vector
	// call getSubstring function to eliminate repetitive code
	int id;
	int units;
	double price;
	string description;
	bool tax;
	while (!file.eof()) {
		id = stoi(getSubstring(input, DATA_DELIMITER));

		getline(file, input);
		units = stoi(getSubstring(input, DATA_DELIMITER));

		getline(file, input);
		price = stod(getSubstring(input, DATA_DELIMITER));

		getline(file, input);
		description = getSubstring(input, DATA_DELIMITER);

		getline(file, input);
		tax = getSubstring(input, DATA_DELIMITER) == "true";

		products.emplace_back(Product(id, units, price, description, tax));

		getline(file, input); // skip empty line
		getline(file, input); // get next line
	}

	file.close();

	// Sort the elements in the products vector in descending order of sales, using custom comparison func
	sort(products.begin(), products.end(), compareSales);

	// open output file
	ofstream outputFile;
	cout << "Enter output file name: ";
	cin >> filename;
	outputFile.open(filename, ios::app);

	// Set the numeric output formatting.
	outputFile << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	outputOrder(products, outputFile);

	// Display total units sold and total sales.
	outputTotals(products, outputFile);

	outputFile.close();
	return 0;
}

// gets the substring containing the data after the delimiter
string getSubstring(string str, string delimiter) {
	int length = str.length();
	int index = str.find(delimiter) + delimiter.length();
	return str.substr(index, length);
}

// This is the comparison function to be passed into the std::sort function.
// Compares two products by sales, returns true if the first is greater than the second.
// This will sort from greatest to smallest (descending order).
bool compareSales(Product product1, Product product2) {
	return product1.getSale() > product2.getSale();
}


// writes the product number and sales of each product to a file
void outputOrder(vector<Product> products, ofstream& file)
{
	int num = products.size();

	file << "Product Number\tSales\n";
	file << "----------------------------------\n";
	for (int index = 0; index < num; index++)
	{
		file << products[index].getID() << "\t\t$";
		file << setw(8) << products[index].getSale() << endl;
	}
	file << endl;
}

// writes the total units sold and sales to the output file
void outputTotals(vector<Product> products, ofstream& file)
{
	int num = products.size();
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < num; index++)
	{
		totalUnits += products[index].getUnits();
		totalSales += products[index].getSale();
	}
	file << "Total units Sold:  " << totalUnits << endl;
	file << "Total sales:      $" << totalSales << endl;
}
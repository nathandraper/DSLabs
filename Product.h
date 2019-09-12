#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
	int id;
	int units;
	double price;
	double sale;
	string description;
	bool tax;

public:
	Product(int, int, double, string, bool);
	~Product();

	int getID();
	int getUnits();
	double getPrice();
	double getSale();
	string getDescription();
	bool getTax();

	void setID(int);
	void setUnits(int);
	void setPrice(double);
	void setDescription(string);
	void setTax(bool);
};

#endif
#include "Product.h"
#include <string>

using namespace std;

Product::Product(int in_id, int in_units, double in_price, string in_description, bool in_tax) {
	this->id = in_id;
	this->units = in_units;
	this->price = in_price;
	this->description = in_description;
	this->tax = in_tax;
	
	this->sale = this->units * this->price;
}

Product::~Product() {}

double Product::getSale() {
	return this->sale;
}

int Product::getID(){
	return this->id;
}

int Product::getUnits() {
	return this->units;
}

double Product::getPrice() {
	return this->price;
}

string Product::getDescription() {
	return this->description;
}

bool Product::getTax() {
	return this->tax;
}

void Product::setID(int in_id) {
	this->id = in_id;
}

void Product::setUnits(int in_units) {
	this->units = in_units;
	this->sale = this->units * this->price;
}

void Product::setPrice(double in_price) {
	this->price = in_price;
	this->sale = this->units * this->price;
}

void Product::setDescription(string in_description) {
	this->description = in_description;
}

void Product::setTax(bool in_tax) {
	this->tax = in_tax;
}

#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Complex::Complex() {
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

Complex::Complex(double r, double theta, bool polar) {
	this->real = cos(theta) * r;
	this->imaginary = sin(theta) * r;
}

void Complex::printNumber() {
	setprecision(4);
	printf("Your complex number:\nCartesian: %f + %f i \nPolar: %f degrees %f radius \n", this->real, this->imaginary, this->getTheta(), this->getR());
}

void Complex::setReal(double real) {
	this->real = real;
}

void Complex::setImaginary(double imaginary) {
	this->imaginary = imaginary;
}

double Complex::getReal() {
	return this->real;
}

double Complex::getImaginary() {
	return this->imaginary;
}

double Complex::getR() {
	return sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
}

double Complex::getTheta() {
	return atan2(this->imaginary, this->real);
}

void Complex::operator +(Complex& b) {
	this->setReal(this->real + b.getReal());
	this->setImaginary(this->imaginary + b.getImaginary());
}

void Complex::operator -(Complex& b) {
	this->setReal(this->real - b.getReal());
	this->setImaginary(this->imaginary - b.getImaginary());
}

void Complex::operator *(double n) {
	this->setReal(this->real * n);
	this->setImaginary(this->imaginary * n);
}

void Complex::operator /(double n) {
	this->setReal(this->real / n);
	this->setImaginary(this->imaginary / n);
}

bool Complex::operator ==(Complex& b) {
	return (this->real == b.getReal()) && (this->imaginary == b.getImaginary());
}
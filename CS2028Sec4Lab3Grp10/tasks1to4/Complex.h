#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(double r, double theta, bool polar);

	void operator +(Complex& b);
	void operator -(Complex& b);
	void operator *(double n);
	void operator /(double n);
	bool operator ==(Complex& b);
	
	void setReal(double real);
	void setImaginary(double imaginary);

	double getReal();
	double getImaginary();
	double getR();
	double getTheta();
	
	void printNumber();
};

#endif
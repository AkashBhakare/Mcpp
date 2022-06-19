#pragma once
struct SimpleCalculator
{
	long long int add(int, int);
	long long int add(int, int, int, int);
	double add(float, float);

	long long int multi(int, int);
	long double multi(double, double);
	double multi(float, float);

};

//Non-Member functions
double  divide(int, int);
long double divide(double, double);
double divide(float, float);

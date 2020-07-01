/*Program to compute numerical integration using Simpson's 1/3rd rule 
x0 = lower limit, xn = upper limit, h = grid size, n = number of strips (must be even for Simpson's 1/3rd rule)*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

#define f(x) sin(x)   //function

int main() {
	double x0, xn, area, h, Simpson;
	int i, n;

	cout << "Enter the lower limit of integration: ";
	cin >> x0;
	cout << "Enter the upper limit of integration: ";
	cin >> xn;
	cout << "Enter the number of strips: ";
	cin >> n;

	x0 = x0 * (3.14159 / 180.0); //conversion from degrees to radians
	xn = xn * (3.14159 / 180.0);	//conversion from degrees to radians

	h = (xn - x0) / n;
	area = f(x0) + f(xn);

	for (i = 1; i <= n - 1; i += 2) {
		area = area + 4 * f(x0 + i * h);
	}
	for (i = 2; i <= n - 2; i += 2) {
		area = area + 2.0 * f(x0 + i * h);
	}
	Simpson = (h / 3.0) * area;

	cout << endl << "The value of the integral using Simpson's 1/3rd rule is: " << Simpson;

	return 0;
}
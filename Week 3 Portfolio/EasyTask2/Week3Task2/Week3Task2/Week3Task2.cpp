// Week3Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* PSUEDOCODE
	ISPRIME(number, div)
	if num < 2
		not prime
	if div = 1
		prime
	else
		if num % div == 0
			not prime
		else
			isPrime(num, div-1)
*/
using namespace std;

bool isPrime(int num, int x) {
	if (num < 2)
		return false;
	if (x == 1)
		return true;
	else
		if (num % x == 0)
			return false;
		else
			return isPrime(num, x - 1);
}

int main()
{
	int x;
	cout << "Give me a number: ";
	cin >> x;
	cout << "Is the number " << x << " prime? " << isPrime(x,x/2) << endl;
	
	system("pause");
    return 0;
}


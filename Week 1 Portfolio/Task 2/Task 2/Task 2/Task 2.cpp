// Task 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int FindZeros(int n) {
	int count = 0;

	for (int i = 5; n / i; i *= 5)
		count += n / i;

	return count;
}

int main()
{
	char cl;
	int n;
	cout << "What is your factoriel? (input only the integer)" << endl;
	cin >> n;

	cout << "Count of the trailing zeros in " << n << "! is " << FindZeros(n) << endl;;

	system("pause");

    return 0;
}

//BIG O notation -> 0(n)


// Week2Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int Square(int num) {
	int highSq;

	for (int i = 0; i <= num; i++) {
		if (i*i <= num) {
			highSq = i*i;
		}
	}

	return highSq;
}

int main()
{
	int num;
	cout << "Gimme your number" << endl;
	cin >> num;


	cout << "Highest square is: " << Square(num) << endl;

	
    return 0;
}

/*PSEUDOCODE
input num
highestSquare

SQUARE
for i <- 0 to num
	if i*i <= num
		highestSquare <- i*i
return highestSquare
*/
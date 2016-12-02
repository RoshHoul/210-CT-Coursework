// Week2Task1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
int number
input number
for (int i<-0, i<number, i++)
if (i*i <= number)
continue
else
answer <- i
break
print answer
*/

int main()
{
	int number;
	int answer;

	cout << "Input number: " << endl;
	cin >> number;

	for (int i = 0; i < number; i++) {
		if (pow(i, 2) <= number) {
			continue;
		}
		else {
			answer = i - 1;
			break;
		}

	}

	cout << answer;
}

// Week5Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	int sequence[20];
	int currLength = 0;
	int finalLength = 0;
	int size;
	int check = 0;
	cout << "How many numbers do you want to input? (A maximum size of 20)" << endl;
	cin >> size;
	if (size > 20) {
		cout << "Told you. Restart application.";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "Give me number: ";
			cin >> sequence[i];
		}
	}

	for (int i = 0; i < size; i++) {
		
		if (sequence[i] < sequence[i + 1]) {
			currLength++;
			if (i == size) {
				if (currLength > finalLength) {
					check = i - finalLength+1;
				}
			}
		}
		else {
			currLength++;
			if (currLength > finalLength) {
				finalLength = currLength;
				check = i - finalLength + 1;
				currLength = 0;
			}
			else {
				currLength = 0;
			}
		}
	}

	for (int i = check; i < finalLength + check; i++) {
		cout << sequence[i] << ", ";
	}
	
	system("pause");
	return 0;
}

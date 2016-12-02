// Week4Easy1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cstdlib>

/*PSEUDOCODE
BINARYRANGE(arr[],first, last,low,high)
	if first > last
		return false
	else 
		midOfArr<-(first+last)/2
		if mid > low AND mid < high
			return true
		else
			if low < mid AND high < mid
				BINARYRANGE(arr[],first,mid-1,low,high)
			else if low > mid AND high > mid
				BINARYRANGE(arr[], mid +1, last, low, high)


BIG O NOTATION:
O(logN)
*/

using namespace std; 

bool binaryS(int A[],  int first, int last, int lRange, int hRange) {

	if (first > last)
		return false;
	else {
		int mid = (first + last) / 2;
		if ((A[mid]  > lRange) && (A[mid] < hRange)) {
			return true;
		}
		else {
			if ((lRange < A[mid]) && (hRange < A[mid] )) {
				binaryS(A,  first, mid - 1, lRange, hRange);
			}
			else if ((lRange > A[mid]) && (hRange > A[mid])) {
				binaryS(A,  mid + 1, last, lRange, hRange);
			}
		}
	}
}

int main()
{

	int A[20];
	int first, last, lowRange, highRange;
	int size;

	cout << "How many numbers do you want to input? (A maximum size of 20)" << endl;
	cin >> size;
	if (size > 20) {
		cout << "Told you. Restart application.";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "Give me number: ";
			cin >> A[i];
		}
	}

	cout << "Give me your bottom range: ";
	cin >> lowRange;
	cout << "Give me your upper range: ";
	cin >> highRange;

	first = 1;
	last = sizeof(A);

	cout << binaryS(A, 0, size, lowRange, highRange) << endl;
	
	system("pause");

    return 0;
}


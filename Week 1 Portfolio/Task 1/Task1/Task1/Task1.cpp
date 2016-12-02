// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

void randomize(int arr[], int n) {
	srand(time(NULL));

	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}

int main()
{
	char close;
	int arrSize;
	cout << "How big do you want your array to be?" << endl;
	cin >> arrSize;

	int *A = new int[arrSize];

	cout << "Enter your array" << endl;
	for (int i = 0; i < arrSize; i++) {
		cin >> A[i];
	}

	randomize(A, arrSize);
	print(A, arrSize);

	system("pause");

	delete[] A;
	//BIG O NOTATION is 0(n)
    return 0;
}


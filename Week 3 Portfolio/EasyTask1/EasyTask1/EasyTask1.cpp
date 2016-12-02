// EasyTask1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#pragma warning (disable : 4996) // strtok prevents the program from running. With a bit of google help, this makes it work

/*PSUEDOCODE
string input
stack output

split string into words (strtok function)
for each token
	output.push
while(output != empty) 
	print(output.head)
	output.pop

*/

using namespace std;

int main()
{
//	string text;
	stack <string> outputSt;
	char str[200]; //= "Hello, i am George and this is awesome.";
	cin.getline(str, 200);
	char *pCh = strtok(str, " . ,");


	while (pCh != NULL) {

		outputSt.push(pCh);
		pCh = strtok(NULL, " ");
	}

	while (!outputSt.empty()) {
		cout << outputSt.top() << " ";
		outputSt.pop();
	}
	cout << endl;
	system("pause");
    return 0;
}

/*
REVERSE A STRING
	read whole string
	separate by spaces;

*/
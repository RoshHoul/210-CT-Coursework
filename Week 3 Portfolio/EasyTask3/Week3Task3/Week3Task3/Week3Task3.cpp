// Week3Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void removeVowel(string word, int n) {
	char vowels[] = { 'a','e', 'i', 'o', 'u','A','E', 'I', 'O', 'U' };
	if (word.find(vowels[n]) != -1) {
		word.erase(word.find(vowels[n]), 1);
		removeVowel(word, n);

	}
	else {
		if (n <= 8)
			removeVowel(word, n + 1);
		else {
			cout << word;
			return;
		}
	}
}


int main()
{
	string word;
	cin >> word;

	removeVowel(word, 0);
	
	system("pause");
    return 0;
}


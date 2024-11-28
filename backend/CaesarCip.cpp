#include <iostream>
#include <string>
#include <unordered_map>
#include "CaesarCip.h"
#include <cctype>
using namespace std;

string caesarEncrypt(string str, int shift) {
	unordered_map<char, char> codeTable;
	string result;

	for (int i = 0; i < 26; i++) {
		codeTable['a' + i] = 'a' + (i + shift) % 26;
		codeTable['A' +i] = 'A' + (i + shift) % 26;
	}

	for(char c: str){
		if (isalpha(c))
			result.push_back(codeTable[c]);
		else
			result.push_back(c);
	}

	cout << "Encrypted text: " << result << endl;
	return result;
}
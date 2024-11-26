#include<iostream>
#include "CaesarCip.h"
using namespace std;

int main() {
	string toEncrypt;

	cout << "Please inser a sentance \n";
	getline(cin, toEncrypt);

	cout << "Encrypted: "<< caesarEncrypt(toEncrypt, 2) << endl;

	return 0;
}
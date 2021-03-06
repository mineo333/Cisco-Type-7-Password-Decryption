// type7decrypt.cpp : Defines the entry point for the console application.
//XOR means 'Exclusive OR' meaning the two parts must be opposite each other
//This means that 1 XOR 1 = 0 but 1 XOR 0 = 1
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int conversion(string x) {
	int k = 0;
	stringstream ss;
	ss << hex << x;
	ss >> k;
	
	return k;
}

int _xor_(int x, int y) {

	return x ^ y;
}

int salt_(int x) {
	int salt;
	char key;
	char pick[] = { 't','f','d',';','k','f','o','A',',','.','i','y','e','w','r','k','l','d','J','K','D' };
	key = pick[x - 1];
	salt = (int)key;
	return salt;
}
string final_string(string input, int salt_base) {
	int length = (input.size() - 2);
	int sections = length / 2;
	int x = 2;
	int y = 3;
	int section = 1;
	int salt = salt_(salt_base);
	string mid = ""; //mid is the sections, conversion mid is the section convrted to an integer
	string finalstring = "";
	
	while (section <= sections) {
		mid = input.at(x);
		mid += input.at(y);
		finalstring += (char)_xor_(salt, conversion(mid));
		cout << "section: " << mid << endl;
		cout <<"conversion mid: "<< conversion(mid) << endl;
		cout << "old salt: " << salt << endl;
		//cout << _xor_(conversion(mid), salt) << endl;
		salt_base += 1;
		salt = salt_(salt_base);
		cout << "new salt: " << salt << endl;
		
		
		x += 2;
		y += 2;
		section++;
		mid = "";
		
		cout << "______" << endl;
	}
	return finalstring;
}
int main()
{	
	
	//x is the starter salt
	string input;
	cin >> input;

	//note the length is of the part without the salt thing
	int x = 0;

	//get first part of the encryption	
	if (input.at(0) != '0') {
		 x = ((int)input.at(0)-48)*10;	
	}
	x += (int)input.at(1)-48;
	
	
	
	cout << final_string(input, x) << endl;
	system("pause");
    return 0;
}




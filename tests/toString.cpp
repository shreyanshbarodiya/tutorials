#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

	char s[50];
	sprintf(s, "%d", 32);

	string stri(s);
	cout << stri;

	return 0;
}
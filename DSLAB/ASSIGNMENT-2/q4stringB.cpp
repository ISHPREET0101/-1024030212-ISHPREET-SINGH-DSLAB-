// 4) String Related Programs (b) Write a program to reverse a string. 
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	char temp;
	cout << "Enter the string" << endl;
	getline(cin,str);

	int n = str.length();
	for(int i=0; i<n/2; i++){
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1];
	}
	cout << "Reversed String" << str << endl;
	return 0;
}

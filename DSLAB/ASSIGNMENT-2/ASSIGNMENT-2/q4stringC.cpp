// (c) Write a program to delete all the vowels from the string

#include <iostream>
using namespace std;

void deleteVowels(string &str) {
    string result = "";
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result += c; 
        }
    }
    str = result;
}

int main() {
    string s;
    cout << "Enter string = " << endl;
    getline(cin,s);    
    deleteVowels(s);
    cout << "After removing vowels: " << s << endl;
    return 0;
}

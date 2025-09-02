// 3) String Anagrams  Given two strings str1 and str2, determine if they form an anagram pair.  
//  Note: Two strings are considered anagrams if one string can be rearranged to form the other string.
 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool anagrams(string str1, string str2) {
    if(str1.length() != str2.length())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    string str1,str2;
    cout << "Enter first string = ";
    cin >> str1;
    cout << "Enter second string = ";
    cin >> str2;

    if (anagrams(str1, str2)){
        cout << "Strings are anagrams." << endl;
    }
    else{
        cout << "Strings are not anagrams." << endl;
    }
    return 0;
}

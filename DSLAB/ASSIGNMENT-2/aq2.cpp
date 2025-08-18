// 2) String Split Challenge You are given a string consisting of lowercase English alphabets.
//  Your task is to determine if it's possible to split this string into three non-empty parts 
//  (substrings) where one of these parts is a substring of both remaining parts 
//
#include <iostream>
#include <string>
using namespace std;

bool substring(string s1, string s2) {
    return s2.find(s1) != string::npos;
}

bool split(string s) {
    int n = s.size();

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string p1 = s.substr(0, i);
            string p2 = s.substr(i, j - i);
            string p3 = s.substr(j);

            if ((substring(p1, p2) && substring(p1, p3)) ||
                (substring(p2, p1) && substring(p2, p3)) ||
                (substring(p3, p1) && substring(p3, p2))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (split(s)){
        cout << "It can be split.\n";
    }else{
        cout << "It cannot be split.\n";
    }
    return 0;
}

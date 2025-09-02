// 2) String Split Challenge You are given a string consisting of lowercase English alphabets.
//  Your task is to determine if it's possible to split this string into three non-empty parts 
//  (substrings) where one of these parts is a substring of both remaining parts 
#include <bits/stdc++.h>
using namespace std;

bool substring(string s) {
    int n = s.size();
    for(int i=1; i<n - 1;i++) {
        for (int j=i+ 1;j<n;j++) {
            string A = s.substr(0,i); //substr(pos,lenght)
            string B =s.substr(i, j-i);
            string C =s.substr(j);

            if((B.find(A) != string::npos && C.find(A) != string::npos) ||
                (A.find(B) != string::npos && C.find(B) != string::npos) ||
                (A.find(C) != string::npos && B.find(C) != string::npos)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string = ";
    cin >> s;

    if(substring(s)) cout << "";
    else cout << "";
    return 0;
}

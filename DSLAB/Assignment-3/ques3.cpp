// 3. Write a program that checks if an expression has balanced parentheses. 
#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(string s){
    stack<char> str;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            str.push(s[i]);
        }
        else if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
            if(str.empty()) return false;
            char top = str.top();
            str.pop();

            if((s[i] == ')' && top != '(') ||
               (s[i] == '}' && top != '{') ||
               (s[i] == ']' && top != '[')){
                return false;
            }
        }
    }
    return str.empty();
}

int main(){
    string s;
    cout << "Enter an expression = ";
    cin >> s;

    if (isbalanced(s))
        cout << "Balanced parentheses " << endl;
    else
        cout << "Not balanced parentheses " << endl;

    return 0;
}

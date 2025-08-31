// 4. Write a program to convert an Infix expression into a Postfix expression. 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}


bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^');
}

string infixToPostfix(string infix) {
    stack<char> str;
    string postfix = "";

    for(int i=0; i<infix.length(); i++) {
        char c = infix[i];

        if(isalnum(c)) {
            postfix += c;
        }
        
        else if(c == '(') {
            str.push(c);
        }
        
        else if(c == ')') {
            while(!str.empty() && str.top() != '(') {
                postfix += str.top();
                str.pop();
            }
            if(!str.empty()) str.pop();
        }
       
        else if(isOperator(c)) {
            while(!str.empty() && precedence(str.top()) >= precedence(c)) {
                postfix += str.top();
                str.pop();
            }
            str.push(c);
        }
    }

    while(!str.empty()) {
        postfix += str.top();
        str.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression = ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression = " << postfix << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <cmath>   
#include <cctype>  
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> str;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            str.push(c - '0');  // converts char to int
        }else {
            int b = str.top(); str.pop();
            int a = str.top(); str.pop();

            switch (c) {
                case '+': str.push(a + b); break;
                case '-': str.push(a - b); break;
                case '*': str.push(a * b); break;
                case '/': str.push(a / b); break;
                case '%': str.push(a % b); break;
                case '^': str.push(pow(a, b)); break;
                default: 
                    cout << "Invalid input " << c << endl;
                    return -1;
            }
        }
    }

    return str.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression = ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result = " << result << endl;

    return 0;
}

//  Given a string, reverse it using STACK.
//   For example “DataStructure” should be output as “erutcurtSataD.” 
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    string reversed = "";
    stack<char> s;
    cout << "Enter a string = ";
    cin >> str;

    for (char c : str) {
        s.push(c);
    }

    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}

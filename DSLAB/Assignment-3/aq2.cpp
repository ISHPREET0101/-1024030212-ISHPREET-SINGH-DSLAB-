// 2. Design a stack that supports getMin() in O(1) time and O(1) extra space. 
#include<iostream>
#include<stack>
using namespace std;

class Stack {
    stack<int>s; 
    stack<int>min; 
public:
    void push(int x){
        s.push(x);
        if(min.empty() || x<=min.top()) {
          min.push(x);
        }else{
            min.push(min.top());
        }
    }

    int getMin(){
        if(min.empty()) {return -1;}
        return min.top();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(5);
    s.push(15);

    cout << s.getMin() << endl;

    return 0;
}
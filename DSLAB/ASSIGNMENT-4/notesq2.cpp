// We are given a stack data structure with push and pop operations, the task is to
// implement a queue using instances of stack data structure and operations on them.

#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1,s2;
    public:

    void enqueue(int x){
        s1.push(x);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
        cout << "Empty" << endl;
        return;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    void top(){
        if(s1.empty() && s2.empty()){
        cout << "Empty" << endl;
        return;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << s2.top() << endl;
    }

    void display(){
        stack<int> temp = s2;
        while(!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    // q.dequeue(); // ! error
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();

    q.display();
    return 0;
}

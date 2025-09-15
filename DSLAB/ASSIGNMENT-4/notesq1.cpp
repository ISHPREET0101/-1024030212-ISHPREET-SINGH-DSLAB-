// 1. Given a Queue data structure that supports standard operations
// like enqueue() and dequeue(). The task is to implement a Stack data
// structure using only instances of Queue and Queue operations allowed on
// the instances.
#include <iostream>
#include <queue>
using namespace std;

class stack{
    queue<int> q;
    public:
    void push(int x){
        int size = q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout << "Empty" << endl;
        }else{
            q.pop();
        }
    }

    void top(){
        if(q.empty()){
            cout << "Empty" << endl;
        }else{
            cout << q.front() << endl;
        }
    }

    void display(){
        queue<int> temp = q;
        while(!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }

    }
};

int main(){
    stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.top();

    q.display();
}


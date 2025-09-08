// 3) Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue<int> &q){
    cout << "Current queue ";
    if(q.empty()){
        cout << "Queue is empty " << endl;
        return;
    }

    queue<int> temp = q;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

void interleave(queue<int> &q){
    if(q.size() % 2 != 0){
        cout << "Cannot interleave an odd sized queue " << endl;
        return;
    }

    stack<int> s;
    int halfsize = q.size()/2;

    for(int i = 0; i<halfsize;++i){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i = 0; i<halfsize;++i){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original queue ";
    display(q);
    interleave(q);
    cout << "Queue after interleaving ";
    display(q);
    return 0;
}
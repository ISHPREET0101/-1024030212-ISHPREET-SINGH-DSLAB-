// 3) Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    queue<int> temp = q;

    if(q.empty()){
        cout << "Underflow" << endl;
        return;
    }

    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
}

void interleave(queue<int> &q){
    if(q.size() %2 != 0){
        cout << "Interleave not possible" << endl;
        return;
    }

    int n = q.size();
    int mid = n/2;
    stack<int> s;

    // display(q);
    // cout << endl;

    for(int i=0;i<mid;i++){
        s.push(q.front());
        q.pop();
    }

    // display(q);
    // cout << endl;

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // display(q);    
    // cout << endl;

    for(int i=0;i<mid;i++){
        s.push(q.front());
        q.pop();
    }
             
    // display(q);
    // cout << endl;

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    // display(q);
    // cout << endl;

    stack<int> temp;
    for(int i=0;i<n;i++){
        temp.push(q.front());
        q.pop();
        
    }

    for(int i=0;i<n;i++){
        
        q.push(temp.top());
        temp.pop();
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

    cout << "Original Queue = ";
    display(q);
    interleave(q);
    cout << endl;
    cout << "After interleave = ";
    display(q);
    return 0;
}
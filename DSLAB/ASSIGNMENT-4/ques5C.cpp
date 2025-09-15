// 5) Write a program to implement a stack using (a) Two queues and 
// (b) One Queue.

#include<iostream>
#include<queue>
using namespace std;

class oneQueue{
    queue<int> q1;
    public:

    void push(int x){
            q1.push(x);
            int size = q1.size();
            for(int i=0;i<size-1;i++){
                int val = q1.front();
                q1.pop();
                q1.push(val);            
        }
    }

    void display(){
        queue<int> temp;
        temp = q1;
        while(!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

};

int main(){
    oneQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(9);

    q.display();
}
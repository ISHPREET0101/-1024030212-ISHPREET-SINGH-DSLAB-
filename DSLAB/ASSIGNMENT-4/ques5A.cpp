// 5) Write a program to implement a stack using (a) Two queues and (b) One Queue.
// ! BY making oush costly

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class pushAlgo{
    queue<int> q1,q2;
    public:
    void push(int x){
        if(q1.empty()){
            q1.push(x);
        }else{
            int size = q1.size();

            for(int i=0;i<size;i++){
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(x);

            for(int i=0;i<size;i++){
                q1.push(q2.front());
                q2.pop();
            }

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
    pushAlgo q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    q1.display();
    return 0;
}
// 2) Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
// operations allowed on queue are:
// 1. enqueue() : Adds an item to rear of queue.
// 2. dequeue() : Removes an item from front of queue.
// 3. isEmpty() : Checks if a queue is empty.

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int minIndex(queue<int> &q,int sortIndex){
    int min_Index = -1;
    int minVal = INT_MAX;
    int n = q.size();

    for(int i=0;i<n;i++){
        int curr = q.front();
        q.pop();

        if(curr <=minVal && i <= sortIndex){
            min_Index = i;
            minVal = curr;
        }
        q.push(curr);
    }
    return min_Index;
}

void insertMinToRear(queue<int> &q, int min_Index){
    int minVal;
    int n = q.size();
    for(int i=0;i<n;i++){
        int curr = q.front();
        q.pop();
        if(i != min_Index){
            q.push(curr);
        }else{
            minVal = curr;
        }
    }
    q.push(minVal);
}

void sortQueue(queue<int> &q){
    for(int i=0;i<=q.size();i++){ // why initialize i =1
        int min_Index = minIndex(q,q.size()-i);
        insertMinToRear(q,min_Index);
    }
}

int main(){
    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);

    sortQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node *front;
    node *rear;
    public:
    queue(){
        front = rear = NULL;
    }

    void enqueue(int val){
        node *newnode = new node(val);
        if(front == NULL){
            front = newnode;
            rear = newnode;
        }else{
            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue(){
        if(front == NULL){
        cout << "queue is empty" << endl;
        return;
    }
        node *temp = front;
        front = front->next;
        delete temp;
    }

    void display(){
        if (front == NULL)
        {
            cout << "queue is empty" << endl;
            return;
        }
        node *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.enqueue(60);
    q.display();
}
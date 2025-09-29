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
            front = rear = newnode;
            rear->next = front;
        }else{
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
        cout << val << " has been enqueued" << endl;
    }

    void dequeue(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
        }else if(front == rear){
            node *temp = front;
            front = rear = NULL;
            delete temp;
        }else{
            node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
        }else{
            node *temp = front;
            cout << "Circular queue" << endl;
            do{
                cout << temp->data << " ";
                temp = temp->next;
            }while(temp != front);
            cout << endl;
        }
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);

    q.display();
}
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

class stack{
    node *head;
    public:
    stack(){
        head = NULL;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }else{
            return false;
        }
    }

    void push(int num){
        node *newnode = new node(num);
        if(newnode == NULL){
            cout << "Stack overflow" << endl;
        }
        newnode->next = head;
        head = newnode;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack underflow" << endl;
        }else{
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void peek(){
        if(!isEmpty()){
            cout << head->data << endl;
        }else{
            cout << "Stack is empty" << endl;
            return;
        }
    }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element = ";
    s.peek();

    s.pop();
    s.pop();
    cout << "Top element = ";
    s.peek();
}
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

class ll{
    node *head;
    public:
    ll(){
        head = NULL;
    }

    void insertAtEnd(int val){
        node *newnode = new node(val);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            return;
        }
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void nNodeFromEnd(int n){
        node *temp = head;
        node *perv = head;
        
        for(int i=0;i<n;i++){
            if(temp == NULL){
                return;
            }
            temp = temp->next;
        }

        while(temp!= NULL){
            temp = temp->next;
            perv = perv->next;
        
        }
        cout << n << " th node from end = " << perv->data << endl;
    }

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    ll l;
    l.insertAtEnd(2);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(3);
    l.insertAtEnd(1);
    l.insertAtEnd(8);
    l.insertAtEnd(7);

    l.nNodeFromEnd(6);
}

// node *temp = head;
// node *perv = NULL;

// if (head->data == val)
// {
//     delete head;
//     head = NULL;
//     return;
// }

// perv = head;
// temp = head->next;
// while (temp != head)
// {
//     if (tem)
// }
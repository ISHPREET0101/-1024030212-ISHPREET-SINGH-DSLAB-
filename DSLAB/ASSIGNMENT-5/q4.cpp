// 4. Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL
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

    void insert(int val){
        node *newnode = new node(val);
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

    void reverse(){
        node *perv = NULL;
        node *curr = head;
        node *next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = perv;
            perv = curr;
            curr = next;
        }
        head = perv;
    }

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    ll l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.display();
    
    l.reverse();
    l.display();
}
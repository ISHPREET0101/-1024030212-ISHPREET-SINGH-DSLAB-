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

    void reverseIterative(){
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

    // ! doubt
    // node *reverseRecursive(node *n){
    //     if(!n || !n->next){
    //         return n;
    //     }
    //     node *newhead = reverseRecursive(n->next);
    //     n->next->next = n;
    //     n->next = NULL;
    //     return newhead;
    // }

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
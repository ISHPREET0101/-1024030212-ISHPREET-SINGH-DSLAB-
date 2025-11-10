// 5. Write a program to check if a linked list is Circular Linked List or not.

// Example 1:

// Input:

// LinkedList: 2->4->6->7->5

#include <iostream>
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
        node *n = new node(val);
        if(head == NULL){
            head = n;
            return;
        }
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }

    void makeCircular(){
        if(head == NULL) return;
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
    }

    bool isCircular(){
        if(head == NULL)
            return false;

        node *temp = head->next;
        while(temp != NULL && temp != head){
            temp = temp->next;
        }

        return (temp == head);
    }

    void displayLimited(int limit = 10){
        node *temp = head;
        int count = 0;
        cout << "List = ";
        while(temp != NULL && count < limit){
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    ll l;
    l.insert(2);
    l.insert(4);
    l.insert(6);
    l.insert(7);
    l.insert(5);

    cout << "Example 1: Normal Linked l" << endl;
    l.displayLimited();
    cout << (l.isCircular()?"It is a Circular Linked list." 
                               : "It is NOT a Circular Linked list.");

    l.makeCircular();
    cout << "Example 2: After making circular" << endl;
    cout << (l.isCircular() ? "It is a Circular Linked List" 
                               : "It is NOT a Circular Linked List.");
    return 0;
}

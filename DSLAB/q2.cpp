// 2. Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.
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
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void occurence(int key){
        int count = 0;

        node *temp = head;

        while(temp != NULL){
            if(temp->data == key){
                count++;
            }
            temp = temp->next;
        }
        cout << "Occurance of " << key << " = " << count << endl;

        while(head != NULL && head->data == key){
            node *temp = head;
            head = head->next;
            delete temp;
        }

        // cout << "Occurence after deletion" << endl;
        node *curr = head;
        while(curr != NULL && curr->next != NULL){
            if(curr->next->data == key){
                node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
        }
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
    l.insert(1);
    l.insert(2);
    l.insert(1);
    l.insert(3);
    l.insert(1);
    l.display();
    
    l.occurence(1);
    l.display();
    return 0;
}
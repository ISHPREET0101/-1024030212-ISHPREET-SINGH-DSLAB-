// 4. Given a linked list, and an integer k, rotate the list to the left by k positions and return
// the updated head.

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

    int count = 1;

    void rotate(int key){
        if(head == NULL && head->next != NULL){
            return;
        }
        node *temp = head;
        
        while(count < key && temp->next != NULL){
           temp = temp->next;
           count++;
        }

        node *curr = temp;
        node *nxt = temp->next;
        node *last = nxt;

        while(last->next != NULL){
            last = last->next;
        }

        last->next = head;

        curr->next = NULL;
        head = nxt;
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
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.display();
    
    l.rotate(4);
    l.display();
    return 0;
}
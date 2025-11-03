// 3. Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3
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

    void middle(){
        node *slow = head;
        node *fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << "Middle element = " << slow->data << endl;
    }
};

int main(){
    ll l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    l.middle();
}
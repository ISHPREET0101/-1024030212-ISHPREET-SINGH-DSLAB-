// ! doubt 
// Given a linked list, remove the loop if it exists.
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
            newnode->next = head;
            return;
        }

        node *temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    void removeLoop(){
        if(head == NULL || head->next == NULL){
            return;
        }

       node *slow = head;
       node *fast = head;

       while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow->data == fast->data){
                break;
            }            
       }

       if(slow->data != fast->data){
        return;
       }

    //    ! doublt
    //    slow = head;
    //    while(slow->next != fast->next){
    //     slow = slow->next;
    //     fast = fast->next;
    //    }

       fast->next = NULL;
    }
};


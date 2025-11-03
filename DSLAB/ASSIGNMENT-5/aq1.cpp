// 1. Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
// The lists may vary in length and have distinct nodes at the beginning, but from the point of
// intersection onward, they share the same sequence of nodes. The task is to identify the first
// common node where the two lists converge. If the two linked lists have no intersection at all,
// return null.
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

    int commonNode(ll &l1, ll &l2, ll &l3){
        node *temp1 = l1.head;
        node *temp2 = l2.head;
        node *temp3 = l3.head;

        while(temp1->next != NULL){
            int val1 = temp1->data;
            while(temp2->next != NULL){
                int val2 = temp2->data;
                
                if(val1 == val2){
                    temp1->next = temp3;
                    temp2->next = temp3;
                    return temp3->data;
                }else{
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
            temp2 = l2.head;
        }
        return 0;
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
    ll l1,l2,l3;
    l1.insert(4);
    l1.insert(1);
    l1.insert(8);
    l1.insert(5);

    l2.insert(5);
    l2.insert(6);
    l2.insert(1);
    l2.insert(8);
    l2.insert(5);

    l3.insert(8);
    l3.insert(5);

    int ans = l3.commonNode(l1,l2,l3);
    cout << ans << endl;

    l1.display();
    l2.display();
    return 0;
}
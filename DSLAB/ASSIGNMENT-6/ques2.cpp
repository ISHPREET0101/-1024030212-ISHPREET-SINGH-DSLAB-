// 2. Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *perv;

    node(int val){
        data = val;
        next = NULL;
        perv = NULL;
    }
};

class CLL{
    node *head;
    public:

    CLL(){
        head = NULL;
    }

    void insert(int val){
        node *n = new node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void display(){
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        cout << "Output  ";
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        } 
        cout << head->data << endl;
    }

};

int main(){
    CLL cll;
    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);
    cll.display();

    return 0;
}

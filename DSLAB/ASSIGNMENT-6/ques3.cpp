// 3. Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
    node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DLL{
    node *head;
public:
    DLL(){
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
        n->prev = temp;
    }


    int getSize(){
        int count = 0;
        node *temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display(){
        node *temp = head;
        cout << "DLL = ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DLL dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.display();
    cout << "Size of DLL = " << dll.getSize() << endl;

    return 0;
}

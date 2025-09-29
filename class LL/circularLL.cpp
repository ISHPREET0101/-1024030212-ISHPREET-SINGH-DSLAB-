#include<iostream> 
using namespace std;
// ! circular linked list
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

    void insertAtBegin(int val){
        node *newnode = new node(val);
        if(head == NULL){
            head = newnode;
            newnode->next = head;
        }else{
            node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void search(int val){
        if(head == NULL){
            cout << "Empty list" << endl;
        }
        int i=0;
        node *temp = head;
        while(temp->next != head && temp->data != val){
            temp = temp->next;
            i++;
        }
        if(temp->data == val){
            cout << "Element found at position " << i+1 << endl;
        }else{
            cout << "Element not found" << endl;
        }
    }

    void insertAtEnd(int val){
        node *newnode = new node(val);
        node *temp = head;
        if(head == NULL){
            head = newnode;
            newnode->next = head;
        }else{
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void insertAfterValue(int num, int val)
    {
        node *newnode = new node(val);
        if(head == NULL){
            cout << "Empty linked list" << endl;
        }else{
            node *temp = head;
            while(temp->data != num){
                if(temp->next == head){
                    cout << "Element not present" << endl;
                    return;
                }
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void deleteFromBegin(){
        if(head == NULL){
            cout << "List is empty" << endl;
        }

        node *temp = head;
        node *temp1 = head;

        while(temp1->next !=head){
            temp1 = temp1->next;
        }

        if(temp1 == head){
            delete head;
            head = NULL;
        }else{
            temp1->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromEnd(){
        if(head == NULL){
            cout << "Linked list is empty" << endl;
            return;
        }

        if(head->next == head){
            delete head;
            head = NULL;
            return;
        }

        node *temp = head;
        node *perv = NULL;
        while(temp->next != head){ // ! in circular ll be carefull to put condition !=head and not != NULL
            perv = temp;
            temp = temp->next;
        }
        perv->next = head;
        delete temp;   
    }

    void deleteByValue(int val){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        node *perv = NULL;
        while(temp->next !=head && temp->data !=val){
            perv = temp;
            temp = temp->next;
        }

        if(temp->data != val){
            cout << "Element not found" << endl;
            return;
        }else if(temp == head){
            deleteFromBegin();
        }else if(temp->next == head){
            deleteFromEnd();
        }else{
            perv->next = temp->next;
        }
        delete temp;        
    }

    void display(){
        if (head == NULL){
            return;
        }
        node *temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
};

int main(){
    ll l;
    l.insertAtEnd(10);
    l.insertAtEnd(20);
    l.insertAtEnd(30);
    // l.display();
    l.insertAtEnd(40);
    l.deleteByValue(30);
    // l.insertAfterValue(30,35);
    // l.deleteFromBegin();

    l.display();
    l.search(30);
}
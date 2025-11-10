// 1. Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// // deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.
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

class DLL{
    node *head;
    public:

    DLL(){
        head = NULL;
    }

    void insertAtBegin(int val){
        node *temp = new node(val);
        if(head != NULL){
            temp->next = head;
            head->perv = temp;
        }
        head = temp;
    }

    void insertAtEnd(int val){
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
        n->perv = temp;
    }

    void insertAfter(int key,int val){
        node *temp = head;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }

        if(temp == NULL){
            return;
        }

        node *n = new node(val);
        n->next = temp->next;
        n->perv = temp;
        if(temp->next != NULL){
            temp->next->perv = n;
        }
        temp->next = n;
    }

    void insertBefore(int key,int val){
        if(head == NULL){
            return;
        }

        if(head->data == key){
            insertAtBegin(val);
            return;
        }

        node *temp = head;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }

        node *n = new node(val);
        n->next = temp;
        n->perv = temp->perv;
        temp->perv->next = n;
        temp->perv = n;
    }

    void deleteNode(int key){
        if(head == NULL){
            return;
        }

        node *temp = head;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }

        if(temp->perv != NULL){
            temp->perv->next = temp->next;
        }else{
            head = temp->next;
        }
        if(temp->next != NULL){
            temp->next->perv = temp->perv;
        }
        delete temp;
        cout << "Node deleted = " << key << endl;
    }

    void search(int key){
        node *temp = head;
        int pos = 1;
        while(temp != NULL){
            if(temp->data == key){
                cout << "Node " << key << " found at pos " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found" << endl;
    }

    void display(){
        node *temp = head;
        if(temp == NULL){
            cout << "Empty" << endl;
        }

        cout << "DLL" << endl;
        while(temp != NULL){
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

    class CLL{
    node *head;
    public:
    CLL(){
        head = NULL;
    }

    void insertAtBeginning(int val){
        node *n = new node(val);
        if(head == NULL){
            head = n;
            n->next = head;
            return;
        }
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        n->next = head;
        temp->next = n;
        head = n;
    }

    
    void insertAtEnd(int val){
        node *n = new node(val);
        if(head == NULL){
            head = n;
            n->next = head;
            return;
        }
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }


    void insertAfter(int key,int val){
        if(head == NULL){
            return;
        }
        node *temp = head;
        do{
            if(temp->data == key){
                node *n = new node(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }while(temp != head);
        cout << "node not found" << endl;
    }

    void deleteNode(int key){
        if(head == NULL){
            return;
        }
        node *temp = head, *prev = NULL;
        if(head->data == key){
            if(head->next == head){
                delete head;
                head = NULL;
                return;
            }
            node *last = head;
            while(last->next != head){
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        do{
            prev = temp;
            temp = temp->next;
        }while(temp != head && temp->data != key);
        if(temp->data != key){
            cout << "node not found" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void search(int key){
        if(head == NULL){
            return;
        }
        node *temp = head;
        int pos = 1;
        do{
            if(temp->data == key){
                cout << "node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }while(temp != head);
        cout << "node not found" << endl;
    }

    void display(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        node *temp = head;
        cout << "Circular Linked List ";
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
};

int main() {
    DLL dll;
    CLL cll;
    int listType, choice, val, key;

    while (true) {
        cout << " MAIN MENU";
        cout << "1. DLL" << endl;
        cout << "2. CLL" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose List Type: ";
        cin >> listType;

        if(listType == 3)break;

        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After a Node";
        cout << "\n4. Insert Before a Node (Doubly Only)";
        cout << "\n5. Delete a Node";
        cout << "\n6. Search a Node";
        cout << "\n7. Display List";
        cout << "\n8. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1)?dll.insertAtBegin(val):cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1)?dll.insertAtEnd(val):cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (listType == 1)?dll.insertAfter(key, val):cll.insertAfter(key, val);
                break;
            case 4:
                if(listType == 1){
                    cout << "Enter key and value: ";
                    cin >> key >> val;
                    dll.insertBefore(key, val);
                }else{
                    cout << "This option is only for Doubly Linked List.\n";
                }
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                (listType == 1)?dll.deleteNode(val):cll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                (listType == 1)?dll.search(val):cll.search(val);
                break;
            case 7:
                (listType == 1)?dll.display():cll.display();
                break;
            case 8:
                continue;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
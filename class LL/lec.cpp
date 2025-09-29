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

    void insertAtBegin(int val){
        node *temp = new node(val);
        temp->next = head;
        head = temp;
    }

    void insertAtEnd(int val){
        node *temp = new node(val);
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            node *ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    void disp(){
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    void search(int x){
            node *curr = head;
            if(head == NULL){
                cout << "List is empty" <<endl;
                return;
            }
            cout << endl;
            while(curr !=NULL){
                if(curr->data == x){
                    cout << "Element found" << endl;
                }else{
                    cout << "Element not found" << endl;
                }
                curr = curr->next;
            }
            
        }

        void insertAfter(int val,int newval){
            node *newnode = new node(newval);
            node *temp = head;
            if(head == NULL){
                head = newnode;
                return;
            }
            while(temp !=NULL && temp->data != val){
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "Value not found" << endl;
            }else{
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }

        void insertAtpos(int pos,int val){
            node *temp = head;
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
                if(temp == NULL){
                    cout << "Invalid Pos" <<endl;
                }
            }
            node *newnode = new node(val);
            newnode->next = NULL;
            newnode->next = temp->next;
            temp->next = newnode;
        }

        void insertTwoPtr(int val){
            node *newnode = new node(val);
            if(head == NULL || head->data >= val){
                newnode->next = head;
                head = newnode;
                return;
            }

            node *perv = NULL;
            node *curr = head;

            while(curr != NULL && curr->data < val){
                perv = curr;
                curr = curr->next;
            }

            perv->next = newnode;
            newnode->next = curr;

        }

        //single pointer
//         void sortedInsert(int d) {
//         node *newNode = new node(d);

//         // Case 1: insert at head (list empty OR new value is smallest)
//         if (head == NULL || head->data >= newNode->data) {
//         newNode->next = head;
//         head = newNode;
//         } 
//         else {
//         // Traverse until finding insertion point
//         node* temp = head;
//         while (temp->next != NULL && temp->next->data < newNode->data) {
//             temp = temp->next;
//         }

//         // Insert newNode after temp
//         newNode->next = temp->next;
//         temp->next = newNode;
//         }
// }

        void deleteAtBegin(){
            if(head == NULL){
                cout << "Linked list is empty" << endl;
            }
            node *temp;
            temp = head;
            head = temp->next;
            delete temp;
        }

        void deleteAtEnd(){
            if(head == NULL){
                cout << "Linked list is empty" << endl;
            }else{
                node *temp = head;
                node *perv = NULL;

                while(temp->next != NULL){
                    perv = temp;
                    temp = temp->next; 
                }

                if(temp == head){
                    head = NULL;
                }else{
                    perv->next = NULL;
                    delete temp;
                }
            }
        }

        void deleteAtPos(int val){
            if(head == NULL){
                cout << "Linked list is empty" << endl;
                return;
            }else{
                node *temp = head;
                node *perv = NULL;

                while(temp != NULL && temp->data != val){
                    perv = temp;
                    temp = temp->next; 
                    }
                    if(temp == NULL){
                        cout << "Element not found" << endl;
                        return;
                    }

                    if(temp == head){
                        head = head->next;
                    }else if(temp->next == NULL){
                        perv->next = NULL;
                    }else{
                        perv->next = temp->next;
                    }
                
                delete temp;
            }         
            
        }

};

int main(){
    ll l;

    int num,n;
    cout << "Enter number of nodes = " << endl;
    cin >> n;

    for(int i=0;i<n;i++){
        cout << "Enter val at node " << i+1 << " = ";
        cin >> num;
        l.insertAtEnd(num);
    }

    cout << "List = " ;
    // l.insertTwoPtr(3);
    // l.insertAtpos(2,7);
    // l.insertAfter(2,9);
    l.deleteAtPos(3);
    l.disp();
    // l.search(2);
}
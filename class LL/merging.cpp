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

    void insertAtEnd(int val){
        node *newnode = new node(val);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            return;
        }else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        }
    }

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    // ! brute force
    // ll bruteForceMerge(ll l1,ll l2){
    //     ll l3;
    //     node *temp = l1.head;
    //     // ? inserting l1 in l3
    //     while(temp != NULL){
    //         l3.insertAtEnd(temp->data);
    //         temp = temp->next;
    //     }
    //     // ? inserting l2 in l3
    //     temp = l2.head;
    //     while(temp != NULL){
    //         l3.insertAtEnd(temp->data);
    //         temp = temp->next;
    //     }
    //     for(node *i=l3.head;i != NULL;i = i->next){
    //         for(node *j=l3.head;j != NULL;j = j->next){
    //             if(i->data < j->data){
    //                 swap(i->data,j->data);
    //             }
    //         }
    //     }
    //     return l3;
    // }

    // ! iterative two ptr merge    
    // node *iterativeMerge(node *l1,node *l2){
    //     node dummy(0);
    //     node *tail = &dummy;
    //     while(l1 != NULL && l2 != NULL){
    //         if(l1->data < l2->data){
    //             tail->next = l1;
    //             l1 = l1->next;
    //         }else{
    //             tail->next = l2;
    //             l2 = l2->next;
    //         }
    //     }
    //     tail->next = (l1 != NULL) ? l1 : l2;
    //         return dummy.next;
    // }

    // ! recursive merge
//     node *recursiveMerge(node *l1, node *l2){
//         if(!l1) {
//             return l2;
//         }
//         if(!l2){
//             return l1;
//         }
//         if(l1->data <= l2->data){
//             l1->next = recursiveMerge(l1->next,l2);
//             return l1;
//         }else{
//             l2->next = recursiveMerge(l1,l2->next);
//             return l2;
//         }
//     }

    // ! iterative in place
    node *inPlaceMerge(node *l1,node *l2){
        node dummy(0);
        node *tail = &dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->data < l2->data){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
        }
        tail->next = (l1 != NULL) ? l1 : l2;
            return dummy.next;

    }
};

int main() {
    ll l1, l2;

    l1.insertAtEnd(3);
    l1.insertAtEnd(7);
    l1.insertAtEnd(10);

    l2.insertAtEnd(1);
    l2.insertAtEnd(2);
    l2.insertAtEnd(5);
    l2.insertAtEnd(8);
    l2.insertAtEnd(10);

    cout << "List 1: "; l1.display();
    cout << "List 2: "; l2.display();

    // ! 1. Brute Force
    // ll bf = l1.bruteForceMerge(l1, l2);
    // cout << "Brute Force Merge: "; bf.display();  
    // ! iterative merging
    // node* iter = l1.iterativeMerge(l1.head, l2.head);
}
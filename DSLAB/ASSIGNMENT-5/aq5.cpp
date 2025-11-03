// 5. Given two polynomial numbers represented by two linked lists. The task is
// to add these lists (meaning the coefficients with the same variable powers will be
// added).
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    int power;
    node *next;

    node(int val,int pow){
        data = val;
        power = pow;
        next = NULL;
    }
};

class addLL{
    node *head;
    public:
    addLL(){
        head = NULL;
    }

    void insert(int val,int pow){
        node *newnode = new node(val,pow);
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

    void add(addLL l1,addLL l2){
        addLL r;
        node *temp1 = l1.head;
        node *temp2 = l2.head;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->power == temp2->power){
                r.insert(temp1->data + temp2->data,temp1->power);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }else if(temp1->power >temp2->power){
                r.insert(temp1->data, temp1->power);
                temp1 = temp1->next;
            }else{
                r.insert(temp2->data,temp2->power);
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL){
            r.insert(temp1->data,temp1->power);
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            r.insert(temp2->data,temp2->power);
            temp2 = temp2->next;
        }

        node *temp = r.head;
        while(temp != NULL){
            cout << temp->data << "x^" << temp->power << "  ";
            temp = temp->next;
        }
    }

   
};

int main(){
    addLL l1,l2;
    l1.insert(5,2);
    l1.insert(4,1);
    l1.insert(2,0);

    l2.insert(5,1);
    l2.insert(5,0);

    l2.add(l1,l2);
    return 0;
}
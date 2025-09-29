#include<iostream>
using namespace std;

class node{
public:
    int coeff;
    int pow;
    node *next;
    node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class poly{
    public:
    node *head;
    poly(){
        head = NULL;
    }

    void insert(int coeff, int pow){
        node *newnode = new node(coeff,pow);
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

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->coeff << "x^" << temp->pow << " ";
            if(temp->next){
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

poly add(poly &p1,poly &p2){
    poly result;
    node *a = p1.head;
    node *b = p2.head;

    while(a != NULL && b != NULL){
        if(a->pow == b->pow){
            result.insert(a->coeff + b->coeff, a->pow);
            a = a->next;
            b = b->next;
        }else if(a->pow > b->pow){
            result.insert(a->coeff,a->pow);
            a = a->next;
        }else{
            result.insert(b->coeff,b->pow);
            b = b->next;
        }
    }

    while(a != NULL){
        result.insert(a->coeff,a->pow);
        a = a->next;
    }
    while(b != NULL){
        result.insert(b->coeff,b->pow);
        b = b->next;
    }
    return result;
}

int main() {
    poly p1, p2;

    // First poly: 5x^2 + 4x^1 + 2x^0
    p1.insert(5, 3);
    p1.insert(5, 3);
    p1.insert(5, 2);
    p1.insert(4, 1);
    p1.insert(2, 0);

    // Second poly: 5x^1 + 5x^0
    p2.insert(4, 2);
    p2.insert(1, 1);
    p2.insert(5, 1);
    p2.insert(5, 0);

    cout << "poly 1: ";
    p1.display();
    cout << "poly 2: ";
    p2.display();

    poly sum = add(p1, p2);

    cout << "Sum = ";
    sum.display();

    return 0;
}

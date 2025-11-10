// 4. Write a program to check if a doubly linked list of characters is palindrome or not.
#include <iostream>
using namespace std;

class node{
    public:
    char data;
    node *prev;
    node *next;
    node(char val){
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

    void insert(char ch){
        node *n = new node(ch);
        if(head == NULL){
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
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

    bool isPalindrome(){
        if (head == NULL || head->next == NULL){
            return true;
        }

        node *tail = head;
        while (tail->next != NULL){
            tail = tail->next;
        }

        node *left = head;
        node *right = tail;

        while(left != right && right->next != left){
            if(left->data != right->data){
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DLL dll;
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for(char ch : str){
        dll.insert(ch);
    }
    dll.display();

    if(dll.isPalindrome()){
        cout << "The DLL is a Palindrome " << endl;
    }else{
        cout << "The DLL is noy a Palindrome " << endl;
    }

    return 0;
}
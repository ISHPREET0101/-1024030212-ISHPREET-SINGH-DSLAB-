// 4. Write a program to determine whether a given binary tree is a BST or not.
#include <iostream>
#include <climits>
using namespace std;

class node{
public:
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

bool checkBST(node* root, int minVal, int maxVal){
    if (root == NULL){
        return true;
    }

    if (root->data <= minVal || root->data >= maxVal){
        return false;
    }
    return checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
}

bool isBST(node* root){
    return checkBST(root, INT_MIN, INT_MAX);
}

int main(){
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);

    if (isBST(root)){
        cout << "This is a BST" << endl;
    }
    else{
        cout << "This is NOT a BST" << endl;
    }
    return 0;
}

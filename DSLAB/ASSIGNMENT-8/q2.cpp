// 2. Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST
#include<iostream>
using namespace std;

class node{
    public: 
    int data;
    node *left;
    node *right;
    node *parent;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class tree{
    node *root;
    public:
    tree(){
        root = NULL;
    }

    int treeSearch(node *temp,int key){

        if(temp == NULL){
            cout << "Element not found" << endl;
            return -1;
        }

        if(key == temp->data){
            return temp->data;
        }

        if(temp->data > key){
            return treeSearch(temp->left,key);
        }else{
            return treeSearch(temp->right,key);
        }
    }

    int iterativeTreeSearch(node *temp,int key){
        while(temp != NULL && key != temp->data){
            if(key < temp->data){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return temp->data;
    }

    node *treeMin(node *temp){
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    int treeMax(node *temp){
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp->data;
    }
    
    node *treeSuccWithoutParent(node *root,node *key){
        if(key->right != NULL){
            return treeMin(key->right);
        }
        node *succ = NULL;
        while(root != NULL){ // ! root = root, key = keroot;
            if(key->data < root->data){
                succ = root;
                root = root->left;
            }else if(key->data > root->data){
                root = root->right;
            }else{
                break;
            }
        }
        cout << succ->data << endl;
        return succ;
    }    
    
    void predecessor(node *pre,node *key){
        node * curr = root;
        pre = NULL;
        while(curr!=NULL){
            if(curr->data < key->data){
                pre = curr;
                curr = curr->right;
            }
            else{
               curr = curr->left;
            }
       }
    }
};

int main(){
    tree t;
    node *root = new node(60);
    node *n1 = new node(41);
    node *n2 = new node(74);
    node *n3 = new node(16);
    node *n4 = new node(53);
    node *n5 = new node(65);
    node *n6 = new node(25);
    node *n7 = new node(46);
    node *n8 = new node(55);
    node *n9 = new node(63);
    node *n10 = new node(70);
    node *n11 = new node(42);
    node *n12 = new node(62);
    node *n13 = new node(64);

    root->left = n1;
    root->right = n2;
    root->left->left = n3;
    root->left->right = n4;
    root->right->left = n5;
    root->left->left->right = n6;
    root->left->right->left = n7;
    root->left->right->right = n8;
    root->right->left->left = n9;
    root->right->left->right = n10;
    root->left->right->left->left = n11;
    root->right->left->left->left = n12;
    root->right->left->left->right = n13;

    // cout << t.treeSearch(root,46);
    // cout << t.iterativeTreeSearch(root,46);
}
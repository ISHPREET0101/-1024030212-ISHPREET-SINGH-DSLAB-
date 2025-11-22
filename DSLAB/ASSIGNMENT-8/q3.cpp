// 3. Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of

#include <iostream>
#include <algorithm>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST{
public:
    node *root;
    BST() {
        root = NULL;
    }

    node* insert(node* root, int key){
        if(root == NULL){
            return new node(key);
        }

        if(key < root->data){
            root->left = insert(root->left, key);
        }
        else if(key > root->data){
            root->right = insert(root->right, key);
        }
        else{
            cout << "Duplicate value not allowed" << endl;
        }

        return root;
    }

    void insert(int key){
        root = insert(root, key);
    }

    node* minValuenode(node* root){
        node *current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    node* deletenode(node* root, int key){
        if(root == NULL){
            cout << "Element not found" << endl;
        }

        if (key < root->data){
            root->left = deletenode(root->left, key);
        }
        else if(key > root->data){
            root->right = deletenode(root->right, key);
        }
        else{
            if(root->left == NULL){
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *temp = minValuenode(root->right);
            root->data = temp->data;             
            root->right = deletenode(root->right, temp->data);
        }
        return root;
    }

    void deleteValue(int key){
        root = deletenode(root, key);
    }

    int maxDepth(node* node){
        if(node == NULL){
            return 0;
        }
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(node* node){
        if(node == NULL){
            return 0;
        }

        if(node->left == NULL && node->right == NULL){
            return 1;}

        if (node->left == NULL){
            return 1 + minDepth(node->right);
        }

        if (node->right == NULL){
            return 1 + minDepth(node->left);
        }

        return 1 + min(minDepth(node->left), minDepth(node->right));
    }
};


int main(){
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Max Depth = " << tree.maxDepth(tree.root) << endl;
    cout << "Min Depth = " << tree.minDepth(tree.root) << endl;

    tree.deleteValue(20);
    tree.deleteValue(30);
    tree.deleteValue(50);

    return 0;
}

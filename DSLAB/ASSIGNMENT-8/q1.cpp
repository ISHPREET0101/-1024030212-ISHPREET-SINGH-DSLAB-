// 1. Write program using functions for binary tree traversals: Pre-order, In-order and Post
// order using a recursive approach.
#include<iostream>
#include<vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// preorder
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root != NULL){
            ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        }      
        
        return ans;    

    }
};

// inorder
class Solution {
public:
vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL){
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
};

// postorder
class Solution {
public:
vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ans.push_back(root->val);
        }
        return ans;
    }
};



#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    void insertNode(TreeNode* root,int value){
        if(value<(root->val)){
            if(root->left){
                insertNode(root->left,value);
            }else{
                TreeNode* tmp = new TreeNode(value);
                root->left=tmp;
            }
        }else{
            if(root->right){
                insertNode(root->right,value);
            }else{
                TreeNode* tmp = new TreeNode(value);
                root->right=tmp;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        cout<<root->val;
        for(int i=1;i<preorder.size();++i)
            insertNode(root,preorder[i]);
        return root;
    }
};
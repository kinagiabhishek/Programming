/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root, int x,TreeNode** px,int& dx,int h){
        if(!root)
            return;
        if(root->left){
            if(root->left->val==x){
                *px=root;
                dx=h;
                return;
            }   
        }
        if(root->right){
            if(root->right->val==x){
                *px=root;
                dx=h;
                return;
            }   
        }
        findParent(root->left,x,px,dx,h+1);
        findParent(root->right,x,px,dx,h+1);   
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* px=NULL;
        TreeNode* py=NULL;
        if(root){
            if(root->val==x || root->val==y)
                return false;
        }
        int h=0,dx=0,dy=0;
        findParent(root,x,&px,dx,h);
        findParent(root,y,&py,dy,h);
        if(dx==dy && px!=py)
            return true;
        else
            return false;
    }
};
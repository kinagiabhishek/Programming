#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int val):val{val},left{NULL},right{NULL}{};   
};
class BinaryTree{
private:
    Node* root;
    int height;
public:
    
};
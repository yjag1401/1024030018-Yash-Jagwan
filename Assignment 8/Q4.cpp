#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isBST(node* root, int minVal, int maxVal){
    if(root == NULL)
        return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

bool isBST(node* root){
    return isBST(root, -1000000, 1000000);
}

int main(){

    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(20);
    root->left->left = new node(3);
    root->left->right = new node(15);

    if(isBST(root))
        cout<<"The given binary tree IS a BST"<<endl;
    else
        cout<<"The given binary tree is NOT a BST"<<endl;

    return 0;
}
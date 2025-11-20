#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorder(node* temp){ 
    if(temp != NULL){
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node* temp){ 
    if(temp != NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void postorder(node* temp){
    if(temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

int main(){
    node* root = new node(41);
    root->left = new node(16);
    root->right = new node(53);
    root->left->left = new node(25);
    root->right->left = new node(46);
    root->right->right = new node(55);
    root->right->left->left = new node(42);

    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);

    return 0;
}
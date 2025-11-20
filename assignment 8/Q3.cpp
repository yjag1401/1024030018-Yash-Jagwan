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

node* insertBST(node* root, int x){
    if(root == NULL)
        return new node(x);

    if(x < root->data)
        root->left = insertBST(root->left, x);
    else if(x > root->data)
        root->right = insertBST(root->right, x);

    return root;
}

node* minNode(node* root){
    node* temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}

node* deleteBST(node* root, int key){
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deleteBST(root->left, key);

    else if(key > root->data)
        root->right = deleteBST(root->right, key);

    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

int maxDepth(node* root){
    if(root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return max(left, right) + 1;
}

int minDepth(node* root){
    if(root == NULL)
        return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(left == 0 || right == 0)
        return left + right + 1;

    return min(left, right) + 1;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    node* root = NULL;

    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    cout<<"BST created with elements: ";
    inorder(root);
    cout<<endl;

    int del;
    cout<<"Enter element to delete: ";
    cin>>del;
    root = deleteBST(root, del);

    cout<<"BST after deletion: ";
    inorder(root);
    cout<<endl;

    cout<<"Maximum Depth of BST: "<<maxDepth(root)<<endl;
    cout<<"Minimum Depth of BST: "<<minDepth(root)<<endl;

    return 0;
}
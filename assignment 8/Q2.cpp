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

node* searchRecursive(node* root, int key){
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

node* searchIterative(node* root, int key){
    node* temp = root;

    while(temp != NULL){
        if(temp->data == key)
            return temp;
        else if(key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

node* treeMinimum(node* root){
    node* temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}

node* treeMaximum(node* root){
    node* temp = root;
    while(temp->right != NULL)
        temp = temp->right;
    return temp;
}

node* inorderSuccessor(node* root, node* x){

    if(x->right != NULL)
        return treeMinimum(x->right);

    node* succ = NULL;
    node* temp = root;

    while(temp != NULL){
        if(x->data < temp->data){
            succ = temp;
            temp = temp->left;
        }
        else if(x->data > temp->data){
            temp = temp->right;
        }
        else{
            break;
        }
    }
    return succ;
}

node* inorderPredecessor(node* root, node* x){
 
    if(x->left != NULL)
        return treeMaximum(x->left);

    node* pred = NULL;
    node* temp = root;

    while(temp != NULL){
        if(x->data > temp->data){
            pred = temp;
            temp = temp->right;
        }
        else if(x->data < temp->data){
            temp = temp->left;
        }
        else break;
    }
    return pred;
}

int main(){
    node* root = NULL;

    int arr[] = {41, 16, 53, 25, 46, 55, 42};
    for(int i = 0; i < 7; i++)
        root = insertBST(root, arr[i]);

    cout<<"BST constructed from: 41 16 53 25 46 55 42\n\n";

    int key = 46;
    cout<<"Searching "<<key<<" (recursive): ";
    if(searchRecursive(root, key))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"Searching "<<key<<" (iterative): ";
    if(searchIterative(root, key))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"\nMinimum element: "<<treeMinimum(root)->data<<endl;
    cout<<"Maximum element: "<<treeMaximum(root)->data<<endl;

    node* x = searchRecursive(root, 46);
    node* succ = inorderSuccessor(root, x);
    if(succ)
        cout<<"\nInorder Successor of 46: "<<succ->data<<endl;
    else
        cout<<"\nInorder Successor of 46: NULL"<<endl;

    node* pred = inorderPredecessor(root, x);
    if(pred)
        cout<<"Inorder Predecessor of 46: "<<pred->data<<endl;
    else
        cout<<"Inorder Predecessor of 46: NULL"<<endl;

    return 0;
}
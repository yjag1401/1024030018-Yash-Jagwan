#include<iostream>
using namespace std;

class node{
    public:
    char data;
    node* prev;
    node* next;

    node(char x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

bool isPalindrome(node* head){
    if(head == NULL) return true;

    node* left = head;
    node* right = head;

    while(right->next != NULL){
        right = right->next;
    }

    while(left != right && right->next != left){
        if(left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main(){
    node* head = new node('k');
    head->next = new node('a');
    head->next->prev = head;
    head->next->next = new node('y');
    head->next->next->prev = head->next;
    head->next->next->next = new node('a');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new node('k');
    head->next->next->next->next->prev = head->next->next->next;

    if(isPalindrome(head))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;

    return 0;
}
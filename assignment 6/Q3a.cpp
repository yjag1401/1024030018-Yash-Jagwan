#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

int sizeDLL(node* head){
    int count = 0;
    node* curr = head;

    while(curr != NULL){
        count++;
        curr = curr->next;
    }

    return count;
}

int main(){
    node* head = new node(5);
    head->next = new node(15);
    head->next->prev = head;
    head->next->next = new node(25);
    head->next->next->prev = head->next;

    cout<<"Size of Doubly Linked List: "<<sizeDLL(head)<<endl;

    return 0;
}
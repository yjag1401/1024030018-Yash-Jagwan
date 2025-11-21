#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

void display(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reverseLL(head);

    cout<<"Reversed List: ";
    display(head);

    return 0;
}
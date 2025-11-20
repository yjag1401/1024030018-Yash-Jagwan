#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

void displayCLL(node* head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    node* curr = head;

    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);

    cout<<head->data;
    cout<<endl;
}

int main(){
    node* head = new node(20);
    head->next = new node(100);
    head->next->next = new node(40);
    head->next->next->next = new node(80);
    head->next->next->next->next = new node(60);
    head->next->next->next->next->next = head;

    cout<<"Circular List: ";
    displayCLL(head);

    return 0;
}
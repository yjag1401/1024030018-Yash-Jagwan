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

void deleteAll(Node* &head, int key){
    int count = 0;

    while(head != NULL && head->data == key){
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->next->data == key){
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        }
        else{
            curr = curr->next;
        }
    }

    cout<<"Count: "<<count<<endl;
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
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key;
    cout<<"Enter key: ";
    cin>>key;

    deleteAll(head, key);

    cout<<"Updated Linked List: ";
    display(head);

    return 0;
}
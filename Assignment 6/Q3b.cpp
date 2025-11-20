#include<iostream>
using namespace std;

class node2{
    public:
    int data;
    node2* next;

    node2(int x){
        data = x;
        next = NULL;
    }
};

int sizeCLL(node2* head){
    if(head == NULL) return 0;

    int count = 0;
    node2* curr = head;

    do{
        count++;
        curr = curr->next;
    } while(curr != head);

    return count;
}

int main(){
    node2* head = new node2(10);
    head->next = new node2(20);
    head->next->next = new node2(30);
    head->next->next->next = head;

    cout<<"Size of Circular Linked List: "<<sizeCLL(head)<<endl;

    return 0;
}
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

class list{
    private:
    node* head;

    public:
    list(){
        head = NULL;
        cout<<"Linked List created!"<<endl;
    }

    void insertBegin(int x){
        node* temp = new node(x);
        temp->next = head;
        head = temp;
    }

    void insertEnd(int x){
        node* temp = new node(x);
        if(head == NULL){
            head = temp;
            return;
        }
        node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }

    void insertBefore(int key, int x){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        if(head->data == key){
            insertBegin(x);
            return;
        }

        node* curr = head;
        while(curr->next != NULL && curr->next->data != key){
            curr = curr->next;
        }

        if(curr->next == NULL){
            cout<<"Key not found"<<endl;
        }
        else{
            node* temp = new node(x);
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void insertAfter(int key, int x){
        node* curr = head;
        while(curr != NULL && curr->data != key){
            curr = curr->next;
        }
        if(curr == NULL){
            cout<<"Key not found"<<endl;
        }
        else{
            node* temp = new node(x);
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void deleteBegin(){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd(){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        node* curr = head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }

        node* temp = curr->next;
        curr->next = NULL;
        delete temp;
    }

    void deleteNode(int key){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(head->data == key){
            deleteBegin();
            return;
        }

        node* curr = head;
        while(curr->next != NULL && curr->next->data != key){
            curr = curr->next;
        }

        if(curr->next == NULL){
            cout<<"Key not found"<<endl;
        }
        else{
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    void search(int key){
        node* curr = head;
        int pos = 1;

        while(curr != NULL){
            if(curr->data == key){
                cout<<"Node found at position "<<pos<<endl;
                return;
            }
            curr = curr->next;
            pos++;
        }
        cout<<"Key not found"<<endl;
    }

    void display(){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        node* curr = head;
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};

int main(){
    list L;

    L.insertEnd(10);
    L.insertEnd(20);
    L.insertEnd(30);
    L.insertEnd(40);
    L.insertEnd(50);

    cout<<"Choose from the following options\n";
    cout<<"1->Insert at Beginning\n";
    cout<<"2->Insert at End\n";
    cout<<"3->Insert Before a Node\n";
    cout<<"4->Insert After a Node\n";
    cout<<"5->Delete from Beginning\n";
    cout<<"6->Delete from End\n";
    cout<<"7->Delete a Specific Node\n";
    cout<<"8->Search a Node\n";
    cout<<"9->Display All Nodes\n";

    int choice;
    cin>>choice;

    int x, key;

    switch(choice){
        case 1:
            cout<<"Enter value: ";
            cin>>x;
            L.insertBegin(x);
            L.display();
            break;

        case 2:
            cout<<"Enter value: ";
            cin>>x;
            L.insertEnd(x);
            L.display();
            break;

        case 3:
            cout<<"Enter key and value: ";
            cin>>key>>x;
            L.insertBefore(key,x);
            L.display();
            break;

        case 4:
            cout<<"Enter key and value: ";
            cin>>key>>x;
            L.insertAfter(key,x);
            L.display();
            break;

        case 5:
            L.deleteBegin();
            L.display();
            break;

        case 6:
            L.deleteEnd();
            L.display();
            break;

        case 7:
            cout<<"Enter value to delete: ";
            cin>>key;
            L.deleteNode(key);
            L.display();
            break;

        case 8:
            cout<<"Enter value to search: ";
            cin>>key;
            L.search(key);
            break;

        case 9:
            L.display();
            break;
    }

    return 0;
}
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

class dll{
    private:
    node* head;

    public:
    dll(){
        head = NULL;
        cout<<"Doubly Linked List created!"<<endl;
    }

    void insertBegin(int x){
        node* temp = new node(x);

        if(head == NULL){
            head = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
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
        temp->prev = curr;
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
        while(curr != NULL && curr->data != key){
            curr = curr->next;
        }

        if(curr == NULL){
            cout<<"Key not found"<<endl;
            return;
        }

        node* temp = new node(x);
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
    }

    void insertAfter(int key, int x){
        node* curr = head;

        while(curr != NULL && curr->data != key){
            curr = curr->next;
        }

        if(curr == NULL){
            cout<<"Key not found"<<endl;
            return;
        }

        node* temp = new node(x);
        temp->next = curr->next;
        temp->prev = curr;

        if(curr->next != NULL)
            curr->next->prev = temp;

        curr->next = temp;
    }

    void deleteNode(int key){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        node* curr = head;

        while(curr != NULL && curr->data != key){
            curr = curr->next;
        }

        if(curr == NULL){
            cout<<"Key not found"<<endl;
            return;
        }

        if(curr->prev != NULL)
            curr->prev->next = curr->next;
        else
            head = curr->next;

        if(curr->next != NULL)
            curr->next->prev = curr->prev;

        delete curr;
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
    dll L;

    L.insertEnd(10);
    L.insertEnd(20);
    L.insertEnd(30);
    L.insertEnd(40);

    cout<<"Choose from the following options\n";
    cout<<"1->Insert at Beginning\n";
    cout<<"2->Insert at End\n";
    cout<<"3->Insert Before a Node\n";
    cout<<"4->Insert After a Node\n";
    cout<<"5->Delete a Node\n";
    cout<<"6->Search\n";
    cout<<"7->Display\n";

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
            cout<<"Enter value to delete: ";
            cin>>key;
            L.deleteNode(key);
            L.display();
            break;

        case 6:
            cout<<"Enter value to search: ";
            cin>>key;
            L.search(key);
            break;

        case 7:
            L.display();
            break;
    }

    return 0;
}
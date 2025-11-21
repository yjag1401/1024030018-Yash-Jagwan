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

class cll{
    private:
    node* head;

    public:
    cll(){
        head = NULL;
        cout<<"Circular Linked List created!"<<endl;
    }

    void insertBegin(int x){
        node* temp = new node(x);

        if(head == NULL){
            head = temp;
            temp->next = head;
            return;
        }

        node* curr = head;
        while(curr->next != head)
            curr = curr->next;

        temp->next = head;
        curr->next = temp;
        head = temp;
    }

    void insertEnd(int x){
        node* temp = new node(x);

        if(head == NULL){
            head = temp;
            temp->next = head;
            return;
        }

        node* curr = head;
        while(curr->next != head)
            curr = curr->next;

        curr->next = temp;
        temp->next = head;
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
        while(curr->next != head && curr->next->data != key)
            curr = curr->next;

        if(curr->next == head){
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

        if(curr == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        do{
            if(curr->data == key){
                node* temp = new node(x);
                temp->next = curr->next;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        } while(curr != head);

        cout<<"Key not found"<<endl;
    }

    void deleteNode(int key){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        if(head->data == key){
            node* curr = head;
            while(curr->next != head)
                curr = curr->next;

            node* temp = head;
            head = head->next;
            curr->next = head;

            delete temp;
            return;
        }

        node* curr = head;
        while(curr->next != head && curr->next->data != key)
            curr = curr->next;

        if(curr->next == head){
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

        if(curr == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        do{
            if(curr->data == key){
                cout<<"Node found at position "<<pos<<endl;
                return;
            }
            curr = curr->next;
            pos++;
        } while(curr != head);

        cout<<"Key not found"<<endl;
    }

    void display(){
        if(head == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        node* curr = head;

        do{
            cout<<curr->data<<" ";
            curr = curr->next;
        } while(curr != head);

        cout<<endl;
    }
};

int main(){
    cll L;

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
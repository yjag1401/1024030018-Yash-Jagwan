#include<iostream>
#define MAXLEN 100
using namespace std;

class circularqueue{
    private:
    int element[MAXLEN];
    int front, rear;

    public:
    circularqueue(){
        front = -1;
        rear = -1;
        cout<<"Circular Queue created!"<<endl;
    }

    int isEmpty(){
        if(front == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int isFull(){
        if((rear + 1) % MAXLEN == front){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Circular Queue Overflow"<<endl;
        }
        else{
            if(front == -1){
                front = 0;
                rear = 0;
            }
            else{
                rear = (rear + 1) % MAXLEN;
            }
            element[rear] = x;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Circular Queue Underflow"<<endl;
        }
        else{
            cout<<"Deleted element: "<<element[front]<<endl;
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1) % MAXLEN;
            }
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Circular Queue is Empty"<<endl;
        }
        else{
            int i = front;
            while(true){
                cout<<element[i]<<" ";
                if(i == rear) break;
                i = (i + 1) % MAXLEN;
            }
            cout<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Circular Queue is Empty"<<endl;
        }
        else{
            cout<<element[front]<<endl;
        }
    }
};

int main(){
    circularqueue Q;

    cout<<"Choose from the following options\n1->enqueue()\n2->dequeue()\n3->isEmpty()\n4->isFull()\n5->display()\n6->peek()\n";

    int choice;
    cin>>choice;
    Q.enqueue(4);
    Q.enqueue(7);
    Q.enqueue(11);
    Q.enqueue(20);
    Q.enqueue(5);
    Q.enqueue(9);

    switch(choice){
        case 1:
            int x;
            cout<<"Enter the element you want to enqueue\n";
            cin>>x;
            Q.enqueue(x);
            cout<<"Elements of the Circular Queue are: ";
            Q.display();
            break;

        case 2:
            Q.dequeue();
            cout<<"Elements of the Circular Queue are: ";
            Q.display();
            break;

        case 3:
            if(Q.isEmpty()==1){
                cout<<"Circular Queue is Empty"<<endl;
            }
            else{
                cout<<"Circular Queue is NOT Empty"<<endl;
            }
            break;

        case 4:
            if(Q.isFull()==1){
                cout<<"Circular Queue is Full"<<endl;
            }
            else{
                cout<<"Circular Queue is NOT Full"<<endl;
            }
            break;

        case 5:
            cout<<"Elements of the Circular Queue are: ";
            Q.display();
            break;

        case 6:
            cout<<"Front element is: ";
            Q.peek();
            break;
    }

    return 0;
}
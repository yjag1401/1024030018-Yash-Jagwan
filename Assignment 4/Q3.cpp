#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q){
    int n = q.size();
    int half = n / 2;

    queue<int> first;

    for(int i = 0; i < half; i++){
        first.push(q.front());
        q.pop();
    }

    while(!first.empty()){
        q.push(first.front());
        first.pop();

        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    int n, x;

    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++){
        cin>>x;
        q.push(x);
    }

    interleave(q);

    cout<<"Interleaved Queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
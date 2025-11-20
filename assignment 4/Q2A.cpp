#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int minIndex(queue<int>& q, int sortedIndex){
    int minVal = INT_MAX;
    int minIdx = -1;
    int n = q.size();

    for(int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();

        if(curr <= minVal && i <= sortedIndex){
            minVal = curr;
            minIdx = i;
        }

        q.push(curr);
    }
    return minIdx;
}

void insertMinToRear(queue<int>& q, int minIdx){
    int minVal;
    int n = q.size();

    for(int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();

        if(i == minIdx)
            minVal = curr;
        else
            q.push(curr);
    }

    q.push(minVal);
}

void sortQueue(queue<int>& q){
    int n = q.size();

    for(int i = 1; i <= n; i++){
        int minIdx = minIndex(q, n - i);
        insertMinToRear(q, minIdx);
    }
}

int main(){
    queue<int> q;

    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout<<"Sorted Queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
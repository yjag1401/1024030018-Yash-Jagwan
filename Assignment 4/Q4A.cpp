#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches){
    queue<int> q;

    for(int s : students)
        q.push(s);

    int idx = 0;
    int count = 0;

    while(!q.empty()){
        if(q.front() == sandwiches[idx]){
            q.pop();
            idx++;
            count = 0;
        }
        else{
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;
        }

        if(count == q.size())
            return q.size();
    }

    return 0;
}

int main(){
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    int result = countStudents(students, sandwiches);

    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
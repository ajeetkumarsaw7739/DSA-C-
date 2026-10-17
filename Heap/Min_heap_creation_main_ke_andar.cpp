#include<iostream>
#include<queue>
using namespace std;

int main(){
    //min heap create
    priority_queue<int,vector<int>,greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    minheap.push(9);

    cout << "Top element " << minheap.top() << endl;

    minheap.pop();

    cout << "Top element " << minheap.top() << endl;

    cout << "size is " << minheap.size() << endl;

    if(minheap.empty()){
        cout << "pq  is empty " << endl;
    }
    else{
        cout << "pq is not empty " << endl;
    }
    
    return 0;
}
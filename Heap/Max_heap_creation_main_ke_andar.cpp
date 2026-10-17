#include<iostream>
#include<queue>
using namespace std;

int main(){

    //max heap create
    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.push(9);

    cout << "Top element " << pq.top() << endl;

    pq.pop();

    cout << "Top element " << pq.top() << endl;

    cout << "size is " << pq.size() << endl;

    if(pq.empty()){
        cout << "pq  is empty " << endl;
    }
    else{
        cout << "pq is not empty " << endl;
    }
    
    return 0;
}

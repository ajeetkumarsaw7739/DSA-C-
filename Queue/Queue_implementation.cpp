#include<iostream>
using namespace std;

class queue{
    public:

    int *arr;
    int front;
    int rear;
    int size;

    // Constructor: queue ko initialize karta hai
    queue(){
        size = 100001;
        arr = new int[size];

        // Initially queue empty hai
        front = 0;
        rear = 0;
    }

    // Check karta hai ki queue empty hai ya nahi
    bool isempty(){

        // front == rear means queue empty
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    // Queue ke rear se element insert karta hai
    void enqueue(int data){

        // Agar rear size tak pahunch gaya to queue full hai
        if(rear == size){
            cout << "Queue is full " << endl;
            return;
        }
        else{
            // Data ko rear position par insert karo
            arr[rear] = data;

            // Rear ko next position par move karo
            rear++;
        }
    }

    // Queue ke front se element delete karta hai
    int dequeue(){

        // Agar front == rear hai to queue empty hai
        if(front == rear){
            cout << "Queue is empty " << endl;
            return -1;
        }
        else{

            // Front element ko store karo
            int ans = arr[front];

            // Deleted position ko -1 kar diya
            arr[front] = -1;

            // Front ko next position par move karo
            front++;

            // Agar queue completely empty ho gayi
            // to front aur rear ko reset kar do
            if(front == rear){
                front = 0;
                rear = 0;
            }

            return ans;
        }
    }

    // Queue ke front element ko return karta hai
    int getFront(){

        // Queue empty hai
        if(front == rear){
            return -1;
        }
        else{
            // Front element return karo
            return arr[front];
        }
    }
};

int main(){

    queue q;

    // Queue mein elements insert
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);

    // Front element print
    cout << q.getFront() << endl;

    // Front element delete
    q.dequeue();

    // Updated front element print
    cout << q.getFront() << endl;

    // Check whether queue is empty
    if(q.isempty()){
        cout << "queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }

    return 0;
}
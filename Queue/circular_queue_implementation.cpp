#include <iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    // Initialize your data structure
    CircularQueue(int n) {
        size = n;
        arr = new int[size];

        front = rear = -1;
    }

    // Pushes x into the queue
    // Returns true if pushed, false otherwise
    bool enqueue(int value) {

        // Check whether queue is full
        if ((front == 0 && rear == size - 1) ||
            (rear == (front - 1 + size) % size)) {
            return false;
        }

        // First element
        else if (front == -1) {
            front = rear = 0;
        }

        // Maintain circular nature
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }

        // Normal flow
        else {
            rear++;
        }

        // Push inside queue
        arr[rear] = value;

        return true;
    }

    // Deletes front element from queue
    // Returns -1 if queue is empty
    // Otherwise returns deleted element
    int dequeue() {

        // Check whether queue is empty
        if (front == -1) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }

        // Maintain circular nature
        else if (front == size - 1) {
            front = 0;
        }

        // Normal flow
        else {
            front++;
        }

        return ans;
    }
};

int main() {

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Deleted: " << q.dequeue() << endl;
    cout << "Deleted: " << q.dequeue() << endl;

    q.enqueue(60);
    q.enqueue(70);

    cout << "Deleted: " << q.dequeue() << endl;
    cout << "Deleted: " << q.dequeue() << endl;

    return 0;
}
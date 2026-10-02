#include <iostream>
using namespace std;

class Deque {
public:
    int *arr;
    int front;
    int rear;
    int size;

    // Initialize data structure
    Deque(int n) {
        size = n;
        arr = new int[n];

        front = -1;
        rear = -1;
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if deque is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Insert from front
    bool pushFront(int x) {

        if (isFull()) {
            return false;
        }

        // If deque is empty
        if (isEmpty()) {
            front = rear = 0;
        }

        // Circular condition
        else if (front == 0) {
            front = size - 1;
        }

        // Normal case
        else {
            front--;
        }

        arr[front] = x;

        return true;
    }

    // Insert from rear
    bool pushRear(int x) {

        if (isFull()) {
            return false;
        }

        // If deque is empty
        if (isEmpty()) {
            front = rear = 0;
        }

        // Circular condition
        else if (rear == size - 1) {
            rear = 0;
        }

        // Normal case
        else {
            rear++;
        }

        arr[rear] = x;

        return true;
    }

    // Delete from front
    int popFront() {

        if (isEmpty()) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }

        // Circular condition
        else if (front == size - 1) {
            front = 0;
        }

        // Normal case
        else {
            front++;
        }

        return ans;
    }

    // Delete from rear
    int popRear() {

        if (isEmpty()) {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }

        // Circular condition
        else if (rear == 0) {
            rear = size - 1;
        }

        // Normal case
        else {
            rear--;
        }

        return ans;
    }

    // Get front element
    int getFront() {

        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int getRear() {

        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }
};

int main() {

    Deque dq(5);

    // Insert from rear
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);

    // Insert from front
    dq.pushFront(5);

    cout << "Front element: " << dq.getFront() << endl;

    cout << "Rear element: " << dq.getRear() << endl;

    // Delete from front
    cout << "Pop Front: " << dq.popFront() << endl;

    // Delete from rear
    cout << "Pop Rear: " << dq.popRear() << endl;

    cout << "Front element: " << dq.getFront() << endl;

    cout << "Rear element: " << dq.getRear() << endl;

    return 0;
}
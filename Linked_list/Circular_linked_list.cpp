#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;

        // Circular linked list me next ko delete nahi karna
        cout << "memory free for node with data " << val << endl;
    }
};

void insertnode(Node* &tail,int ele, int d){

    //empty list
    if(tail == NULL){
        Node* newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        //non empty list
        //assume that the element is present in the list
        Node* curr = tail;
        
        while(curr->data != ele){
            curr = curr->next;
        }

        //element found-> curr is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletenode(Node* &tail,int val){

    //empty list
    if(tail == NULL){
        cout << "List is empty " << endl;
        return;
    }
    else{
        //non empty list
        //assume that value is present in the linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 node linked list
        if(curr == prev){
            tail = NULL;
        }

        // >= 2 node linked list
        else if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){

    Node* temp = tail;

    //empty list
    if(tail == NULL){
        cout << "Empty list " << endl;
        return;
    }

    do{
        cout << tail->data << " ";
        tail = tail->next;

    }
    while(tail != temp);

    cout << endl;
}

int main(){
    
    //create node
    Node* tail = NULL;

    insertnode(tail,5,3);
    print(tail);

    insertnode(tail,3,5);
    print(tail);

    insertnode(tail,5,7);
    print(tail);

    deletenode(tail,5);
    print(tail);
    
    return 0;
}
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
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

void insertAthead(Node* &head,Node* &tail,int d){
    //empty list
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }
    temp->next = head;
    head = temp;
}

void insertAttail(Node* &tail,Node* &head,int d){
    //empty list
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
        head = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}
void insertAtposition(Node* &head,Node* &tail,int pos,int d){

    //insert at first position
    if(pos == 1){
        insertAthead(head,tail,d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp->next == NULL){
        insertAttail(tail,head,d);
        return ;
    }

    //create a node for d
    Node* insertnode = new Node(d);
    insertnode->next = temp->next;
    temp->next = insertnode;
}
void deletenode(Node* &head,int pos){

    //deleting first node
    if(pos == 1){
        Node* temp = head;
        head = temp->next;

        //memeory free start node
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* head){

    //empty list
    if(head == NULL){
        cout << "Empty list "<< endl;
        return ;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){

    Node* node1 = NULL;

    Node* head = node1;
    Node* tail = node1;

    insertAthead(head,tail,10);
    print(head);

    insertAthead(head,tail,5);
    print(head);

    insertAttail(tail,head,15);
    print(head);

    insertAttail(tail,head,20);
    print(head);

    insertAtposition(head,tail,3,25);
    print(head);

    deletenode(head,3);
    print(head);
    
    return 0;
}
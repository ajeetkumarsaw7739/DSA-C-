#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAttail(Node* &tail,Node* &head,int d){

    //empty list
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtposition(Node* &head,Node* &tail,int pos,int d){

    //insert at first
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

    //insert at last position
    if(temp->next == NULL){
        insertAttail(tail,head,d);
        return ;
    }

    ///creating a new node for d
    Node* newnode = new Node(d);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void deletenode(Node* &head,int pos){

    //delete first node
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;

    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node* head){

    int len = 0;

    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
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

    cout << "lenght is: " << getlength(head);

    return 0;
}
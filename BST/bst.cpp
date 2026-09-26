#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor: new node create karne ke liye
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// BST mein new node insert karne ka function
Node* insertintobst(Node* root,int d){

    // Base case:
    // Agar root NULL hai, to new node create karo
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    // Agar data root se bada hai
    // to right subtree mein insert karenge
    if(d > root->data){

        root->right = insertintobst(root->right,d);
    }
    else{

        // Agar data root se chhota ya equal hai
        // to left subtree mein insert karenge
        root->left = insertintobst(root->left,d);
    }

    return root;
}

// User se data lekar BST create karne ka function
void takeinput(Node* &root){

    int data;

    cin >> data;

    // Jab tak data -1 nahi milta,
    // tab tak BST mein nodes insert karte rahenge
    while(data != -1){

        root = insertintobst(root,data);
        cin >> data;
    }
}

// BST ka Level Order Traversal
void levelordertraversal(Node* root){

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    
        Node* front = q.front();
        q.pop();

        // Agar NULL mila
        if(front == NULL){

            // Purana level complete traverse ho chuka hai
            cout << endl;

            // Agar queue empty nahi hai,
            // to next level ke end ke liye NULL push karo
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";

            // Agar left child exist karta hai,
            if(front->left){
                q.push(front->left);
            }

            // Agar right child exist karta hai,
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

int main(){

    Node* root = NULL;

    cout << "Enter data to create BST " << endl;

    takeinput(root);

    // BST ka level order print karo
    levelordertraversal(root);

    return 0;
}
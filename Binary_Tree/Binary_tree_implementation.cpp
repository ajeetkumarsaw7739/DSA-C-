#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree(Node* root){

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){

            //purana level complete travese ho chuka hai
            cout << endl;

            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root){

    //base case
    if(root == NULL){
        return ;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

void preorder(Node* root){

    //base case
    if(root == NULL){
        return ;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node* root){

    //base case
    if(root == NULL){
        return ;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";

}

void buildfromlevelorder(Node* &root){

    queue<Node*> q;

    cout << "Enter data for root " << endl;
    int data;
    cin >> data;

    if(data == -1){
        root = NULL;
        return;
    }

    root = new Node(data);

    q.push(root);

    while (!q.empty()){

        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){

    Node* root = NULL;

    /*root = buildtree(root);

    //level order traversal
    cout << "printing the level order traversal output:" << endl;

    levelordertraversal(root);

    // inorder traversal
    cout << "printint the inorder traversal: " ;

    inorder(root);
    cout << endl;
    // preorder traversal
    cout << "printing the preorder traversal: ";

    preorder(root);
    cout << endl;
    // postorder traversal
    cout << "printing the postorder traversal: ";

    postorder(root);*/

    //build level order
    buildfromlevelorder(root);
    
    levelordertraversal(root);
    
    return 0;
}

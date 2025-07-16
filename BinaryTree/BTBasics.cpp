#include<iostream>
using namespace std;
class Node{
   public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* constructTree(){
    cout<<"enter the value to insert"<<endl;
    int val;
    cin>>val;

    if(val==-1){
        return NULL;
    }
    else{
        Node* root=new Node(val);
        root->left=constructTree();
        root->right=constructTree();
        return root;
    }
    
}
void preOrder(Node* root){
    if(root==NULL)return;
    cout<<root->val<<"->";
    preOrder(root->left);
    preOrder(root->right);
    return;
}
void inOrder(Node* root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->val<<"->";
    inOrder(root->right);
    return;
}

void postOrder(Node* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<"->";
    return;
}

int main(){
    Node* root=NULL;
    root=constructTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}
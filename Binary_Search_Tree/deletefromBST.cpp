//Leetcode Question N0->
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    
};

Node* buildTree(Node*root,int val){
    if(root==nullptr){
        return new Node(val);
    }
    else{
        if(val<root->val){
            root->left=buildTree(root->left,val);
        }
        else {
            root->right=buildTree(root->right,val);
        }
    }
    return root;
}

void constructTree(Node* &root){
    cout<<"enter the root value";
    int val;
    cin>>val;
    while(val!=-1){
        root=buildTree(root,val);
        cout<<"enter the node val";
        cin>>val;
    }
    return;
}

int getMin(Node*root){
    if(root==nullptr)return -1;
    if(root->left==nullptr)return root->val;
    return getMin(root->left);
}

Node* deleteKey(Node* root,int key){
    if(!root)return nullptr;
    if(root->val==key){
        if(root->left==nullptr&&root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left!=nullptr&&root->right==nullptr){
            Node* leftSubTree=root->left;
            root->left=nullptr;
            delete root;
            return leftSubTree;
        }
        else if(root->left==nullptr&&root->right!=nullptr){
            Node* rightSubTree=root->right;
            root->right=nullptr;
            delete root;
            return rightSubTree;
        }
        else{
            int minofRight=getMin(root->right);
            root->val=minofRight;
            root->right= deleteKey(root->right,minofRight);
            return root;
        }
    }
    else{
        if(key>root->val){
           root->right= deleteKey(root->right,key);
        }
        else{
           root->left= deleteKey(root->left,key);
        }
    }
    return root;
}
void inorder(Node* root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    return;
}
int main(){
    Node*root=nullptr;
    constructTree(root);
    inorder(root);
    int key;
    cout<<"enter the key to delete";
    cin>>key;
    while(key){
        root=deleteKey(root,key);
        inorder(root);
        cout<<"enter the key to delete";
        cin>>key;
    }
}
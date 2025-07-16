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
    if(val>=root->val){
        root->right=buildTree(root->right,val);
    }
    else{
      root->left=buildTree(root->left,val);
    }
    }
    return root;
}


void constructTree(Node* &root){
     cout<<"enter the value of node"<<endl;
     int val;
     cin>>val;
     while(val!=-1){
        root=buildTree(root,val);
        cout<<"enter the value of node"<<endl;
        cin>>val;
     }
     return;
}

Node* lowestCommonAncestor(Node* root,Node*p,Node*q){
    if(root==nullptr)return nullptr;
    if(p->val>root->val&&q->val>root->val){
        return lowestCommonAncestor(root->right,p,q);
    }
    if(p->val<root->val&&q->val<root->val){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}

int main(){
    Node* root=nullptr;
    constructTree(root);

    Node*p=new Node(60);
    Node*q=new Node(76);
    cout<<lowestCommonAncestor(root,p,q)->val<<endl;
    return 0;
}
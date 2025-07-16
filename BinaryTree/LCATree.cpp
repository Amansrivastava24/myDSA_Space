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
     cout<<"enter the value of the node"<<endl;
     int val;
     cin>>val;
     if(val==-1)return NULL;
     else {
        Node*root=new Node(val);
        root->left=constructTree();
        root->right=constructTree();
        return root;
     }
}
Node* LCA(Node*root,Node*p,Node*q){
    if(root==NULL)return NULL;
    if(root->val==p->val)return p;
    if(root->val==q->val)return q;

    Node* leftAns=LCA(root->left,p,q);
    Node* rightAns=LCA(root->right,p,q);

    if(leftAns!=NULL&&rightAns!=NULL)return root;
    else if(leftAns==NULL&&rightAns!=NULL)return rightAns;
    else if(leftAns!=NULL&&rightAns==NULL)return leftAns;
    else return NULL;
}
int main(){
    Node* root=constructTree();
    int pval;
    cin>>pval;
    Node*p=new Node(pval);
    int qval;
    cin>>qval;
    Node*q=new Node(qval);

    Node*ans=LCA(root,p,q);
    cout<<ans->val;
    return 0;


}
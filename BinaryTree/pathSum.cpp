/*Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.*/
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
  
Node* constructTree(){
    cout<<"enter the value of the Node"<<endl;
    int val;
    cin>>val;
    if(val==-1)return NULL;
    else{
        Node* root=new Node(val);
        root->left=constructTree();
        root->right=constructTree();

        return root;
    }
}

bool checkPath(Node*root,int target){
    if(root==NULL)return false;
    if(root->left==NULL&&root->right==NULL){
        if(target==0)return true;
        else return false;
    } 
    int leftAns=checkPath(root->left,target-root->val);
    int rightAns=checkPath(root->right,target-root->val);
    return leftAns||rightAns;
    
}

int main(){

    Node*root=constructTree();
    cout<<"enetr the target"<<endl;
    int target;
    cin>>target;
    if(checkPath(root,target)){
        cout<<"path exist";
    }
    else cout<<"path does not exist";

}
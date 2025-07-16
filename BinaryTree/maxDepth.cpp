#include<iostream>
using  namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node*right;
    
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};


 int maxDepth(Node* root){
    if(root==NULL)return 0;

    int leftMax=maxDepth(root->left);
    int rightMax=maxDepth(root->right);
    int maxHeight=max(leftMax,rightMax);
    return maxHeight+1;
 }
Node* constructTree(){
    cout<<"Enter the value of the node"<<endl;
    int val;
    cin>>val;
    if(val==-1)return NULL;
    Node*root=new Node(val);
    root->left=constructTree();
    root->right=constructTree();
    return root;
}
int main(){
    Node*root=constructTree();
    int maxDep=maxDepth(root);
    cout<<"max depth is"<<maxDep<<endl;
    return 0;
}
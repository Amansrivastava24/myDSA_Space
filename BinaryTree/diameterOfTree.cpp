/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.*/
#include<iostream>
using namespace std;
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

int getHeight(Node*root){
    if(root==NULL)return 0;
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    int height=max(leftHeight,rightHeight);
    return height+1;
}

int findDiameter(Node* root){
    if(root==NULL)return 0;
    int option1=findDiameter(root->left);
    int option2=findDiameter(root->right);
    int option3=getHeight(root->left)+getHeight(root->right);
    return max(option1,max(option2,option3));
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
    int diameter=findDiameter(root);
    cout<<diameter<<endl;
    return 0;
}

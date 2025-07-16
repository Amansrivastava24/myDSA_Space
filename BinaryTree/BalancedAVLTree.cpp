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
    cout<<"Enter the value of the node"<<endl;
    int val;
    cin>>val;
    if(val==-1)return NULL;
    else{
        Node*root=new Node(val);
        root->left=constructTree();
        root->right=constructTree();
        return root;
    }
}
int getHeight(Node* root){
    if(root==NULL)return 0;
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    int maxHeight=max(leftHeight,rightHeight);
    return maxHeight+1;
}
bool balanced(Node* root){
   if(root==NULL)return true;
   int count=abs(getHeight(root->left)-getHeight(root->right));
   if(count<=1){
    return balanced(root->left)&&balanced(root->right);
   }
   else return false;
}

int main(){
    Node* root=constructTree();
    if(balanced(root)){
        cout<<"tree is balanced Avl tree"<<endl;
    }
    else 
    cout<<"tree is not a balanced tree";
}
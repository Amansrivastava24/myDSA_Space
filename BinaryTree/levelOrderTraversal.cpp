#include<iostream>
#include<queue>
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
void levelOrderTraversal(Node* root){
  queue<Node*>list;
  if(root==NULL)return;
  list.push(root);
  while(!list.empty()){
    int size=list.size();
   while(size--){
     Node* front=list.front();
    list.pop();
    cout<<front->val<<" ";
    if(front->left!=NULL){
        list.push(front->left);
    }
    if(front->right!=NULL){
        list.push(front->right);
    }
    }
    cout<<endl;
  }
  return;
}

int main(){
    Node* root=NULL;
    root=constructTree();
    levelOrderTraversal(root);
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
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

int getIndex(vector<int>inorder,int element){
    int n=inorder.size();
    for(int i=0;i<n;i++){
        if(inorder[i]==element)return i;
    }
    return -1;
}

Node* constructTree(vector<int>inorder,vector<int>preorder,int& preInd,int inStart,int inEnd,int preSize){
      if(preInd>=preSize)return NULL;
      if(inStart>inEnd)return NULL;
      int element=preorder[preInd];
      preInd++;
      int currelementInd=getIndex(inorder,element);
      Node* root=new Node(element);
      root->left=constructTree(inorder,preorder,preInd,inStart,currelementInd-1,preSize);
      root->right=constructTree(inorder,preorder,preInd,currelementInd+1,inEnd,preSize);
      return root;
}

void levelTraversal(Node* root){
    queue<Node*>q;
    if(root==NULL)return;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* front=q.front();
            q.pop();
            cout<<front->val<<" ";
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);
        }
        cout<<endl;
    }
    return ;
}

int main(){

    vector<int>inorder={9,3,15,20,7};
    vector<int>preorder={3,9,20,15,7};
    
    int preorderIndex=0;
    int instart=0;
    int inEnd=inorder.size()-1;
    Node* root=constructTree(inorder,preorder,preorderIndex,instart,inEnd,preorder.size());
    levelTraversal(root);
    return 0;

}
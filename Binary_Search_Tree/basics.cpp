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
        this->left=nullptr;
        this->right=nullptr;
    }
};

Node* buildTree(Node* root,int val){
    if(root==nullptr){
        // Node*root=new Node(val);
        // return root;
        return new Node(val);
    }
    else {
        if(val<root->val){
            root->left=buildTree(root->left,val);
        }
        else{
            root->right=buildTree(root->right,val);
        }
    }
    return root;
}


void constructTree(Node* &root){
    cout<<"enter the node value"<<endl;
    int val;
    cin>>val;
    while(val!=-1){
        root=buildTree(root,val);
        cout<<"enter the node value"<<endl;
        cin>>val;
    }
}

void preorder(Node* root){
    if(root==nullptr)return;
    cout<<root->val<<"->";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(Node* root){
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->val<<"->";
    inorder(root->right);
    return;
}
void postorder(Node* root){
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<"->";
    return;
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    if(root==nullptr)return;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* front=q.front();
            q.pop();
            cout<<front->val<<" ";
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        cout<<endl;
    }
    return;
}

int getMin(Node*root){
    if(root==nullptr)return -1;
    if(root->left==nullptr)return root->val;
    return getMin(root->left);
}
int getMax(Node*root){
    if(root==nullptr)return -1;
    if(root->right==nullptr)return root->val;
    return getMax(root->right);
}

bool SearchBST(Node* root,int target){
    if(root==nullptr)return false;
    if(root->val==target)return true;
    if(target<root->val)
    return SearchBST(root->left,target);
    else
    return SearchBST(root->right,target);
    // else {
    //     if(target>root->val){
    //         bool leftCheck=SearchBST(root->right,target);
    //         if(leftCheck)return true;
    //     }
    //     else{
    //         bool rightCheck=SearchBST(root->left,target);
    //         if(rightCheck)return true;
    //     }
    // }
    // return false;
}

int main(){
    Node* root=nullptr;
    constructTree(root);
    preorder(root);  
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelordertraversal(root);
    cout<<getMin(root);
    cout<<getMax(root);
    int target;
    cout<<"enter the target to search";
    cin>>target;
    if(SearchBST(root,target))cout<<"target found";
    else cout<<"target not found";

    return 0;
    
}
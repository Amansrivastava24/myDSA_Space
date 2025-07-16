#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void printSubset(vector<int>arr,int n,int ind,vector<int>subset){
    if(ind==n){
        for(auto it:subset){
            cout<<it;
        }
        cout<<endl;
        return;
    }
    subset.push_back(arr[ind]);
    printSubset(arr,n,ind+1,subset);
    subset.pop_back();
    printSubset(arr,n,ind+1,subset);
    return;
}
int main(){
    int n;
    vector<int>arr;
    cout<<"Enter the size";
    cin>>n;
    cout<<"Enter the element";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int>subset;
    printSubset(arr,n,0,subset);
    return 0;
}
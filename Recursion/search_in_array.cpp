#include<iostream>
#include<vector>
using namespace std;
bool searchArray(vector<int>arr,int key,int index,int size){
    if(index>=size) return false;
    if(arr[index]==key) return true;
    bool ans=searchArray(arr,key,index+1,size);
    return ans;
}

int main(){
    vector<int>arr;
    cout<<"Enter the size of array";
    int n;
    cin>>n;
    cout<<"Enter the elements";
    int a;
    for(int i=0;i<n;i++){
       cin>>a;
       arr.push_back(a);
    }
    cout<<"Enter the key";
    int key;
    cin>>key;
    cout<<searchArray(arr,key,0,n);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int>arr,int n,int ind){
   //Base case:- if index exceeds the size of array that means array is sorted
    if(ind==n-1){
        return true;
    }
    //initialize two variables 
    //one for currentanswer other for the recursion
    bool currentAnswer=false;
    bool recursionAnswer=false;
    //check one case i.e arr[0]<arr[1]
    if(arr[ind]<arr[ind+1]){
        currentAnswer=true;
    }
    //recursive call to find the answer from remaining array
    recursionAnswer=checkSorted(arr,n,ind+1);
    return currentAnswer&&recursionAnswer;
}
int main(){
    vector<int>arr;
    cout<<"enter the array size";
    int n;
    cin>>n;
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    //cout<<checkSorted(arr,n,0);
    if(checkSorted(arr,n,0)){
     cout<<"true";
    }
    else cout<<"false";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
void coinSolve(vector<int>arr,int total,int& count,int ind){
if(total==0){
    count++;
    return;
}
for(int i=ind;i<arr.size();i++){
    if(total-arr[i]<0)break;
    coinSolve(arr,total-arr[i],count,i);
}
return;
}
int main(){
    vector<int>arr={1,2,5};
    int total,count=0;
    cin>>total;
    coinSolve(arr,total,count,0);
    cout<<count;
    return 0;
}
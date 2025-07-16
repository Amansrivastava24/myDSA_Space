#include<iostream>
#include<vector>
using namespace std;
void getSum(vector<int>arr,int sum,int n,int &count){
    if(n==0){
        if(sum==0){
        count++;
    }
        return ;
    }
    getSum(arr,sum,n-1,count);
    getSum(arr,sum-arr[n-1],n-1,count);
    return;
   
}
int main(){
  vector<int>arr;
  int n;
  cout<<"Enter the size of Array";
  cin>>n;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr.push_back(a);
  }
  cout<<"Enter the target Sum";
  int sum;
  cin>>sum;
  int ans=0;
  getSum(arr,sum,arr.size(),ans);
  cout<<ans;
  return 0;

}
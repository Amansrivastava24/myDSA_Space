#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximizeRobberyCash(vector<int>nums,int n,int ind){
  //Base Case 
  if(ind>=n)return 0;
  //steal the money 
  int option1=nums[ind]+maximizeRobberyCash(nums,n,ind+2);
  //Dont steal the money
  int option2=0+maximizeRobberyCash(nums,n,ind+1);
  //return max of the options
  return max(option1,option2);
  
}
int main(){
    int n;
    vector<int>nums;
    cout<<"Enter the number of houses/elements";
    cin>>n;
    cout<<"Enter the money they posses";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int ans=maximizeRobberyCash(nums,n,0);
    cout<<ans;
    return 0;
}
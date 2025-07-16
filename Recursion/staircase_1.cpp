//Question climbing stair case
#include<iostream>
#include<vector>
using namespace std;
int stairCase(int n){
    //if staircase has only 1 stair then we have only  one way to climb
    if(n==1)return 1;
    // if staircase has 2 stair then we have two ways to climb
    if(n==2)return 2;
    //recursive call 
    int ans=stairCase(n-1)+stairCase(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter number of stair";
    cin>>n;
    cout<<stairCase(n);
    return 0;
}
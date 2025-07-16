#include<iostream>
#include<vector>
#include<string>
using namespace std;

void countConfiguration(int sum,int currsum,int& count,int ind,string nums){
    if(currsum==sum){
     count++;
     cout<<nums<<endl;
     return;
    }
    if(currsum>sum)return;
   for(int i=1;i<=6;i++){
    if(currsum>sum)break;
    countConfiguration(sum,currsum+i,count,i,nums+to_string(i)+" ");
   }
    return;
}
int main(){
    int sum;
    cin>>sum;
    int currsum=0,count=0;
    string ans;
    countConfiguration(sum,currsum,count,0,ans);
    cout<<count;
    return 0;
}
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximizeCutSegment(int n,int x,int y,int z){
//Base conditions 
//1. n<0 that means segment can be cut so we return minimum possible val intmin
//2. n==0 we return 0 as length of tree is over
if(n<0)return INT_MIN;
if(n==0)return 0;
//cut segment of x length from overall length and resturn leave for recursion
int cut_x=1+maximizeCutSegment(n-x,x,y,z);
//cut segment of y length from overall length and resturn leave for recursion
int cut_y=1+maximizeCutSegment(n-y,x,y,z);
//cut segment of z length from overall length and resturn leave for recursion
int cut_z=1+maximizeCutSegment(n-z,x,y,z);
//return maximum of the three 
return max(cut_x,max(cut_y,cut_z));
}

int main(){
 int n;
 cout<<"Enter the length of the segment";
 cin>>n;
 cout<<"Enter the segments tyo be cut x,y,z";
 int x,y,z;
 cin>>x>>y>>z;
 int ans=0;
 ans=maximizeCutSegment(n,x,y,z);
 cout<<ans;
 return 0;
}

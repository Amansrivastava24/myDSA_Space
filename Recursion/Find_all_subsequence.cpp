#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;
void printSubsequence(string s,string temp,int ind){
    int n=s.length();
    if(ind==n){
        cout<<temp<<endl;
        return;
    }
    printSubsequence(s,temp+s[ind],ind+1);
    printSubsequence(s,temp,ind+1);

    return;
}
int main()
{
    string s;
    getline(cin, s);
    string temp="";
    printSubsequence(s,temp,0);
    return 0;
}
/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g321
[AC]
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
int main(){
    int a;
    cin>>a;
    int ans=70;
    if(a>=1250){
        a-=1250;
        ans+=5+(a/200)*5;
    }
    cout<<ans;
    return 0;
}
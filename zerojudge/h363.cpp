/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h363
[AC]
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
int main(){
    int a;
    cin>>a;
    lli ans=0,maxn=0;
    while(a--){
        lli b;
        cin>>b;
        ans+=b;
        maxn=max(b,maxn);
    }
    cout<<ans-maxn;
    return 0;
}
/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i085
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
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        int a;
        cin>>a;
        ans+=a/1000;
    }
    cout<<ans;
    return 0;
}
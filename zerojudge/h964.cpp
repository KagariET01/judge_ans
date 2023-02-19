/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h964
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
    lli ans=1;
    while(a--){
        int b;
        cin>>b;
        if(b%2==0){
            ans=b;
            break;
        }
    }
    if(ans!=1){
        cout<<ans;
    }else{
        cout<<"not found";
    }
    return 0;
}
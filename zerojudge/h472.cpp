/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h472
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
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    lli passmin=(h2-h1)*60+m2-m1;
    lli t;
    cin>>t;
    cout<<passmin;
    if(passmin>=t){
        cout<<" yes";
    }else{
        cout<<" no";
    }
    return 0;
}
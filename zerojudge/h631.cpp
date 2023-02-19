/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h631
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
    while(a%2==0 && a!=1){
        a/=2;
    }
    while(a%3==0 && a!=1){
        a/=3;
    }
    while(a%5==0 && a!=1){
        a/=5;
    }
    if(a!=1){
        cout<<"beautiful";
    }else{
        cout<<"ugly";
    }
    return 0;
}
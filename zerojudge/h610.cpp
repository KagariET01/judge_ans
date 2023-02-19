/*
[Q]https://zerojudge.tw/ShowProblem?problemid=h610
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
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    string str="Safe for now.";
    if(r1==r2 || c1==c2){
        str="You're dead!";
    }else if(abs(r1-r2)==abs(c1-c2)){
        str="You're dead!";
    }
    cout<<str;
    return 0;
}
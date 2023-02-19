#include<bits/stdc++.h>
using namespace std;
int t,pixels=0;
string str1;
int a(int add){
    add>>=1;
    for(int i=0;i<4;i++){
        t++;
        if(str1[t]=='0'){continue;}
        if(str1[t]=='1'){pixels+=add*add;continue;}
        a(add);
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>str1;
    int add;
    cin>>add;
    if(str1[0]=='2'){
        a(add);
    }else if(str1[0]=='1'){
        pixels+=add*add;
    }
    cout<<pixels<<'\n';
    return 0;
}

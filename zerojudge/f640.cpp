#include<bits/stdc++.h>
using namespace std;
int a(){
    char b[10];
    cin>>b;
    if(b[0]=='f'){
        int x=a();
        return 2*x-3;
    }else if(b[0]=='g'){
        int x=a();
        int y=a();
        return 2*x+y-7;
    }else if(b[0]=='h'){
        int x=a();
        int y=a();
        int z=a();
        return 3*x-2*y+z;
    }else{
        return atoi(b);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<a();
}

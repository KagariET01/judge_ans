#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=(b*b-4*a*c);
        int ians=sqrt(ans);
        if(ans>=0&&ians*ians==ans){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
    }
    return 0;
}

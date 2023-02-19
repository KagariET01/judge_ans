#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    int s=a.size();
    if(s%2!=0){cout<<"NO"<<endl;return 0;}
    for(int i=0;i<=(s/2);i++){
        if(a[i]!=a[s-i-1]){cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
    for(int i=0;i<(s/2);i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}

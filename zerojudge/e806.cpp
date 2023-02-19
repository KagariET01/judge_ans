#include<iostream>
using namespace std;
int main(){
    int a[1001];
    for(int i=0;i<1001;i++){
        a[i]=0;
    }
    int maxp=0;
    for(int l=0;l<2;l++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int p,c;
            cin>>p>>c;
            if(p>maxp){maxp=p;}
            a[p]+=c;
        }
    }
    int counter1=0;
    for(int i=maxp;i>=0;i--){
        if(a[i]!=0){cout<<i<<":"<<a[i]<<endl;counter1++;}
    }
    if(counter1==0){cout<<"NULL!"<<endl;}
    return 0;
}

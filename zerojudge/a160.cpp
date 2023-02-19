#include<bits/stdc++.h>
using namespace std;
int a(int n,int k,int p[]){
    if(k>=n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==p[i]){
                    cout<<"Q";
                    continue;
                }cout<<"x";
            }
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }
    int total=0;
    bool valid[n];
    for(int i=0;i<n;i++){
        valid[i]=true;
    }
    for(int i=0;i<k;i++){
        valid[p[i]]=false;
        int b=k-i+p[i];
        if(b<n){valid[b]=false;}
        b=p[i]-(k-i);
        if(b>=0){valid[b]=false;}
    }
    for(int i=0;i<n;i++){
        if(valid[i]){
            p[k]=i;
            total+=a(n,k+1,p);
        }
    }
    if(k==0){
        cout<<total<<"\n\n";
    }
    return total;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(true){
        cin>>n;
        if(n<=0){break;}
        int p[n];
        a(n,0,p);
    }
    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n,sh,sm;
    cin>>n>>sh>>sm;
    int timeh[n+1];
    int timem[n+1];
    for(int i=0;i<=n;i++){timeh[i]=0;timem[i]=0;}
    timeh[0]=sh;
    timem[0]=sm;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        timeh[i]=timeh[i-1];
        timem[i]=m+timem[i-1];
        timeh[i]+=timem[i]/60;
        timem[i]=timem[i]%60;
        timeh[i]=timeh[i]%24;
    }
    int s=1;
    while(s!=0){
        cin>>s;
        if(s==0){break;}
        //s++;
        if(timeh[s]<10){cout<<"0";}
        cout<<timeh[s]<<":";
        if(timem[s]<10){cout<<"0";}
        cout<<timem[s]<<"\n";
    }
    return 0;
}

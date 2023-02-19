#include <iostream>
#include <algorithm>>
using namespace std;

int main(){
    int n;
    cin>>n;
    int al[n];
    for(int i=0;i<n;i++){
        cin>>al[i];
    }
    sort(&(al[0]),&(al[n]));
    int now=0,coun=0;
    for(int i=0;i<n;i++){
        if(al[i]-now){
            coun+=1;
            now=al[i];
        }else{
            al[i]=0;
        }
    }
    cout<<coun<<"\n";
    for(int i=0;i<n;i++){
        if(al[i]){
            cout<<al[i]<<" ";
        }
    }
    return 0;
}

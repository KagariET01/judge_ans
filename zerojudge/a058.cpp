#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a;
    int* ll=NULL;
    ll=new int(0);
    for(int i=0;i<a;i++){
        cin>>b;
        ll[b%3]+=1;
    }
    cout<<ll[0]<<" ";
    cout<<ll[1]<<" ";
    cout<<ll[2];


    delete (ll);
    return 0;
}

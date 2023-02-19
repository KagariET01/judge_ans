//c022
#include <iostream>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        int a=0,b=0;
        cin>>a;
        cin>>b;
        a=(a/2)*2+1;
        b=((b+1)/2)*2-1;
        cout<<"Case "<<i+1<<": "<<((a+b)*((b-a)/2+1)/2)<<"\n";
    }





    return 0;
}

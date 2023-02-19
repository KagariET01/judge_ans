#include <iostream>

using namespace std;

int main(){
    int n=0,k=0,p=0,tot=0;
    while(cin>>n){
        cin>>k;
        while(true){
            p+=n;
            tot+=n;
            n=0;
            if(p/k){
                n=p/k;
                p%=k;
            }
            else{break;}

        }
        cout<<tot<<"\n";
        n=0;k=0;p=0;tot=0;
    }
    return 0;
}

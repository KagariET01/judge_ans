#include <iostream>

using namespace std;

int main(){
    int n=0,k=3,p=0,tot=0;
    while(cin>>n){
        n++;
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
        tot--;
        cout<<tot<<"\n";
        n=0;k=3;p=0;tot=0;
    }
    return 0;
}

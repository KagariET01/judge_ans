#include <iostream>
#include<cmath>
using namespace std;

int main(){
    unsigned long long int a,total=0;
    while(cin>>a){
        total=0;
        for(int i=1;i<=int(sqrt(a));i++){
            if(not(a%i)){
                total+=i;
                if(a/i!=i){
                    total+=a/i;
                }
            }
        }
        total-=a;
        if(a>total){cout<<"虧數\n";}
        else if(a<total){cout<<"盈數\n";}
        else if(a==total){cout<<"完全數\n";}
    }



    return 0;
}

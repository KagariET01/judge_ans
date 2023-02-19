#include<iostream>
#include<list>
#include<cmath>
using namespace std;
int main(){
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int counter1=0;
        {
            for(int i=a+1;i<b;i++){
                if(i%c){counter1++;cout<<i<<" ";}
            }
        }
        if(counter1==0){cout<<"No free parking spaces."<<endl;}else{cout<<endl;}
    }
    return 0;
}

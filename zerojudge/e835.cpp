#include <iostream>

using namespace std;

int main(){
    int a,x,y,z;
    cin>>a;
    if(a<2500){
        x=1;
        y=((a/25)+1);
        z=a%25;
        if(z==0){
            z=25;
            y=y-1;
        }
    }else if(a<7500){
        x=2;
        a=a-2500;
        y=((a/50)+1);
        z=a%50;
        if(z==0){
            z=50;
            y=y-1;
        }
    }else{
        x=3;
        a=a-7500;
        y=((a/25)+1);
        z=a%25;
        if(z==0){
            z=25;
            y=y-1;
        }
    }
    cout<<x<<" "<<y<<" "<<z;


    return 0;
}

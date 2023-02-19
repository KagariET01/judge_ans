#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int add=4;
    while(add<a){
        a-=add;
        add+=4;
    }
    add/=4;
    int counter1=0;
    while(a>0){
        a-=add;
        counter1++;
    }
    if(counter1==1){cout<<"Pen";}
    if(counter1==2){cout<<"Pineapple";}
    if(counter1==3){cout<<"Apple";}
    if(counter1==4){cout<<"Pineapple pen";}
    return 0;
}

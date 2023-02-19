#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){cout<<"a leap year";}
            else{cout<<"a normal year";}
        }else{cout<<"a leap year";}
    }
    else{cout<<"a normal year";}



    return 0;
}

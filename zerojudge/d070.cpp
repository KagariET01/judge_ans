#include <iostream>

using namespace std;

int main(){
    int a=1;
    while(cin>>a){
        if(a==0){
            break;
        }
        if(a%4==0){
            if(a%100==0){
                if(a%400==0){cout<<"a leap year\n";}
                else{cout<<"a normal year\n";}
            }else{cout<<"a leap year\n";}
        }
        else{cout<<"a normal year\n";}
    }




    return 0;
}

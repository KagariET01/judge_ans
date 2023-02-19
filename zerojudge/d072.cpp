#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>a;
        cout<<"Case " <<i<<": ";
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

#include <iostream>

using namespace std;

int main(){
    int hh,mm,tt=0;
    cin>>hh;
    cin>>mm;
    tt=mm+hh*60;
    if(tt>=450 && tt<1020){
        cout<<"At School";
    }else{
        cout<<"Off School";
    }


    return 0;
}

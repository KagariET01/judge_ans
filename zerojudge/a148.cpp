#include <iostream>

using namespace std;

int main(){
    int a,total=0;
    while(cin>>a){
        total=0;
        for(int i=0;i<a;i++){
            int b;
            cin>>b;
            total+=b;
        }
        if(total>59*a){cout<<"no\n";}
        else{cout<<"yes\n";}
    }










    return 0;
}

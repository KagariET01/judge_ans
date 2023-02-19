#include <iostream>

using namespace std;

int main(){
    int m=0,d=0;
    cin>>m;
    cin>>d;
    int s=((m*2+d)%3);
    switch (s){
    case 0:
        cout<<"普通";
        break;
    case 1:
        cout<<"吉";
        break;
    case 2:
        cout<<"大吉";
        break;
    }
    return 0;
}

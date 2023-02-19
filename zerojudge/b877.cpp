#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    a=b-a;
    if(a<0){a+=100;}
    cout<<a;
    return 0;
}

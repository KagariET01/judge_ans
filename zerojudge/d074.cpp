//c074
#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int n=0,pmax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a=0;
        cin>>a;
        pmax=max(pmax,a);
    }
    cout<<pmax;






    return 0;
}

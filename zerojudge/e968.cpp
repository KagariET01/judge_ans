#include <iostream>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    for(int i=n;i>=1;i--){
        if(i==a||i==b||i==c){continue;}
        cout<<"No. "<<i<<"\n";
    }






    return 0;
}

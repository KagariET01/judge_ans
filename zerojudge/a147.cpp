#include <iostream>

using namespace std;

int main(){
    int a;
    while(true){
        cin>>a;
        if(not(a)){
            break;
        }
        for(int i=1;(i<a);i++){
            if(i%7){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }






    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int m;
    cin>>m;
    while(true){
        int t;
        cin>>t;
        if(not(t)){
            break;
        }else{
            if(not(t%m)){
                cout<<t/m<<"\n";
            }else{
                cout<<m-t%m<<"\n";
            }
        }
    }






    return 0;
}

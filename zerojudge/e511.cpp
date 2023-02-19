#include <iostream>

using namespace std;

int main(){
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int addmin=0,addmax,xi=0;
        for(int j=0;j<n;j++){
            cin>>xi;
            if(j==0){
                addmin=xi;
                addmax=xi;
            }else{
                if(addmin>xi){
                    addmin=xi;
                }
                if(addmax<xi){
                    addmax=xi;
                }
            }
        }
        cout<<(addmax-addmin)*2<<"\n";
    }





    return 0;
}

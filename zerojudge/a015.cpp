#include <iostream>

using namespace std;

int main(){
    int a,b;
    while(cin>>a){
        cin>>b;
        int a_list[a][b];
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin>>a_list[i][j];
            }
        }
        for(int j=0;j<b;j++){
            for(int i=0;i<a;i++){
                cout<<a_list[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    return 0;
}

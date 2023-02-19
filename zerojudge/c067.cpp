#include <iostream>

using namespace std;

int main(){
    int a=0,i=0;
    while(true){
        cin>>a;
        if(a==0){
            break;
        }
        i++;
        cout<<"Set #"<<i<<"\n";
        int block_list[a],tot=0,o=0;
        for(int j=0;j<a;j++){
            cin>>block_list[j];
            tot+=block_list[j];
        }
        tot/=a;
        for(int j=0;j<a;j++){
            if(block_list[j]<tot){
                o+=tot-block_list[j];
            }
        }
        cout<<"The minimum number of moves is "<<o<<".\n";
    }




    return 0;
}

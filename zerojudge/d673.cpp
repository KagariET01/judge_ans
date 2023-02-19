#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int s,i=1;
    while(true){
        cin>>s;
        if(s<0){break;}
        cout<<"Case "<<i<<":\n";
        int nowq=0;
        nowq=s;
        int* qlist;
        qlist = (int*)malloc(12);
        for(int j=0;j<12;j++){
            cin>>qlist[j];
        }
        int use;
        for(int j=0;j<12;j++){
            cin>>use;
            if(nowq<use){
                cout<<"No problem. :(\n";
            }else{
                nowq-=use;
                cout<<"No problem! :D\n";
            }
            nowq+=qlist[j];
        }
        free(qlist);
        i++;
    }



    return 0;
}

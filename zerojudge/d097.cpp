#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int a=0,b=0,al[n]={0};
        for(int i=0;i<n;i++){
            al[i]=0;
        }
        for(int i=0;i<n;i++){
            cin>>b;
            if(i){

                al[int(abs(a-b))]+=1;

            }
            a=b;
        }
        a=1;
        for(int i=1;i<n;i++){
            if(al[i]==1){continue;}
            a=0;break;
        }
        if(a){cout<<"Jolly\n";}
        else{cout<<"Not jolly\n";}
    }
    return 0;
}


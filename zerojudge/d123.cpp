#include<iostream>
using namespace std;
int main(){
    int n,thi=1;
    while(cin>>n){
        int alist[n],right=1;
        for(int i=0;i<n;i++){
            cin>>alist[i];
            if(alist[i]<1 || (alist[i]<alist[i-1] && i>0)){right=0;}

        }
        int blist[alist[n-1]*2+1];
        for(int i=0;i<=alist[n-1]*2;i++){
            blist[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int tt=alist[i]+alist[j];
                if(blist[tt]>=1){
                    right=0;
                    break;
                }
                blist[tt]+=1;
            }
            if(right==0){break;}
        }
        if(right){
            cout<<"Case #"<<thi<<": It is a B2-Sequence.\n\n";
        }else{
            cout<<"Case #"<<thi<<": It is not a B2-Sequence.\n\n";
        }
        thi++;
    }
}

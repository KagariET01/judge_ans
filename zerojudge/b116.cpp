#include<iostream>
#include<cmath>
using namespace std;
void printlist(bool *lista,int b){
    for(int i=0;i<b;i++){
        cout<<*(lista+i)<<",";
    }
    cout<<endl;
}
bool fn_a(int *lista,int b,int c){
    /*{
        if(b==0){
            if(c!=*(lista+b)){return 0;}else{return 1;}
        }else if(c==0){
            return 1;
        }else if(c<0){
            return 0;
        }else{
            int aa=fn_a(lista,b-1,c-*(lista+b));
            int bb=fn_a(lista,b-1,c);
            return (aa|bb);
        }
    }*/
    {
        bool listb[b][c+1];
        for(int i=0;i<b;i++){
            for(int j=0;j<c+1;j++){
                listb[i][j]=false;
            }
        }
        for(int i=0;i<b;i++){listb[i][0]=true;}
        for(int j=0;j<c+1;j++){listb[0][j]=false;}
        listb[0][*lista]=true;
        for(int i=1;i<b;i++){
            for(int j=1;j<c+1;j++){
                if(*(lista+i)>c){
                    listb[i][j]=listb[i-1][j];
                }else{
                    bool aa=listb[i-1][j];
                    bool bb=listb[i-1][j-*(lista+i)];
                    listb[i][j]=(aa|bb);
                }
            }
        }
        /*for(int i=0;i<b;i++){
            printlist(listb[i],c+1);
        }cout<<endl;*/
        return listb[b-1][c];

    }
}
int main(){
    int m=0;
    int n;
    //cin>>m;
    while(cin>>m>>n){
        //cin>>m>>n;
        for(int i=0;i<m;i++){
            int lista[n],total=0;
            for(int j=0;j<n;j++){
                cin>>lista[j];
                total+=lista[j];
            }
            if(total%2==1){cout<<"No"<<endl;continue;}
            if(fn_a(lista,n,total/2)){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
        }
    }
    return 0;
}

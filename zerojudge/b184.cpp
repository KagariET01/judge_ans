#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,kg=100;
    while(cin>>a){
        int item_price[a];
        int item_kg[a];
        int lista[a+1][kg+1];
        for(int i=0;i<a;i++){
            cin>>item_kg[i];
            cin>>item_price[i];
        }
        for(int i=0;i<=a;i++){
            for(int j=0;j<=kg;j++){
                lista[i][j]=0;
            }
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=kg;j++){
                if(j<item_kg[i-1]){
                    lista[i][j]=lista[i-1][j];
                }else{
                    int aa=lista[i-1][j];//dont take
                    int bb=lista[i-1][j-item_kg[i-1]]+item_price[i-1];
                    lista[i][j]=max(aa,bb);
                    //cout<<"lista["<<i<<"]["<<j<<"]="<<lista[i][j]<<endl;
                }
            }
        }
        //{for(int ii=0;ii<=a;ii++){for(int ij=0;ij<=kg;ij++){cout<<lista[ii][ij]<<",";}cout<<endl;}cout<<endl;}
        cout<<lista[a][kg]<<endl;
    }
    return 0;
}
/*
test data==
 input=====
  5 10
  6 3 5 4 6
  2 5 4 2 3
 output====
  17
  5,3,1
===========
*/

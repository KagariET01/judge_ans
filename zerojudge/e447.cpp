#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    queue<int> lista;
    int count1;
    cin>>count1;
    for(int i=0;i<count1;i++){
        int a;
        cin>>a;
        if(a==1){
            int data;
            cin>>data;
            lista.push(data);
        }
        if(a==2){
            if(lista.size()>0){
                cout<<lista.front()<<endl;
            }else{
                cout<<"-1"<<endl;
            }
        }
        if(a==3&&(lista.size())>0){
            lista.pop();
        }
    }
    return 0;
}

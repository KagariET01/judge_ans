/*
[AC]
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>

using namespace std;

#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

/*num*/
bool debug=false;
bool iofast=true;
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    INT n;
    cin>>n;
    INT mp[n][n];
    for(INT i=0;i<n;i++){
        for(INT j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='b')mp[i][j]=-1;
            else mp[i][j]=(int)(c-'0');
        }
    }
    /*solve*/
    while(true){
        INT havenum=0;
        //橫向掃描
        for(INT i=0;i<n;i++){
            INT one=0;
            INT zero=0;
            for(INT j=0;j<n;j++){
                if(mp[i][j]==1){one++;havenum++;}
                if(mp[i][j]==0){zero++;havenum++;}
            }
            if(one*2==n){//數字為1的已經有一半ㄌ
                for(INT j=0;j<n;j++){//將還沒填上的數字填上0
                    if(mp[i][j]==-1){mp[i][j]=0;havenum++;}
                }
            }else if(zero*2==n){//反向，數字為0的已經有一半ㄌ
                for(INT j=0;j<n;j++){//將還沒填上的數字填上1
                    if(mp[i][j]==-1){mp[i][j]=1;havenum++;}
                }
            }
        }
        if(havenum==n*n)break;
        havenum=0;
        //直向掃描
        for(INT j=0;j<n;j++){
            INT one=0;
            INT zero=0;
            for(INT i=0;i<n;i++){
                if(mp[i][j]==1){one++;havenum++;}
                if(mp[i][j]==0){zero++;havenum++;}
            }
            if(one*2==n){//數字為1的已經有一半ㄌ
                for(INT i=0;i<n;i++){//將還沒填上的數字填上0
                    if(mp[i][j]==-1){mp[i][j]=0;havenum++;}
                }
            }else if(zero*2==n){//反向，數字為0的已經有一半ㄌ
                for(INT i=0;i<n;i++){//將還沒填上的數字填上1
                    if(mp[i][j]==-1){mp[i][j]=1;havenum++;}
                }
            }
        }
        if(havenum==n*n)break;
    }
    for(INT i=0;i<n;i++){
        if(i)cout<<endl;
        for(INT j=0;j<n;j++){
            if(j)cout<<" ";
            cout<<mp[i][j];
        }
    }
    return 0;
}

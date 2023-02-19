/*
[2/20]
[WA]
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
#define wassomething() empty() ^ true

/*num*/
bool debug=false;
bool iofast=true;
INT n,m;
INT mp[102][102];
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT dbg[102][102];
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    cin>>n>>m;
    for(INT i=1;i<=n;i++){
        for(INT j=1;j<=m;j++){
            cin>>mp[i][j];
            dbg[i][j]=0;
        }
    }
    /*solve*/
    INT swape=0;
    deque<PII> dc;
    for(INT i=1;i<=n;i++){
        for(INT j=1;j<=m;j++){
            INT other=0;
            for(INT k=0;k<4;k++){
                INT ni=i+mx[k];
                INT nj=j+my[k];
                if(1<=ni && ni<=n && 1<=nj && nj<=m){
                    if(mp[ni][nj]!=mp[i][j])other++;
                }
            }
            if(other>2){
                mp[i][j]=mp[i][j]^1;
                swape++;
                dbg[i][j]=1;
                for(INT k=0;k<4;k++){
                    INT ni=i+mx[k];
                    INT nj=j+my[k];
                    if(1<=ni && ni<=n && 1<=nj && nj<=m){
                        if(mp[ni][nj]!=mp[i][j]){
                            PII adder;
                            adder.first=ni;
                            adder.second=nj;
                            dc.push_back(adder);
                        }
                    }
                }
            }
        }
    }
    while(dc.wassomething()){
        PII now=dc.front();
        dc.pop_front();
        INT i=now.first;
        INT j=now.second;
            INT other=0;
            for(INT k=0;k<4;k++){
                INT ni=i+mx[k];
                INT nj=j+my[k];
                if(1<=ni && ni<=n && 1<=nj && nj<=m){
                    if(mp[ni][nj]!=mp[i][j])other++;
                }
            }
            if(other>2){
                mp[i][j]=mp[i][j]^1;
                swape++;
                dbg[i][j]=1;
                for(INT k=0;k<4;k++){
                    INT ni=i+mx[k];
                    INT nj=j+my[k];
                    if(1<=ni && ni<=n && 1<=nj && nj<=m){
                        if(mp[ni][nj]!=mp[i][j]){
                            PII adder;
                            adder.first=ni;
                            adder.second=nj;
                            dc.push_back(adder);
                        }
                    }
                }
            }

    }
    INT ans=swape*4;
    for(INT i=1;i<=n;i++){
        for(INT j=1;j<=m;j++){
            if(debug)cerr<<dbg[i][j];
            for(INT k=0;k<4;k++){
                INT ni=i+mx[k];
                INT nj=j+my[k];
                if(1<=ni && ni<=n && 1<=nj && nj<=m){
                    if(mp[ni][nj]!=mp[i][j])ans++;
                }
            }
        }
        if(debug)cerr<<endl;
    }
    cout<<ans/2;
    return 0;
}
/*
[I3]
6 7
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 1 0 0 0 1 0
0 1 0 1 0 1 0
0 1 1 1 0 1 0
0 0 0 0 0 1 0


*/

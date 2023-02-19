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
/*struct*/
struct s_item{
    INT h=0;
    INT v=0;
};
/*num*/
bool debug=false;
bool iofast=true;
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    INT m;
    cin>>m;
    vector<s_item> vec;
    s_item inin;
    inin.h=0;
    inin.v=0;
    vec.push_back(inin);
    while(cin>>inin.h>>inin.v){
        vec.push_back(inin);
    }
    /*solve*/
    INT vecs=vec.size();
    INT dp[m+1];
    for(INT j=0;j<=m;j++){
        dp[j]=0;
    }
    for(INT i=1;i<=vecs;i++){
        for(INT j=m;j>=vec[i].h;j--){
            dp[j]=max(dp[j],dp[j-vec[i].h]+vec[i].v);
        }
    }
    cout<<dp[m];
    return 0;
}
/*
[I2]
5000
547 916
958 793
815 158
914 486
906 971
98 142
127 958
965 960
279 422
633 801
[O2]
5963
*/

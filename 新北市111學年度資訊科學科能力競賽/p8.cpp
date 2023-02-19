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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
/*num*/
bool debug=false;
bool iofast=true;
/*fn*/
/*main*/
int main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    INT n;
    cin>>n;
    INT box[n];
    for(INT i=0;i<n;i++){
        cin>>box[i];
    }
    /*solve*/
    INT ans=0;
    for(INT i=0;i<n;i++){
        INT mn=box[i];
        INT p=i;
        for(INT j=i+1;j<n;j++){
            if(box[j]<mn){
                mn=box[j];
                p=j;
            }
        }
        ans+=(box[i]+box[p])*abs(i-p);
        ans%=1000000007;
        INT t=box[i];
        box[i]=box[p];
        box[p]=t;
        if(debug)cerr<<ans<<endl;
    }
    cout<<ans;
    return 0;
}

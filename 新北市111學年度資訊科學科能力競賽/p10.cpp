/*
[WA]
[2/20]
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
#define endl "\n"

/*num*/
bool debug=true;
bool iofast=true;
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    INT n;
    cin>>n;
    vector<INT> a;
    INT ans=0;
    for(INT i=0;i<n;i++){
        INT inin;
        cin>>inin;
        a.push_back(inin);
    }
    /*solve*/
    while(a.size()>1){
        /*
        vector<INT>::iterator it=a.begin();
        vector<INT>::iterator itb=it;
        itb++;
        vector<INT>::iterator readyadd;
        vector<INT>::iterator readyaddb;
        INT mn=10000;
        while(itb!=a.end()){
            if(*it+*itb<mn){
                mn=*it+*itb;
                readyadd=it;
                readyaddb=itb;
            }
            it++;
            itb++;
        }
        ans+=mn;
        *readyadd=mn;
        *readyaddb=mn;
        a.erase(readyadd,readyadd);
        if(debug)cerr<<ans<<endl;
        */
        INT it=0;
        INT mn=10000;
        for(INT i=0;i<a.size()-1;i++){
            if(a[i]+a[i+1]<mn){
                mn=a[i]+a[i+1];
                it=i;
            }
        }
        ans+=mn;
        a[it+1]=mn;
        a.erase(a.begin()+it);
        if(debug)cerr<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
/*
[I1]
4
3 2 1 4
[O1]
19
[I2]
10
3 4 8 7 1 6 9 2 10 5
[O2]
179
*/

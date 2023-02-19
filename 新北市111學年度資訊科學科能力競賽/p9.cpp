/*
[TLE]
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
    INT m,x;
    cin>>m>>x;
    vector<INT> base[m];
    for(INT i=0;i<m;i++){
        INT a;
        cin>>a;
        for(INT j=0;j<a;j++){
            INT inin;
            cin>>inin;
            base[i].push_back(inin);
        }
    }
    if(debug)cerr<<"solve"<<endl;
    /*solve*/
    /*
    for(INT i=0;i<x;i++){
        if(i)cout<<endl;
        INT a;
        cin>>a;
        set<INT> se;
        for(INT j=0;j<a;j++){
            INT inin;
            cin>>inin;
            inin--;
            for(INT k:base[inin]){
                se.insert(k);
            }
        }
        cout<<se.size();
    }
    */
    vector<INT> addlist[m];
    set<INT>se[x];
    for(INT i=0;i<x;i++){
        INT a;
        cin>>a;
        for(INT j=0;j<a;j++){
            INT inin;
            cin>>inin;
            inin--;
            addlist[inin].push_back(i);
        }
    }
    for(INT i=0;i<m;i++){
        for(INT k:base[i]){
            for(INT j:addlist[i]){
                se[j].insert(k);
            }
        }
    }
    for(INT i=0;i<x;i++){
        if(i)cout<<endl;
        cout<<se[i].size();
    }
    return 0;
}
/*
[I1]
5 2
6 2 3 7 8 60 500000
5 7 8 60 65 50001
4 60 65 50001 1000
5 3 8 60 50001 499999
3 60 1000 50001
2 1 4
3 3 4 5
[O1]
8
7
*/

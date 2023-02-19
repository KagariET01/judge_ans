/*
[]
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
#define FINT double
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PFIFI pair<FINT,FINT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"

/*num*/
bool debug=false;
bool iofast=true;
INT n,m,k,l;
//N (1 ≤ N ≤ 100)代表 判斷一個新士兵是否存活需考慮的鄰近士兵數量
//M (1 ≤ M ≤ 10)表示有多少不同勢力
//K (1 ≤ K ≤ 10,000)為地圖上士兵數量
//L (1 ≤ L ≤ 10,000)為有多少次新士兵投放結果需要做判斷
//map<INT,vector<PFIFI> > omp;//omp[power]={x,y}
vector<pair<INT,PFIFI> > omp;
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    cin>>n>>m>>k>>l;
    for(INT i=0;i>k;i++){
        pair<INT,PFIFI> adder;
        PFIFI fadd;
        cin>>adder.first;
        cin>>fadd.first>>fadd.second;
        adder.second=fadd;
        omp.push_back(adder);
    }
    /*solve*/
    for(INT i=0;i<l;i++){
        if(i)cout<<endl;
        INT p;
        FINT x,y;
        cin>>p>>x>>y;
        vector<PII> vec;
        for(INT j=0;j<k;j++){
            PII adder;
            adder.second=omp[j].first;

            FINT aa=abs((omp[j].second).first-x);
            FINT bb=abs((omp[j].second).second-y);
            adder.first=aa*aa+bb*bb;
            vec.push_back(adder);
        }
        sort(vec.begin(),vec.end());
        INT powerlist[m+1];
        for(INT j=0;j<=m;j++){
            powerlist[j]=0;
        }
        powerlist[p]++;
        INT mx=0;
        INT me=1;
        for(INT j=0;j<n;j++){
            powerlist[vec[j].second]++;
            if(vec[j].second==p)me++;
            else mx=max(powerlist[vec[j].second],mx);
        }
        if(me>mx)cout<<"1";
    }
    return 0;
}
/*
新頭放的士兵
最近的n個士兵裡
同勢力的士兵要比其他的多
新兵才能活下來
*/
/*
[I1]
4 4 15 3
1 -4 5
1 -2 5
2 -6 1
1 -3 1
4 -4 -2
3 -2 -2
1 2 -3
3 4 -1
1 2 4.1
3 4 4
4 2 3
4 3 3
3 5 2
3 1 1
2 3 1
1 -7 -4
4 3 4.5
2 5 0.5
[O1]
1
1
0
*/


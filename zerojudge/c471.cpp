/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid=c471
[貪心][排序]
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
struct s_item{
	INT w=0;
	INT f=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
bool sorter(s_item a,s_item b){
	return a.w*b.f<a.f*b.w;//左端=頂端
	/*
	如果結果為true
	表[b在下面所耗的能量]<[a在下面所耗的能量]
	*/
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	cin>>n;
	s_item it[n];
	for(INT i=0;i<n;i++){
		cin>>it[i].w;
	}
	for(INT i=0;i<n;i++){
		cin>>it[i].f;
	}
	/*solve*/
	sort(it,it+n,sorter);
	INT allw=0;
	INT ans=0;
	for(INT i=0;i<n-1;i++){
		allw+=it[i].w;
		ans+=it[i+1].f*allw;
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

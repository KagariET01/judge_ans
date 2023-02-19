/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
[TLE 98%]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define FIR first
#define SEC second
#define DBG if(debug)
#define ifif if
#define elif else if
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
const INT mxn=1e5; 
INT n,m;
vector<INT> tree[mxn+2];
INT flag[mxn+2];
INT na[3]={0,0,0};
/*fn定義*/
bool DFS(INT p,INT g){
	flag[p]=g;
	na[g]++;
	bool re=true;
	for(INT i:tree[p]){
		if(flag[i]){
			if(flag[i]==g)return false;
			else continue;
		}
		re&=DFS(i,3-g);
		if(!re)return re;
	}
	return re;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n>>m;
	while(m--){
		INT a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	/*solve*/
	INT ans=0;
	for(INT i=1;i<=n;i++){
		if(flag[i])continue;
		na[1]=na[2]=0;
		if(!DFS(i,1)){
			ans=0;break;
		}else{
			ans+=min(na[1],na[2]);
		}
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

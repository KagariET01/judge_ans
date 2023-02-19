/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>

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
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
/*fn定義*/
const INT mxn=5e5;
vector<INT> tree[mxn+2];
INT indo[mxn+2];
INT mxindo=0;
INT mxindop=0;
vector<INT> dpsort;

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

void dfs(INT np,INT lp=-1,INT nwdp=0){
	if(indo[np]<=(INT)1){
		dpsort.push_back(nwdp);
	}else{
		for(INT i:tree[np]){
			if(i==lp)continue;
			dfs(i,np,nwdp+1);
		}
	}
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=1;
	while(t--){
		INT n=read(INT);
		loop(i,0,n-1){
			INT a,b;
			cin>>a>>b;
			tree[a].push_back(b);
			tree[b].push_back(a);
			indo[a]++;
			indo[b]++;
			if(indo[a]>mxindo){
				mxindo=indo[a];
				mxindop=a;
			}elif(indo[b]>mxindo){
				mxindo=indo[b];
				mxindop=b;
			}
		}
		dfs(mxindop);
		INT st=0;
		INT nd=0;
		INT allrun=dpsort.size();
		for(INT i=0;i<allrun;i++){
			if(dpsort[i]>st){
				swap(st,dpsort[i]);
			}
		}
		for(INT i=0;i<allrun;i++){
			if(dpsort[i]>nd){
				swap(nd,dpsort[i]);
			}
		}
		INT ans=nd+max(nd,st-nd);
		cout<<ans<<endl;
	}
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

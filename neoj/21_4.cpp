/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[暴力解+structe優化(???)+list優化(?????)]

[result]		[]
[time]			[]
[mem]				[]
[challenge]	[]
[sub time]	[YYYY/MM/DD HH:MM:SS]
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
#define INT int
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
/*num*/
bool debug=0;
bool iofast=true;	
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

struct node{
	INT pID=0;
	node *l,*r;
	node(){
		l=NULL;
		r=NULL;
	}
};

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n;
	while(cin>>n){
		/*CIN*/
		INT m=read(INT);
		vector<PII> todo(m);
		for(INT i=0;i<m;i++){
			todo[i]={read(INT),read(INT)};
		}
		/*set*/
		INT ap[n+2];
		for(INT i=1;i<=n;i++){
			ap[i].pID=i;
			if(1<i){
				ap[i].l=&(ap[i-1]);
			}
			if(i<n){
				ap[i].r=&(ap[i+1]);
			}
		}
		/*solve*/
		for(PII i:todo){
			if(i.FIR){//衝刺
				INT inin=i.SEC;
				if((ap[inin]).l==NULL)continue;
				node *nxt=((ap[inin]).l);
			}else{//kill
				INT inin=i.SEC;
				((ap[inin]).l).r=(ap[inin]).r;
				((ap[inin]).r).l=(ap[inin]).l;
			}
		}
		bool outer=false;
		for(){
		}
		cout<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

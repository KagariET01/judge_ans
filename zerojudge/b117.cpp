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
/*num*/
bool debug=0;
bool iofast=true;
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

const INT mxm=1e6;
INT toroad[mxm+1];
INT bkroad[mxm+1];
vector<INT> tre[mxm+1];
vector<INT> bktre[mxm+1];
map<PII,INT> lne;
map<PII,INT> bklne;

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT m,n;
	while(cin>>m>>n){
		memset(toroad,-1,sizeof(toroad));
		memset(bkroad,-1,sizeof(bkroad));
		/*CIN*/
		for(INT i=0;i<n;i++){
			INT p,q,r;
			cin>>p>>q>>r;
			tre[p].push_back(q);
			lne[{p,q}]=r;
			bktre[q].push_back(p);
			bklne[{q,p}]=r;
		}
		/*solve*/
		toroad[1]=0;
		deque<INT> dq;
		dq.push_back(1);
		bool cansolve=true;
		while(dq.wassomething()){
			INT nw=dq.front();
			dq.pop_front();
			for(INT i:tre[nw]){
				INT newroad=toroad[nw]+lne[{nw,i}];
				if(toroad[i]==-1 || toroad[i]>newroad){
					toroad[i]=newroad;
					dq.push_back(i);
				}
			}
		}

		INT ans=0;
		for(INT i=1;i<=m && cansolve;i++){
			if(toroad[i]==-1)cansolve=false;
			ans+=toroad[i];
		}
		
		if(!cansolve){
			cout<<0<<endl;
			continue;
		}

		bkroad[1]=0;
		dq.push_back(1);
		while(dq.wassomething()){
			INT nw=dq.front();
			dq.pop_front();
			for(INT i:bktre[nw]){
				INT newroad=bkroad[nw]+lne[{nw,i}];
				if(bkroad[i]==-1 || bkroad[i]>newroad){
					bkroad[i]=newroad;
					dq.push_back(i);
				}
			}
		}


		for(INT i=1;i<=m && cansolve;i++){
			if(bkroad[i]==-1)cansolve=false;
			ans+=bkroad[i];
		}
		if(!cansolve){
			cout<<0<<endl;
			continue;
		}

		cout<<ans<<endl;
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

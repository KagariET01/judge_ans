/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[]

[result]		[TLE]
[time]			[3450]
[mem]				[16600]
[challenge]	[232530]
[sub time]	[2023/03/10 16:17:27]
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
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*CIN*/
		INT n=read(INT);
		INT lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i];
		}
		/*solve*/
		deque<INT> dq;
		INT ans=0;
		for(INT pnt=0;pnt<n;pnt++){
			INT i=lst[pnt];
			INT nwadd=0;
			if(pnt){
				deque<INT>::iterator it=dq.end();
				INT mx=i;
				while(true){
					it--;
					if(mx<=i){mx=*it;}
					DBG cerr<<mx<<" ";
					if(*it>mx)break;
					nwadd++;
					if(it==dq.begin() || mx>i)break;
				}
				DBG cerr<<endl;
				if(nwadd<=0)nwadd=1;
				ans+=nwadd;
				while(!dq.empty() && dq.back()<i){
					DBG cerr<<dq.back()<<" ";
					dq.pop_back();
				}
			}
			dq.push_back(i);
			DBG for(INT j:dq){
				cerr<<j<<" ";
			}
			DBG cerr<<":"<<nwadd<<endl;
			DBG cerr<<endl<<endl;
		}
		DBG cerr<<endl;
		cout<<ans<<endl;
		DBG cerr<<endl;
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

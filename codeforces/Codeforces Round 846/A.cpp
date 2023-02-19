/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
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

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
		vector<INT> onelist;
		INT onesize=0;
		vector<INT> twolist;
		INT twosize=0;
		bool noans=true;
		for(INT i=1;i<=n;i++){
			INT inin=read(INT);
			if(inin%2){
				onelist.push_back(i);
				onesize++;
			}else{
				twolist.push_back(i);
				twosize++;
			}
			if(noans){
				if(onesize>=3){
					cout<<"YES"<<endl;
					cout<<onelist[0]<<" ";
					cout<<onelist[1]<<" ";
					cout<<onelist[2];
					cout<<endl;
					noans=false;
				}
				if(onesize>=1&&twosize>=2){
					cout<<"YES"<<endl;
					cout<<onelist[0]<<" ";
					cout<<twolist[0]<<" ";
					cout<<twolist[1];
					cout<<endl;
					noans=false;
				}
			}
		}
		if(noans){
			cout<<"NO"<<endl;
		}
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

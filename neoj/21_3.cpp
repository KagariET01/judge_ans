/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[neoj]			[Q]https://neoj.sprout.tw/problem/ [ID]

[暴力解+deque優化(?)+To do list優化(???]

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

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n;
	while(cin>>n){
		/*CIN*/
		INT m=read(INT);
		vector<PII> todo(m);
		bool needpsh[n+1];
		set0(needpsh);
		for(INT i=0;i<m;i++){
			todo[i]={read(INT),read(INT)};
			needpsh[todo[i].SEC]=true;
		}
		deque<INT> que;
		map<INT,deque<INT>::iterator> allit;
		for(INT i=1;i<=n;i++){
			que.push_back(i);
			if(needpsh[i])allit[i]=que.end()-1;
		}
		/*solve*/
		for(PII i:todo){
			if(i.FIR){//衝刺
				INT inin=i.SEC;
				if(inin==que.front()){
					continue;
				}else{
					deque<INT>::iterator it=allit[inin];
					deque<INT>::iterator it2=it-1;
					deque<INT>::iterator fst=que.begin();
					deque<INT>::iterator ed=que.end();
					if(fst<=it && it<ed && fst<=it2 && it2<ed){
						swap(*it,*it2);
						allit[*it]=it;
						allit[*it2]=it2;
						//cerr<<*allit[inin];
					}
				}
			}else{
				INT inin=i.SEC;
				que.erase(allit[inin]);
			}
		}
		bool outer=false;
		for(INT i:que){
			if(outer){
				cout<<" ";
			}
			outer=true;
			cout<<i;
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

/*
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=a454
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
/*struct定義*/
/*fn定義*/

INT n;
const INT mxn=1000;
vector<INT> tre[mxn+2];
INT pr[mxn+2];
INT ans[mxn+2];//節點還沒被走過時：它需要等多久才能開始，節點走過後：該工程完成時是甚麼時候
INT incount[mxn+2];

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

deque<INT> dq;

void bfs(INT n){
	ans[n]+=pr[n];//將自己花費的時間加進去
	for(INT nxt:tre[n]){
		ans[nxt]=max(ans[nxt],ans[n]);
		incount[nxt]--;
		if(incount[nxt]<=0){
			dq.push_back(nxt);
		}
	}
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*re0*/
		for(INT i=0;i<mxn+2;i++){
			tre[i].clear();
		}
		memset(pr,0,sizeof(pr));
		set0(ans);
		set0(incount);
		dq.clear();
		/*CIN*/
		n=read(INT);//節點數量
		for(INT i=1;i<=n;i++){
			pr[i]=read(INT);
			INT linkout=read(INT);
			while(linkout--){
				INT inin=read(INT);
				tre[i].push_back(inin);//連出去
				incount[inin]++;//入度++
			}
		}
		/*solve*/
		for(INT i=1;i<=n;i++){
			if(incount[i]==0){
				dq.push_back(i);
			}
		}
		while(dq.wassomething()){
			INT nw=dq.back();
			dq.pop_back();
			bfs(nw);
		}
		INT outer=0;
		loop(i,1,n+1){
			outer=max(outer,ans[i]);
		}
		cout<<outer<<endl;
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
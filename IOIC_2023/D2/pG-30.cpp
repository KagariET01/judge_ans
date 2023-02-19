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
struct dsu{
	vector<INT> vec;//vec[i]紀錄i連到哪裡
	vector<set<INT>> se;//se[i]記錄所有連到i的點編號
	void init(INT n){//初始化
		se.clear();
		se.resize(n+1);
		vec.clear();
		vec.resize(n+1);
		for(INT i=0;i<=n;i++){
			vec[i]=i;
			se[i].clear();
		}
	}
	INT find(INT n){//查詢編號
		if(vec[n]==n){
			return n;
		}else{
			INT re=find(vec[n]);//找出最終老大
			se[vec[n]].erase(n);//將n連到re，所以要把vec[n]的被動連線解除掉
			vec[n]=re;//將n連到re
			se[re].insert(n);//re被n連
			return re;
		}
	}
	void merge(INT a,INT b){//合併兩者
		INT aboss=find(a);
		INT bboss=find(b);
		vec[aboss]=bboss;//將a樹連到b樹
		se[bboss].insert(aboss);//b樹被a連
	}
	void erase(INT n){//將n孤立
		vec[n]=n;//將自己連到自己
		INT othboss=*(se[n].begin());//其他的老大就用第一個連到n的人來當
		for(INT i:se[n]){
			vec[i]=othboss;
			se[othboss].insert(i);
		}
		se[n].clear();
	}
};
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

struct dta{
	INT v=0;
	INT l=0;
	INT r=0;
};

bool vser(dta a,dta b){
	return a.v>b.v;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=1;
	while(t--){
		INT n=read(INT);
		INT a[n+1];
		loop(i,1,n+1){
			cin>>a[i];
		}
		vector<dta> vec;
		loop(i,1,n+1){
			loop(j,i+1,n+1){
				dta ininer={__gcd(a[i],a[j]),i,j};
				vec.push_back(ininer);
			}
		}
		sort(vec.begin(),vec.end(),vser);
		dsu ds;
		ds.init(n);
		INT ans=0;
		INT count=n-1;
		for(dta i:vec){
			if(ds.find(i.l)!=ds.find(i.r)){
				ans+=i.v;
				ds.merge(i.l,i.r);
				count--;
			}
			if(count)continue;
			else break;
		}
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

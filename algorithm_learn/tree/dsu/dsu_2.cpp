/*
[temp_dsu]
[並查集]
[L71-L108]
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
























/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
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

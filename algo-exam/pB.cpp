/*
[2023 算法班歡樂報名預試]pB
[AC]
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;

vector<INT> loop[30];

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
	/*CIN*/
	string p=reader<string>();
	INT n=reader<INT>();
	INT q=reader<INT>();
	string s=reader<string>();
	/*solve*/
	INT p_I[26];
	for(INT i=0;i<26;i++){
		p_I[i]=p[i]-'A';
	}
	INT s_I[n];
	for(INT i=0;i<n;i++){
		s_I[i]=s[i]-'A';
	}
	for(INT i=0;i<26;i++){//初始字母
		INT now=i;
		for(INT j=0;j<26;j++){
			now=p_I[now];
			loop[i].push_back(now);
			if(now==i)break;
		}
	}
	while(q--){
		INT t=read(INT);
		INT x=read(INT)-1;
		INT nw=s_I[x];
		while(t){
			if(t>=loop[nw].size()){
				if(nw==loop[nw].back()){
					t%=loop[nw].size();
				}
				else{
					t-=loop[nw].size();
					nw=loop[nw].back();
				}
			}
			else{
				nw=loop[nw][t-1];
				t=0;
				break;
			}
		}
		char c='A'+nw;
		cout<<c<<endl;
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

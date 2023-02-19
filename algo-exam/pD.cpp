/*
[2023 算法班歡樂報名預試]pD
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

INT mp[2001][2001];
INT paint[3][4002];
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
	INT n=read(INT);
	INT q=read(INT);
	while(q--){
		INT op=read(INT);
		INT ii=read(INT);
		paint[op][ii]=max(paint[op][ii],read(INT));
	}
	/*re:0*/
	/*solve*/
	/*for(INT j=0;j<n;j++){
		for(INT i=0;i<n;i++){
			mp[i][j]=max(paint[2][i+j+1],paint[1][((n-1)-i)+j+1]);
			cerr<<((n-1)-i)+j+1<<endl;
		}
	}*/
	for(INT i=0;i<n;i++){
		if(i)cout<<endl;
		for(INT j=0;j<n;j++){
			if(j)cout<<" ";
			cout<<max(paint[2][i+j+1],paint[1][((n-1)-j)+i+1]);
		}
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

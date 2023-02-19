/*
[AtCoder]		[Q]https://atcoder.jp/contests/abc178/tasks/abc178_e
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
	INT n=read(INT);
	INT admax=0;
	INT admin=0;
	INT mnmax=0;
	INT mnmin=0;
	for(INT i=0;i<n;i++){
		INT a=read(INT),b=read(INT);
		if(i){
			admax=max(admax,a+b);
			admin=min(admin,a+b);
			mnmax=max(mnmax,a-b);
			mnmin=min(mnmin,a-b);
		}else{
			admax=admin=a+b;
			mnmax=mnmin=a-b;
		}
	}
	/*solve*/
	cout<<max(admax-admin,mnmax-mnmin)<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

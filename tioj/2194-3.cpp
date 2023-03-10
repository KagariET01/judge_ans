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

const INT mxn=1005;
const INT mxm=1e9;
INT tt[mxn+1];
INT tadd[mxn+2];
INT s[mxn+1];
INT d[mxn+1];
INT n,m;
INT dmx=0;

INT realscore(INT e,INT x,INT tt){
	INT re=0;
	INT mx=0;
	for(INT i=1;i<=e;i++){
		if(d[i]==0){
			mx=max(mx,s[i]);
			continue;
		}
		INT a=s[i]-x;
		INT t=a/d[i];
		INT mn=s[i]-d[i]*(t-1);
		re+=(s[i]+mn)*t/2;
		tt-=t;
	}
	return re+tt*mx;
}


PII dust_to_time(int e, int x) {//e代表考慮的房間數量,x代表一常數,此函數會回傳有多少時間可以掃到>x的灰塵(FIR),以及有多少時間可以掃到=x的灰塵(SEC)
	long long a = 0, b = 0;
	for (int i=1; i<=e; i++){
		if (s[i] >= x) {//枚舉所有的房間
			if (d[i] == 0) {//如果有一個房間的灰塵量永不減少
				return PII (mxm,mxm);
			}
			a += (s[i] - x) / d[i] + 1;//計算這房間在幾分鐘前是有>=x的灰塵量
			if (s[i] % d[i] == x % d[i]) { // 最小的那分鐘剛好掃到的灰塵量是 x
				b++;
				a--;
			}
		}
	}
	return {a, b};//回傳a,b
}


INT solve(){
	INT re=0;
	for(INT i=1;i<=n;i++){
		INT l=0,r=dmx;
		INT k=m-tadd[i];
		while(l<r){
			INT nw=l+(r-l)/2;
			PII ab=dust_to_time(i,nw);
			if(ab.FIR+ab.SEC>=k){
				l=nw+1;
			}else{
				r=nw;
			}
		}
		re=max(re,realscore(i,r,k));
	}
	return re;
}


















/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		cin>>n>>m;
		for(INT i=2;i<=n;i++){
			cin>>tt[i];
			tadd[i]=tadd[i-1]+tt[i];
		}
		for(INT i=1;i<=n;i++){
			cin>>s[i];
		}
		for(INT i=1;i<=n;i++){
			cin>>d[i];
			dmx=max(dmx,d[i]);
		}
		/*solve*/
		cout<<solve()<<endl;
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

/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]https://codeforces.com/contest/1792/problem/C
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

/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

template<typename TPE>auto LIS(TPE a,INT N=0){
	if(N==0)N=(int)a.size();
	INT dp[N+1];dp[0]=1;
	TPE vec;vec.push_back(a[0]);
	INT L=1;
	for(INT i=1;i<N;i++){
		if(a[i]>vec.back()){
			vec.push_back(a[i]);
			L++;
			dp[i]=L;
		}
		else{
			auto it=lower_bound(vec.begin(),vec.end(),a[i]);
			*it=a[i];
			dp[i]=(int)(it-vec.begin()+1);
		}
	}
	return L;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
		vector<INT> p;
		for(INT i=0;i<n;i++){
			p.push_back(read(INT));
		}
		INT lisans=LIS(p,n);
		cout<<(n-lisans+1)/2<<endl;
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

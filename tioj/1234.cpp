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

vector<PII> vec;

bool vser(PII a,PII b){
	return (double)a.SEC/a.FIR<(double)b.SEC/b.FIR;//if a<b  1/a > 1/b
}

void doadd(PII a){
	if(__gcd(a.FIR,a.SEC)>1)return;
	vec.push_back(a);
}

P(INT,PII) solve(INT n){
	for(INT i=2;i<=n;i++){//分母
		for(INT j=1;j<i;j++){//分子
			doadd({j,i});
		}
	}
	sort(vec.begin(),vec.end(),vser);
	return {vec.size(),vec[max(vec.size()-n,(UINT)0)]};
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n;
	while(cin>>n){
		vec.clear();
		/*CIN*/
		/*solve*/
		if(n==2){
			cout<<1<<endl;
			cout<<"1/2"<<endl;
			continue;
		}
		P(INT,PII) ans=solve(n);
		cout<<ans.FIR<<endl;
		cout<<ans.SEC.FIR<<"/"<<ans.SEC.SEC<<endl;
		
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

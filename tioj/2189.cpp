/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2189
[WA]
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
const INT mxn=1e5;
vector<INT> vec[mxn+1];
map<PII,INT> lne;
P(INT,PII) dfs(INT n,INT lst){
	INT llst[6];
	set0(llst);
	for(INT i:vec[n]){
		if(i==lst){
			continue;
		}
		P(INT,PII) get=dfs(i,n);
		INT lneadd=lne[{n,i}];
		INT a=get.FIR+lneadd;
		INT b=get.SEC.FIR+lneadd;
		INT c=get.SEC.SEC+lneadd;
		llst[0]=llst[1]=llst[2]=0;
		if(llst[3]!=a && llst[4]!=a && llst[5]!=a)llst[0]=a;
		if(llst[3]!=b && llst[4]!=b && llst[5]!=b && llst[0]!=b)llst[1]=b;
		if(llst[3]!=c && llst[4]!=c && llst[5]!=c && llst[0]!=c && llst[1]!=c)llst[2]=c;
		sort(llst,llst+5);
	}
	return {llst[2],{llst[3],llst[4]}};
}




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		for(INT i=0;i<n-1;i++){
			INT u,v,w;
			cin>>u>>v>>w;
			vec[u].push_back(v);
			vec[v].push_back(u);
			lne[{u,v}]=lne[{v,u}]=w;
		}
		/*solve*/
		P(INT,PII) reans=dfs(0,-1);
		INT ans[3]={reans.FIR+reans.SEC.FIR,reans.FIR+reans.SEC.SEC,reans.SEC.FIR+reans.SEC.SEC};
		sort(ans,ans+3);
		if(ans[2]==ans[1])cout<<ans[0]<<endl;
		else cout<<ans[1]<<endl;
		cerr<<ans[0]<<","<<ans[1]<<","<<ans[2]<<endl;
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

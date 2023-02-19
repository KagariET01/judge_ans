/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1196
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

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		INT mp[n+1][n+1];
		memset(mp,-1,sizeof(mp));
		for(INT i=1;i<=n;i++){
			string s=read(string);
			for(INT j=1;j<=n;j++){
				mp[i][j]=(INT) ( (s[j-1]=='X')?(-1):(s[j-1]-'0') );
			}
		}
		/*solve*/
		INT dp[n+1][n+1];
		memset(dp,-1,sizeof(dp));
		mp[1][1]=mp[n][n]=dp[1][1]=0;
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=n;j++){
				if(i==1 && j==1)continue;
				if(mp[i][j]<=-1)continue;
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(dp[i][j]>=0){
					dp[i][j]+=mp[i][j];
				}
			}
		}
		if(dp[n][n]>=0)cout<<dp[n][n]<<endl;
		else cout<<"X"<<endl;
		if(false)for(INT i=0;i<n+1;i++){
			for(INT j=0;j<n+1;j++){
				cerr<<dp[i][j]<<" ";
			}
			cout<<endl;
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
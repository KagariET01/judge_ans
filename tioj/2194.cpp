/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2194
[30/100]
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






/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT),m=read(INT);
		INT t[n+1];
		INT tadd[n+1];
		INT s[n+1];
		INT d[n+1];
		t[1]=0;
		tadd[1]=0;
		INT allwk=0;
		for(INT i=2;i<=n;i++){
			cin>>t[i];
			allwk+=t[i];
			tadd[i]=allwk;
		}
		for(INT i=1;i<=n;i++){
			cin>>s[i];
		}
		for(INT i=1;i<=n;i++){
			cin>>d[i];
			s[i]+=d[i];
		}
		/*solve*/
		INT dp[n+1][m+1];//dp[房間][時間]
		set0(dp);
		INT mxdo[n+1];
		for(INT i=1;i<=n;i++){
			if(d[i]==0)mxdo[i]=1e9;
			else mxdo[i]=(s[i]+d[i]-1)/d[i];
		}
		INT ans=0;
		for(INT i=1;i<=n;i++){//i=room id
			for(INT j=tadd[i];j<=m;j++){//j=time，j分鐘結束後，我能得到多少
				if(j<tadd[i])continue;//如果目前的時間不夠機器人到這邊就continue
				INT ft=s[i]-d[i];//做第一次可以獲得多少(這很重要，待會可以用高斯計算)
				INT &nwdp=dp[i][j];//只是宣告nwdp
				nwdp=max(nwdp,dp[i-1][j-t[i]]);//如果我甚麼都不做，只是從上個房間走過來，那我最多可以拿到多少
				for(INT wkt=1;wkt<=min(mxdo[i],j-tadd[i]);wkt++){//wkt=how many time bot work at here
				//min(mxdo[i],j-tadd[i])的意思如下：
				//mxdo很明顯就是你最多只能在這邊掃多久
				//tadd[i]代表你走過來最早是甚麼時候
				//例如t[2]=1 則tadd[2]=1，代表你走過來時已經是t=1了(如果你t=0就直接走過來)
				//j-tadd[i]代表你走過來後，還剩多少時間可以做
					nwdp=max(
						nwdp,
						dp[i-1][j-t[i]-wkt]+
							//j-t[i]-wkt代表從上個房間走過來，並打掃wkt分鐘
							((ft+s[i]-d[i]*wkt)*wkt)/2
					);
				}
				if(j==m){
					ans=max(ans,nwdp);
				}
			}
		}
		cout<<ans<<endl;
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

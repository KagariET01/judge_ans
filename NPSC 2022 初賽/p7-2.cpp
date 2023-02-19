/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
[]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

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
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=true;
bool iofast=true;
const INT maxnm=1000;
PII dp[maxnm+1][maxnm+1];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n,m;
	cin>>n>>m;
	INT a[n],b[m];
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	for(INT i=1;i<=m;i++){
		cin>>b[i];
	}
	/*solve*/
	INT now=0;
	INT ans=-1;
	for(INT i=0;i<=n;i++){
		for(INT j=0;j<=m;j++){
			dp[i][j]={0,0};

			
				bool up=true;//上面往下走，可否過
				PII readyupdp;//儲存由上往下走，dp要儲存甚麼
				PII &updp=dp[i-1][j];//上面的dp
			if(i-1>=0){
				if(updp.first==-1)up=false;//如果上面不通，那就不能從上面走下來
				else{
					readyupdp=updp;//由上往下走
					readyupdp.second+=a[i];//由上往下走
					if(readyupdp.second<0)up=false;//如果走下來，值會變成負數，代表不能走
					else {//如果不會變成負數，代表可以走
						readyupdp.first=max(readyupdp.first,readyupdp.second);//走完後把mx算出來
					}
				}
			}else up=false;

				bool dn=true;//上面往下走，可否過
				PII readydndp;//儲存由上往下走，dp要儲存甚麼
				PII &dndp=dp[i][j-1];//上面的dp
			if(j-1>=0){
				if(dndp.first==-1)dn=false;//如果上面不通，那就不能從上面走下來
				else{
					readydndp=dndp;//由上往下走
					readydndp.second+=b[j];//由上往下走
					if(readydndp.second<0)dn=false;//如果走下來，值會變成負數，代表不能走
					else {//如果不會變成負數，代表可以走
						readydndp.first=max(readydndp.first,readydndp.second);//走完後把mx算出來
					}
				}
			}else dn=false;

			if(up)dp[i][j]=readyupdp;
			if(dn)dp[i][j]=readydndp;
			if(up && dn)dp[i][j]=min(readyupdp,readydndp);
		}
	}
	ans=dp[n][m].first;
	cout<<ans<<endl;
	if(debug){
		cerr<<endl;
		for(INT i=0;i<=n;i++){
			for(INT j=0;j<=m;j++){
				cerr<<dp[i][j].first<<","<<dp[i][j].second<<" ";
			}
			cerr<<endl;
		}
	}
	return 0;
}

/*
[I1]
3 1
10 20 -30
15
[O1]
30

[I2]
2 7
100 -50
1 1 1 1 1 1 -6
[O2]
100

[I3]
2 3
2 -101
100 50 -51
[O3]
102

[I4]
2 2
1000 -100
1 -100
[O4]
1000
*/

/*think*/
/*

*/

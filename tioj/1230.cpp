/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1230
[80% TLE]
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
#define INT int
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
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}
const INT mxn=7;
INT mp[mxn+1][mxn+1];
bool fmv[mxn+1][mxn+1];
bool smv[mxn+1][mxn+1];
bool allmv[mxn+1][mxn+1];
INT n,m;
INT apans=0;
INT bpans=0;


void dfs(INT x=0,INT y=0,INT p=0,INT nwcoin=0){
	if(x<0 || x>=n || y<0 || y>=m)return;
	//偵測是否走過
	if(p==0){
		if(fmv[x][y])return;
		else fmv[x][y]=true;
	}else{
		if(smv[x][y])return;
		else smv[x][y]=true;
	}
	//檢測是否能拿金幣
	bool tkecoin=false;
	if(!allmv[x][y]){
		nwcoin+=mp[x][y];
		allmv[x][y]=true;
		tkecoin=true;
	}
	//這裡是否為終點站
	if(x==n-1 && y==m-1){
		if(p==0){
			apans=max(apans,nwcoin);
			dfs(0,0,1,nwcoin);//換下一個人
		}else{
			bpans=max(bpans,nwcoin);
		}
	}else{
//		cerr<<p<<"go to"<<x<<","<<y<<",get"<<nwcoin<<endl;
		//往下走
		for(INT i=0;i<4;i++){
			dfs(x+mx[i],y+my[i],p,nwcoin);
		}
	}

	//往後走(?)
	if(tkecoin)allmv[x][y]=false;
	if(p==0){
		fmv[x][y]=false;
	}else{
		smv[x][y]=false;
	}
}




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	while(cin>>n>>m){
		set0(mp);
		set0(fmv);
		set0(smv);
		set0(allmv);
		apans=0;
		bpans=0;
		/*CIN*/
		for (INT i = 0; i < n; i++){
			for(INT j=0;j<m;j++){
				char c=read(char);
				if(c=='x'){
					mp[i][j]=-1;
					fmv[i][j]=true;
					smv[i][j]=true;
					allmv[i][j]=true;
				}
				else mp[i][j]=c-'0';
			}
		}
		/*solve*/
		dfs();
		cout<<bpans<<endl;
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

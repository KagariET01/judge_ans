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
bool iofast=1;
INT mx[]={0,0,1,1,1,-1,-1,-1};
INT my[]={1,-1,0,1,-1,0,1,-1};
INT outer[]={0,1,2,3,3,4,4,5,5,5,5,6,6,7,7,8,8,9,9,10,10};
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

const INT maxmn=520;
bool mp[maxmn+2][maxmn+2];
INT mpans[maxmn+2][maxmn+2];
INT ans=0;
INT m,n;
INT cost[11] = {0, 1, 2, 4, 6, 10, 12, 14, 16, 18, 20};

INT solve(INT x,INT y){
	if(x<0 || x>=m || y<0 || y>=n)return 0;
	if(mp[x][y]==0)return 0;
	if(mp[x][y]){
		mp[x][y]=false;
		for(INT i=0;i<8;i++){
			solve(x+mx[i],y+my[i]);
		}
		return 1;
	}
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(cin>>m>>n){
		/*CIN*/
		
		for(INT i=0;i<m;i++){
			string s=read(string);
			for(INT j=0;j<n;j++){
				mp[i][j]=s[j]-'0';
			}
		}
		/*solve*/
		for(INT i=0;i<m;i++){
			for(INT j=0;j<n;j++){
				ans+=solve(i,j);
			}
		}
		if(ans>cost[10]){cout<<"10\n";return 0;}
		for(INT i=0;i<=10;i++){
			if(ans<=cost[i]){
				cout<<i<<endl;
				break;
			}
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

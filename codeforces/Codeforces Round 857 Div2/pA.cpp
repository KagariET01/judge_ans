/*
[CF]				[Q]https://codeforces.com/contest/1802/problem/A

[]

[result]		[AC]
[time]			[15]
[mem]				[0]
[challenge]	[196610482]
[sub time]	[2023/03/09 13:01:51]
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
	INT t=read(INT);
	while(t--){
		/*CIN*/
		INT n=read(INT);
		INT saygoodtme[n+1];
		INT saybadtme[n+1];
		set0(saygoodtme);
		set0(saybadtme);
		INT mxgood=0;
		INT cangood=0;
		INT canbad=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			if(inin>0){
				if(!saygoodtme[inin]){
					mxgood++;
				}
				saygoodtme[inin]++;
				cangood++;
			}else{
				inin=-inin;
				saybadtme[inin]++;
				canbad++;
			}
		}
		/*solve*/
		{
			INT amxgood=mxgood;
			INT acanbad=canbad;
			INT acangood=cangood;
			INT nw=0;
			for(INT i=0;i<n;i++){
				if(nw<amxgood && acangood){
					nw++;
					acangood--;
				}else{
					nw--;
					acanbad--;
				}
				if(i)cout<<" ";
				cout<<nw;
			}
			cout<<endl;
		}
		{
			INT amxgood=mxgood;
			INT acanbad=canbad;
			INT acangood=cangood;
			INT nw=0;
			for(INT i=0;i<n;i++){
				if(nw>0 && acanbad){
					nw--;
					acanbad--;
				}else{
					nw++;
					acangood--;
				}
				if(i)cout<<" ";
				cout<<nw;
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

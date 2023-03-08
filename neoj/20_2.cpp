/*
[neoj]			[Q]https://neoj.sprout.tw/problem/20

[result]		[AC]
[time]			[1000]
[mem]				[34744]
[challenge]	[231728]
[sub time]	[2023/03/07 19:58:26]
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

INT mxp=1e6;

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	for(INT rt=1;rt<=t;rt++){
		cout<<"Line #"<<rt<<endl;
		/*CIN*/
		INT n=read(INT);
		INT pgp[mxp+1];
		set0(pgp);
		for(INT i=1;i<=n;i++){
			INT j=read(INT);
			while(j--){
				pgp[read(INT)]=i;
			}
		}
		deque<INT> gdq[n+1];
		INT m=read(INT);
		deque<INT> alldq;
		while(m--){
			if(read(string)=="ENQUEUE"){
				INT inin=read(INT);
				if(pgp[inin]==0){
					alldq.push_back(-inin);
				}else{
					if(gdq[pgp[inin]].empty()){
						alldq.push_back(pgp[inin]);
					}
					gdq[pgp[inin]].push_back(inin);
				}
			}else{
				if(alldq.front()<0){
					cout<<-alldq.front()<<endl;
					alldq.pop_front();
				}else{
					cout<<gdq[alldq.front()].front()<<endl;
					gdq[alldq.front()].pop_front();
					if(gdq[alldq.front()].empty()){
						alldq.pop_front();
					}
				}
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

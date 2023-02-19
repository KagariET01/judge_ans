/*
[ioic_2023]	[Q]https://judge.ioicamp.org/contests/5/problems/511
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
const INT mxn=2e5;
set<INT> imp[mxn+2];
set<INT> norm[mxn+2];
bool flag[mxn+2];//F1表入度為0，T表入度為1
set<INT> se;
INT ses;
/*struct定義*/
/*fn定義*/
bool waswalk[mxn+2];
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

bool bfs(INT np){
	waswalk[np]=true;
	for(INT i:norm[np]){
		if(waswalk[i])continue;
		if(flag[i]||bfs(i)){
			if(flag[i])flag[i]=false;
			norm[np].erase(i);
			norm[i].erase(np);
			waswalk[np]=false;
			return true;
		}
	}
	waswalk[np]=false;
	return false;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n,m,k;
		cin>>n>>m>>k;
		flag[1]=flag[n]=true;
		loop(i,0,k){
			INT a,b;
			cin>>a>>b;
			imp[a].insert(b);
			imp[b].insert(a);
			flag[a]^=true;
			flag[b]^=true;
		}
		loop(i,0,m-k){
			INT a,b;
			cin>>a>>b;
			norm[a].insert(b);
			norm[b].insert(a);
		}
		/*solve*/
		loop(i,1,n+1){
			if(flag[i])se.insert(i);
		}
		ses=se.size();
		if(ses==0){
			cout<<"Yes"<<endl;
			return 0;
		}
		for(INT i:se){
			if(flag[i]){
				if(bfs(i)){
					ses-=2;
				}
				if(ses==0){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
		cout<<"No"<<endl;
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

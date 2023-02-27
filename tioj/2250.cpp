/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2250
[WA TLE]
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
#include<stack>
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

PII operator+(const PII &a,const PII &b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
PII operator-(const PII &a,const PII &b){
	return {a.FIR-b.FIR,a.SEC-b.SEC};
}
bool operator<(const PII &a,const PII &b){
	return a.FIR<b.FIR || a.SEC<b.SEC;
}
bool operator>(const PII &a,const PII &b){
	return a.FIR>b.FIR || a.SEC>b.SEC;
}
bool operator<=(const PII &a,const PII &b){
	return a.FIR<=b.FIR || a.SEC<=b.SEC;
}
bool operator>=(const PII &a,const PII &b){
	return a.FIR>=b.FIR || a.SEC>=b.SEC;
}
bool operator==(const PII &a,const PII &b){
	return ((a.FIR==b.FIR) || (a.SEC==b.SEC));
}

const PII orig={0,0};
PII nm;
const INT mxn=1000;
INT mp[mxn+1][mxn+1];
deque<PII> step;
INT lst=0;

bool solve(PII add={0,0}){
	if(add<orig || add>=nm)return false;
	if(mp[add.FIR][add.SEC])return false;
	mp[add.FIR][add.SEC]=true;
	lst-=1;

	if(lst==0){
		PII nxt=step.front();
		PII aa=add-nxt;
		if(aa.FIR==aa.SEC)return false;
		else{
			step.push_back(nxt);
			return true;
		}
	}

	step.push_back(add);
	for(INT i=0;i<nm.FIR;i++){
		for(INT j=0;j<nm.SEC;j++){
			if(mp[i][j])continue;
			PII nxt={i,j};
			PII aa=add-nxt;
			if(abs(aa.FIR)==abs(aa.SEC))continue;
			if(nxt==add)continue;
			if(solve(nxt))return true;
		}
	}

	lst+=1;
	step.pop_back();
	mp[add.FIR][add.SEC]=false;
	return false;
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	while(cin>>nm.FIR>>nm.SEC){
		/*re:0*/
		set0(mp);
		step.clear();
		lst=nm.FIR*nm.SEC;
		/*CIN*/
		/*solve*/
		if(solve()){
			for(PII i:step){
				cout<<i.FIR+1<<" "<<i.SEC+1<<endl;
			}
		}else{
			cout<<"-1"<<endl;
		}
		cout<<endl;
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

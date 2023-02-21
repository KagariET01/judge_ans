/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2194
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
bool iofast=true;

const INT mxn=1005;

INT t[mxn+1];
INT tadd[mxn+2];
INT s[mxn+1];
INT d[mxn+1];

/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

INT solve(INT id,INT t){
	priority_queue<PII> que;//使用priority queue維護房間目前的灰塵數量
	for(INT i=1;i<=id;i++){
		que.insert({s[i],i});
	}
INT re=0;
for(INT i=0;i<t;i++){
if(que.empty())break;//沒東西掃就滾
PII nw=que.top();
que.pop();
re+=nw.FIR;
if(nw.FIR-d[nw.SEC]>0){//如果這次掃完後還有灰塵可以掃就推回去
que.insert({nw.FIR-d[nw.SEC],nw.SEC});
}
}
return re;
}




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT),m=read(INT);

set0(t);
set0(tadd);
set0(s);
set0(d);
for(INT i=2;i<=n;i++{
cin>>t[i];
tadd[i]=tadd[i-1]+t[i];
}
for(INT i=1;i<=n;i++){
cin>>s[i];
}
for(INT i=1;i<=n;i++){
cin>>d[i];
}
		/*solve*/
INT ans=0;
for(INT i=1;i<=n;i++){
ans=max(ans,solve(i,m-tadd[i]);
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

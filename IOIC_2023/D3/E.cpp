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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=0;


vector<bool> a;
vector<INT> vecl;
vector<INT> vecr;

bool operator <(const PII& a,const PII& b){//讓r-l大的先做
	return (a.SEC-a.FIR)<(b.SEC-b.FIR);
}
bool operator <=(const PII& a,const PII& b){
	return (a.SEC-a.FIR)<=(b.SEC-b.FIR);
}
bool operator >(const PII& a,const PII& b){
	return (a.SEC-a.FIR)>(b.SEC-b.FIR);
}
bool operator >=(const PII& a,const PII& b){
	return (a.SEC-a.FIR)>=(b.SEC-b.FIR);
}

map<PII,INT> canmnl;
map<PII,INT> canmxr;
set<PII> se;
bool vser(PII a,PII b){
	return (a.SEC-a.FIR)>(b.SEC-b.FIR);
}

priority_queue<PII> que;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

void fnd(INT l,INT r){
	if(r<=l)return;
	PII nw={l,r};
	vector<INT>::iterator lit=lower_bound(vecl.begin()+l,vecl.begin()+r+1,vecl[l]);//尋找該字串中第一個左括號
	vector<INT>::iterator rit=lower_bound(vecr.begin()+l,vecr.begin()+r+1,vecr[r]);//子字串中，最長合法括弧的長度就是vecr[r](不可能更高)
	INT nl=lit-vecl.begin();
	INT nr=rit-vecr.begin();
	while(!a[nl]){
		nl++;
	}
	while(vecl[nr]!=vecr[nr]){
		nr--;
	}

	PII nwthis=make_pair(nl,nr);
	se.insert(nwthis);
	INT &lll=canmnl[nwthis];
	lll=min(lll,l);
	INT &rrr=canmxr[nwthis];
	rrr=max(rrr,r);
	que.push(make_pair(nl+1,nr));
	que.push(make_pair(nl,nr-1));
}








/*INT fnd(INT l,INT r){
	if(r-l<=0)return 0;
	PII thiss={l,r};
	if(mp[thiss])return 0;
	mp[thiss]=true;
	INT cl,cr;
	vector<INT>::iterator lit=lower_bound(vecl.begin()+l,vecl.begin()+r+1,max(vecl[l],(INT)1));
	INT lp=lit-vecl.begin();
	INT rp=r;
	while(rp>lp && vecr[rp]!=vecl[rp]){
		rp--;
	}
	que.push(make_pair(lp,rp-1));
	que.push(make_pair(lp+1,rp));
	cerr<<
	cerr<<endl;
	INT xx=r-rp;
	xx+=lp-l;
	xx++;
	INT thismx=max(vecr[rp]-(*lit),(INT)0)*2;//這個子字串裡最大的合法括號字串
	return xx*thismx;
}*/





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		string s=read(string);
		/*solve*/
		a.resize(n);
		vecl.resize(n);
		vecr.resize(n);
		for(INT i=0;i<n;i++){
			a[i]=(s[i]=='('?true:false);

		}
		INT nl=0;
		INT nr=0;
		loop(i,0,n){
			if(a[i]){
				nl++;
			}else{
				nr=min(nr+1,nl);
			}
			vecl[i]=nl;
			vecr[i]=nr;
		};
		que.push(make_pair(0,n-1));
		INT ans=0;
		while(que.wassomething()){
			PII tp=que.top();
			que.pop();
			fnd(tp.FIR,tp.SEC);
		}
		for(PII pi:se){
			if(pi.FIR==pi.SEC)continue;
			cerr<<"l="<<canmnl[pi]<<",pil="<<pi.FIR<<",pir="<<pi.SEC<<"r="<<canmxr[pi];
			INT nwmx=vecr[pi.SEC]-vecl[pi.FIR];
			nwmx*=2;
			INT mxxx=canmxr[pi]-canmnl[pi]+1;
			mxxx-=(pi.SEC-pi.FIR+1);
			mxxx++;
			ans+=nwmx*mxxx;
			cerr<<",ans="<<ans<<endl;
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

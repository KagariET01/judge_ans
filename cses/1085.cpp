/*
[cses]		https://cses.fi/problemset/task/1085
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
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
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

const INT mxn=2e5;
vector<INT> x;
/*struct定義*/
/*fn定義*/


template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}

bool vser(INT k,INT maxn){
	k--;
	INT nwnum=0;
	for(INT i:x){
		if(nwnum+i>maxn){
			k--;
			nwnum=i;
		}else{
			nwnum+=i;
		}
	}
	return k>=0;
}

template<typename TPE,typename TPE2,typename Fn>TPE Bit_Search(TPE l,TPE r,TPE2 n,Fn isit){
	if(isit(n,l))return l;
	while(r-l>1){
		TPE nw=l+(r-l)/2;
		if(isit(n,nw)){
			r=nw;
		}else{
			l=nw;
		}
	}
	return r;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n=read(INT),k=read(INT);
	INT mxx=0;
	INT tt=0;
	for(INT i=0;i<n;i++){
		x.push_back(read(INT));
		tt+=x.back();
		mxx=max(mxx,x.back());
	}
	/*solve*/
	cout<<Bit_Search(mxx,tt,k,vser);
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

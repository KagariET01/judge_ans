/*
[CF]				[Q]https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C
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
INT n,k;
INT a[mxn+1];
INT b[mxn+1];
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

bool vser(INT fnd,INT nw){
	INT no=0;
	INT rn=upper_bound(a,a+n,nw)-a;
	//cerr<<"nw="<<nw<<"rn="<<rn<<endl;
	INT r=n-1;
	for(INT i=0;i<rn;i++){
		while(a[i]+b[r]>nw){
			r--;
		}
		no+=r+1;
	}
	//cerr<<"no="<<no<<endl;
	if(no>=fnd)return true;
	else return false;
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
		//cerr<<"l="<<l<<"r="<<r<<endl;
	}
	return r;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	n=read(INT),k=read(INT);
	for(INT i=0;i<n;i++){
		a[i]=read(INT);
	}
	for(INT i=0;i<n;i++){
		b[i]=read(INT);
	}
	/*solve*/
	sort(a,a+n);
	sort(b,b+n);
	INT l,r;
	l=a[0]+b[0];
	r=a[n-1]+b[n-1];
	cout<<Bit_Search(l,r,k,vser);
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

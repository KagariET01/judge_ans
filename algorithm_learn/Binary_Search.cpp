/*
[二分搜]
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

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
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

bool vser(INT n,vector<INT>::iterator nw){
	return n<=*nw;
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
	vector<INT> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	vector<INT>::iterator it=Bit_Search(a.begin(),a.end(),3,vser);
	cout<<*it<<endl;
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

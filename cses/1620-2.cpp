/*
[cses]			[Q]https://cses.fi/problemset/task/1620
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
INT n,t;

vector<INT> k;
/*struct定義*/
struct mat{
	INT a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<2;i++){
			for(INT j=0;j<2;j++){
				for(INT k=0;k<2;k++){
					re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
INT INT_IN(){
	INT a;
	cin>>a;
	return a;
}

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

bool vser(const INT &n,const INT &nw){
	INT ans=0;
	for(INT i:k){
		ans+=nw/i;
		if(ans>=n)return true;
	}
	return false;
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
	cin>>n>>t;
	while(n--){
		k.push_back(reader<INT>());
	}
	
	/*solve*/
	INT l=0,r=1e18;
	cout<<Bit_Search(l,r,t,vser)<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

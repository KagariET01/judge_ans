/*
[Q]
[]
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
const INT mxn=2e6;
INT n,m,q;
//n=紀念品
//m=lucky num
//q=coin
INT a[mxn+5];
INT b;
INT qme[mxn+5];//q的冪次
INT mxa=0;
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
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n>>m>>q;
	for(INT i=0;i<n;i++){
		cin>>a[i];
		mxa=max(mxa,a[i]);
	}
	/*solve*/
	qme[0]=1;
	while(q--){
		cin>>b;
		INT mxme=0;
		while(qme[mxme]<mxa){
			mxme++;
			qme[mxme]=qme[mxme-1]*b;
		}
		INT ans=0;
		for(INT i=0;i<n;i++){
			INT coin=0;
			INT p=a[i];
			for(INT j=mxme;j>=0;j--){
				coin+=p/qme[j];
				p=p%qme[j];
				if(coin>=m)break;
				if(p==0)break;
			}
			if(p==0 && coin==m)ans++;
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

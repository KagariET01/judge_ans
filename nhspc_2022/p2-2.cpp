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
#define ifif if
/*struct宣告*/
struct mat;
struct da;
/*fn宣告*/
/*num*/
bool iofast=1;
bool debug=0;
bool mode=0;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
const INT mxn=1e5;
INT n;
INT nowdata[mxn+1];
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
struct da{
	INT l;
	INT r;
	INT total;
	INT center;
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
bool aaal(da a,da b){
	return a.l>b.l;
}
bool aaar(da a,da b){
	return a.r>b.r;
}
/*main*/
int main(){
	if(iofast){what_the_fuck;}
	/*CIN*/
	INT a;
	cin>>a>>n;
	if(a>1){cout<<"pass"<<endl;return 0;}
	INT num[n+1];
	for(INT i=0;i<n;i++){
		cin>>num[i];
	}
	INT ans=num[0];
	INT now=num[0];
	INT l=0;
	for(INT r=0;r<n;r++){
		now+=num[r];
		while(l<r && now<0){
			now-=num[l];
			l++;
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

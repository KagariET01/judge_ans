/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f161
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

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define PB(n) push_back(n)
#define PF(n) push_front(n)
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

const INT mxn=2e5;
const INT mxc=1e9;
INT n;
INT c[mxn+1];
vector<INT> tree[mxn+1];
INT ans=0;
map<INT,INT> getcolor;
bool wawawa[mxn+1];
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

void DFS(INT nn){
	getcolor[c[nn]]++;//拿取該格寶石
	ans=max(ans,getcolor[c[nn]]);
	wawawa[nn]=true;
	for(INT i:tree[nn]){
		if(wawawa[i])continue;
		DFS(i);
	}
	getcolor[c[nn]]--;
	wawawa[nn]=false;
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n;
	for(INT i=0;i<n;i++){
		cin>>c[i];
	}
	for(INT i=0;i<n-1;i++){
		INT a,b;
		cin>>a>>b;
		tree[a].PB(b);
	}
	/*solve*/
	DFS((INT)0);
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

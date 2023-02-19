/*
[Q]
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
INT INT_in(){
	INT inin;
	cin>>inin;
	return inin;
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT k;
	cin>>k;
	INT m,n;
	cin>>m>>n;
	INT pre[m+1][n+1];
	INT ans=0;
	memset(pre,0,sizeof(pre));
	for(INT i=1;i<=m;i++){
		for(INT j=1;j<=n;j++){
			INT nw=INT_in();
			/*solve*/
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+nw;
			for(INT x=1;x<=i;x++){
				for(INT y=1;y<=j;y++){
					INT nn=pre[i][j]-pre[x-1][j]-pre[i][y-1]+pre[x-1][y-1];
					if(nn<=k){
						ans=max(ans,nn);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	DBG{
		for(INT i=0;i<=m;i++){
			for(INT j=0;j<=n;j++){
				cerr<<pre[i][j]<<" ";
			}
			cerr<<endl;
		}
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
pre[i][j]=從地圖(1,1)(含)到(i,j)(含)的所有個數和
pre[i][j]-pre[x-1][j]-pre[i][y-1]+pre[x-1][y-1]=地圖(x,y)到(i,j)的所有個數總和
*/

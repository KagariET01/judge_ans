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
da dal[mxn+1];
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
	cin>>n;
	if(!mode){
		for(INT i=0;i<n;i++){
			INT k=0;
			cin>>k;
			//讀入list data
			for(INT j=0;j<k;j++){
				cin>>nowdata[j];
				dal[i].total+=nowdata[j];
			}
			//左邊total max
			INT nwtotal=0;
			dal[i].l=nowdata[0];
			for(INT j=0;j<k;j++){
				nwtotal+=nowdata[j];
				dal[i].l=max(dal[i].l,nwtotal);
			}
			dal[i].l-=max(dal[i].total,(INT)0);
			//r
			nwtotal=0;
			dal[i].r=nowdata[k-1];
			for(INT j=k-1;j>=0;j--){
				nwtotal+=nowdata[j];
				dal[i].r=max(dal[i].r,nwtotal);
			}
			dal[i].r-=max(dal[i].total,(INT)0);
			//center
			INT pl=0;
			nwtotal=0;
			dal[i].center=nowdata[0];
			for(INT pr=0;pr<k;pr++){
				nwtotal+=nowdata[pr];
				while(pl<pr && nwtotal<0){
					nwtotal-=nowdata[pl];
					pl++;
				}
				//DBG cerr<<"pl="<<pl<<",pr="<<pr<<endl;
				dal[i].center=max(dal[i].center,nwtotal);
			}
			DBG{
				cerr<<" l:"<<dal[i].l;
				cerr<<" r:"<<dal[i].r;
				cerr<<" total:"<<dal[i].total;
				cerr<<" center:"<<dal[i].center;
				cerr<<endl;
			}
		}
	}
	else{
		for(INT i=0;i<n;i++){
			cin>>dal[i].l>>dal[i].center>>dal[i].total>>dal[i].r;
		}
	}
	/*solve*/
	if(n==1){
		cout<<dal[0].center<<endl;
		return 0;
	}
	INT ans=dal[0].center;
	INT tt=0;
	for(INT i=0;i<n;i++){
		if(dal[i].total>0){
			tt+=dal[i].total;
		}
		ans=max(ans,dal[i].center);
	}
	if(false){
		INT lc=0;
		INT rc=0;
		INT cc=0;
		for(INT i=0;i<n;i++){
			ifif(dal[i].l>dal[i].r){
				if(dal[i].total<=0){//如果total計算時沒有選他
					ifif(dal[i].l>lc)lc=dal[i].l;
					elif(dal[i].r>rc)rc=dal[i].r;
				}
				else{//total換l,r
					ifif(dal[i].l-dal[i].total>lc)lc=dal[i].l-dal[i].total;
					elif(dal[i].r-dal[i].total>rc)rc=dal[i].r-dal[i].total;
				}
			}
			elif(dal[i].l==dal[i].r){
				if(dal[i].total<=0){//如果total計算時沒有選他
					ifif(dal[i].l>cc)cc=dal[i].l;
				}
				else{//total換l,r
					ifif(dal[i].l-dal[i].total>cc)cc=dal[i].l-dal[i].total;
				}
			}
			else{
				if(dal[i].total<=0){//如果total計算時沒有選他
					ifif(dal[i].r>rc)rc=dal[i].r;
					elif(dal[i].l>lc)lc=dal[i].l;
				}
				else{//total換l,r
					ifif(dal[i].r-dal[i].total>rc)rc=dal[i].r-dal[i].total;
					elif(dal[i].l-dal[i].total>lc)lc=dal[i].l-dal[i].total;
				}
			}
		}
		DBG cerr<<"tt="<<tt<<",lc="<<lc<<",rc="<<rc<<",cc="<<cc<<endl;
		tt=tt+max(lc,rc)+max(min(lc,rc),cc);
	}
	if(true){
		INT a,b,c,d;
		sort(dal,dal+n,aaal);
		a=dal[0].l;
		b=dal[1].l;
		sort(dal,dal+n,aaar);
		c=dal[0].r;
		d=dal[1].r;
		tt+=max(max(a+c,a+d),max(b+c,b+d));
	}
	if(tt>0) ans=max(ans,tt);
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

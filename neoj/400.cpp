/*
[Q]https://neoj.sprout.tw/problem/400/
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
#define ifif if
//#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
//#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}
#define wassomething() empty()==false
#define ERR(n) cerr<<"#n="<<n<<endl
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
PII operator-(PII a,PII b){
	return {a.FIR-b.FIR,a.SEC-b.SEC};
}
INT PII_cross(PII a,PII b){//外積(向量a,向量b) 向量={x位移,y位移}
	return a.FIR*b.SEC-a.SEC*b.FIR;
	//兩vector的關係為逆時針旋轉:值>0
	//同向、反向:值=0
	//順時針:值<0
}

INT PII_dot(PII a,PII b){//內積(向量a,向量b) 向量={x位移,y位移}
	return a.FIR*b.FIR+a.SEC*b.SEC;
	//夾角>90:值<0
	//夾角=90:值=0
	//夾角<90:值>0
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	
	/*CIN*/
	INT l=0,r=0,ba_ck=0;
	INT n;
	cin>>n;
	PII dta[n];
	PII vec[n];
	for(INT i=0;i<n;i++){
		cin>>dta[i].FIR;
		cin>>dta[i].SEC;
	}
	/*solve*/
	for(INT i=1;i<n;i++){
		vec[i]=dta[i]-dta[i-1];
	}
	for(INT i=2;i<n;i++){
		INT nw=PII_cross(vec[i-1],vec[i]);
		ifif(nw>0)l++;
		elif(nw<0)r++;
		else{
			INT se=PII_dot(vec[i],vec[i-1]);
			DBG cerr<<se<<endl;
			if(se<0){
				ba_ck++;
			}
		}
	}
	cout<<l<<" "<<r<<" "<<ba_ck<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

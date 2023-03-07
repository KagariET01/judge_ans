/*
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=g555
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=g556
[AC]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
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
#include<ctime>
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
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=0;
bool iofast=true;
INT mod=998244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

struct bck{
	INT a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	bck operator*(const bck b){
		bck re;
		memset(re.a,0,sizeof(re.a));
		for(INT i=0;i<3;i++){
			for(INT j=0;j<3;j++){
				for(INT k=0;k<3;k++){
					re.a[i][j]+=(a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};

template<typename TPE>TPE ETpow(TPE n,INT m){
	//cerr<<m<<"="<<endl;
	TPE re=n;
	m--;
	TPE nw=n;
	
	while(m){
		if(m & 1){	
			re=re*nw;
		}
		nw=nw*nw;
		m>>=1;
	}
			// for(INT i=0;i<3;i++){
			// 	for(INT j=0;j<3;j++){
			// 		cerr<<re.a[i][j]<<",";
			// 	}
			// 	cerr<<endl;
			// }
	return re;
}


/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	bck fst;
	memset(fst.a,0,sizeof(fst.a));
	fst.a[0][0]=1;
	fst.a[0][1]=1;
	fst.a[0][2]=2;
	bck xx;
	memset(xx.a,0,sizeof(xx.a));
	xx.a[0][0]=1;
	xx.a[2][1]=1;
	xx.a[0][2]=1;
	xx.a[1][2]=1;
	xx.a[2][2]=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		if(n==1){
			cout<<"1"<<endl;
		}elif(n==2){
			cout<<"2"<<endl;
		}else{
			bck ans=fst*ETpow(xx,n-2);
			cout<<ans.a[0][2]%mod<<endl;
		}
		/*solve*/
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

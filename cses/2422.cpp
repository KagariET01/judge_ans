/*
[cses]		https://cses.fi/problemset/task/2422
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

INT n;
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

bool vser(INT mnt,INT fnd){
	INT bef=0;
	for(INT i=1;i<=n;i++){//找出數字比mnt小的個數
		bef+=min(n,mnt/i);//代表第i列有多少個數字比mnt小
	}
	if(bef>=fnd)return true;//如果數量太多，把r往左移
	else return false;//反之...懶得打
}

template<typename TPE,typename TPE2,typename Fn>TPE Bit_Search(TPE l,TPE r,TPE2 fnd,Fn isit){
	//if(isit(n,l))return l;
	//就很普通的二分搜，錯了ㄇ
	while(l<r){
		TPE nw=l+(r-l)/2;
		if(isit(nw,fnd)){
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
	n=read(INT);
	/*solve*/
	INT ans=Bit_Search((INT)1,(INT)(n*n),(INT)((n*n+1)/2),vser);
	cout<<ans;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

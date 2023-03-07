/*
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=b232
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
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}
const INT mxn=750;
INT dp[mxn+1][mxn+1];
INT solve(INT al,INT mx){//al為最終要湊出的$，mx為最大面額
	if(!dp[al][mx]){
		if(al==0){//
			dp[al][mx]=1;
		}elif(mx==0){//如果面額為0:無解
			dp[al][mx]=0;
		}elif(mx%2==0){//不允許面額為2的倍數
			dp[al][mx]=solve(al,mx-1);
		}else{
			dp[al][mx]=solve(al,mx-1);//一種組法：1+(al+1) 例如10=1+9
			if(mx<=al){
				dp[al][mx]+=solve(al-mx,mx);//一種組法:假設我們要湊出10，而最大面額為3，那我們就湊3+(7)
			}
		}
	}
	return dp[al][mx];
}





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=read(INT);
	while(t--){
		/*CIN*/
		INT n=read(INT);
		cout<<solve(n,n)<<endl;
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
假設有1,3,5,......j種$$
然後要湊出i
那有幾種湊法?
*/

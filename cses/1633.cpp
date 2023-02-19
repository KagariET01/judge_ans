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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
const INT maxn=1e6;
const INT moder=1e9+7;
INT dp[maxn+1];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n;
	cin>>n;
	/*solve*/
	for(INT i=1;i<=6;i++){
		dp[i]=1;
	}
	for(INT i=2;i<=n;i++){
		for(INT j=1;j<=6;j++){
			if(i-j<0)break;
			dp[i]+=dp[i-j];
			dp[i]%=moder;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

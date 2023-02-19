/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d105
[AC]
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	INT n,m;
	cin>>n>>m;
	/*solve*/
	INT dp[m+1][n];
	dp[0][0]=1;
	for(INT i=1;i<n;i++){
		dp[0][i]=0;
	}
	for(INT i=1;i<=m;i++){
		for(INT j=0;j<n;j++){
			dp[i][j]=dp[i-1][(j+1)%n]+dp[i-1][(j+n-1)%n];
		}
	}

	cout<<dp[m][0];
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d482
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
	INT n;
	while(cin>>n){
		INT mp[n+1][n+1];
		INT dp[n+1][n+1];
		for(INT i=0;i<=n;i++){
			dp[i][0]=0;
			dp[0][i]=0;
		}
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=n;j++){
				cin>>mp[i][j];
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mp[i][j];
			}
		}
		cout<<dp[n][n]<<endl;
	}
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

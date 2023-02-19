/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d054
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
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
	INT q;
	cin>>q;
	INT mx=1e18+1;
	INT dp[mx];
	dp[0]=0;
	for(INT i=1;i<=1e18;i++){
		dp[i]=0;
		if(i>=1){
			dp[i]+=dp[i-1];
		}
		if(i>=2){
			dp[i]+=dp[i-2]*4;
		}
		if(i>=3){
			dp[i]+=dp[i-3]*2;
		}
	}
	while(q--){
		/*CIN*/
		INT n;
		cin>>n;
		/*solve*/
		cout<<n<<endl;
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d212
[AC]
*/

/*include*/
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
#define INT ULLI
#define UINT INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
INT n;
INT dp[101][2];
//dp[n][0] 走一階
//dp[n][1] 走兩階
INT wasdo=1;
/*fn定義*/

/*main*/
int main(){
	/*IO加速*/
	if(false){
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	dp[0][0]=1;
	dp[0][1]=0;
	dp[1][0]=1;
	dp[1][1]=0;
	while(cin>>n){
		/*CIN*/
		/*solve*/
		while(wasdo<=n){
			wasdo++;
			//cout<<wasdo<<",";
			dp[wasdo][0]=dp[wasdo-1][0]+dp[wasdo-1][1];
			dp[wasdo][1]=dp[wasdo-2][0]+dp[wasdo-2][1];
		}
		cout<<dp[n][0]+dp[n][1]<<"\n";
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

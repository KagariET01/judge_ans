/*
[Q]
[]
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
#include<stack>
#include<cstring>
#include<unordered_map>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/
UINT dp[1000001];
UINT mod=1e9+7;
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	UINT n,x;
	dp[0]=1;
	cin>>n>>x;
	for(UINT i=1;i<=n;i++){
		UINT c;
		cin>>c;
		for(UINT j=0;j+c<=x;j++){
			dp[j+c]+=dp[j];
			dp[j+c]%=mod;
		}
	}
//	for(int i=0;i<=x;i++){
//		cout<<dp[i]<<" ";
//	}
	cout<<dp[x];
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

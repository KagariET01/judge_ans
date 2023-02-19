/*
[Q]
[WA TLE 0%]
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
map<INT,INT> dp;
INT wasdo=1;
INT mod=998244353;
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	INT n;
	cin>>n;
	dp[1]=1;
	while(n--){
		INT sc;
		cin>>sc;
		while(wasdo<sc){
			wasdo++;
			INT aa,bb,cc;
			aa=dp[wasdo-1]*1;
			bb=dp[wasdo-2]*2;
			cc=dp[wasdo-3]*3;
			dp[wasdo]=max(aa,max(bb,max(cc,wasdo)))%mod;
		}
		cout<<dp[sc]<<"\n";
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

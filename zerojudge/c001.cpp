/*
[Q]
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
INT dp[1001][1001];
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	string a,b;
	while(cin>>a>>b){
		/*CIN*/
		INT al=a.size(),bl=b.size();
		/*solve*/
		for(INT i=1;i<=al;i++){
			for(INT j=1;j<=bl;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[al][bl]<<"\n";
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

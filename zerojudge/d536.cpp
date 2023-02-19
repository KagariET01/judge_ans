/*
[Q]
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
bool debug=0;
bool iofast=true;
INT n;
INT dp[30][30];//dp[i][j]表i到j的最短路徑
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	while(cin>>n){
		for(INT i=0;i<30;i++){
			for(INT j=0;j<30;j++)dp[i][j]=30;
		}
		while(n--){
			string str;
			cin>>str;
			dp[str[0]-'A'][str[1]-'A']=1;
		}
		/*solve*/
		for(INT i=0;i<26;i++){
			for(INT j=0;j<26;j++){
				for(INT k=0;k<26;k++){
					dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				}
			}
		}
		INT ans=30;
		for(INT i=0;i<26;i++){
			ans=min(ans,dp[i][i]);
		}
		DBG{
			for(INT i=0;i<26;i++){
				for(INT j=0;j<26;j++){
					cerr<<dp[i][j]<<" ";
				}
				cerr<<endl;
			}
		}
		cout<<(ans==30?0:ans)<<endl;
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

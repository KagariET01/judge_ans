/*
[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
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
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT ca=0;
	INT n,m;
	while(cin>>n>>m){
		/*CIN*/
		INT ma[n+1][m+1];
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		/*solve*/
		INT dp[n+1][m+1];
		for(INT i=0;i<=n;i++){
			dp[i][0]=0;
		}
		for(INT i=0;i<=m;i++){
			dp[0][i]=0;
		}
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=m;j++){
				if(i==1 && j==1){
					dp[i][j]=ma[i][j];
				}else if(i==1){
					dp[i][j]=dp[i][j-1]+ma[i][j];
				}else if(j==1){
					dp[i][j]=dp[i-1][j]+ma[i][j];
				}else{
					dp[i][j]=min(dp[i-1][j],dp[i][j-1])+ma[i][j];
				}
			}
		}
		cout<<"Case #"<<++ca<<" :\n"<<dp[n][m]<<endl;
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c777
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT a,b;
	cin>>a>>b;
	/*solve*/
	if(a>b){
		cout<<0<<endl;
		return 0;
	}
	INT dp[1000]={0,1,2};
	INT ans=0;
	if(a<3)ans=3-a;
	for(INT i=3;i<1000;i++){
		if(debug){
			cout<<i<<":"<<dp[0]<<","<<dp[1]<<","<<dp[2]<<endl;
		}
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
		if(dp[i]>b)break;
		if(dp[i]>=a){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

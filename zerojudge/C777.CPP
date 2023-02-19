/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c777
[TLE]
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
	INT dp[3]={0,1,2};
	INT now=0;
	INT ans=0;
	if(a==0)ans+=2;
	else if(a==1)ans+=1;
	else if(a==2)ans+=0;
	else while(true){
		dp[now%3]=dp[0]+dp[1]+dp[2];
		if(dp[now%3]>=a)break;
		now++;
		now%=3;
	}
	while(true){
		if(dp[now%3]>=b)break;
		ans++;
		if(debug)cout<<dp[now%3]<<endl;
		now++;
		now%=3;
		dp[now%3]=dp[0]+dp[1]+dp[2];
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

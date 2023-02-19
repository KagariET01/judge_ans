/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a111
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
bool debug=false;
bool iofast=true;
INT dp[101];
INT i=2;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	INT n;
	/*re:0*/
	dp[1]=1;
	while(cin>>n){
		if(n){
			/*solve*/
			while(i<=n){
				dp[i]=dp[i-1]+i*i;
				i++;
			}
			cout<<dp[n]<<endl;
		}
		else break;
	}
	DBG for(INT j=0;j<=i;j++){
		cerr<<dp[j]<<",";
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c039
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
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT ii,jj;
	INT ans=0;
	INT now;
	INT thisans;
	while(cin>>ii>>jj){
		/*CIN*/
		/*solve*/
		cout<<ii<<" "<<jj<<" ";
		ans=0;
		for(INT i=min(ii,jj);i<=max(ii,jj);i++){
			now=i;
			thisans=1;
			while(now!=1){
				if(now%2){
					now=3*now+1;
				}else{
					now/=2;
				}
				thisans++;
			}
			ans=max(ans,thisans);
		}
		cout<<ans<<endl;
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b467
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
	INT nn,mm,kk,xx;
	//n為人數
	//m為位移
	//k為10^k次
	//x為詢問人
	while(cin>>nn>>mm>>kk>>xx){
		/*CIN*/
		/*solve*/
		INT now=10;
		while(kk){//快速冪
			if(kk&1){
				mm*=now;
				mm%=nn;
			}
			now*=now;
			now%=nn;
			kk>>=1;
		}
		mm+=xx;
		mm%=nn;
		cout<<mm<<endl;
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

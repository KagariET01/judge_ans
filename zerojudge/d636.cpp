/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d636
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
map<INT,INT>ntt;
/*fn定義*/
INT nttc(INT a,INT b){
	if(ntt[b])return ntt[b];
	if(b==1)return a;
	else{
		INT mnt=b/2;
		INT rig=b-mnt;
		INT re=(nttc(a,mnt)*nttc(a,rig))%10007;
		ntt[b]=re;
		return re;
	}
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	ntt[0]=1;
	/*CIN*/
	INT a,b;
	cin>>a>>b;
	ntt[1]=a;
	cout<<nttc(a,b)<<"\n";
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c812
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
#define sec2 second
#define fir1 first

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
INT N,Vk,q;
vector<PII> lk[5000+10];
INT anscounter=0;
bool wasvisit[5000+10];
/*fn定義*/
INT dfs(INT st){
	if(debug)cout<<st<<",";
	wasvisit[st]=true;
	INT re=0;
	for(auto i:lk[st]){
		if(i.sec2<q)continue;
		if(wasvisit[i.fir1])continue;
		re++;
		re+=dfs(i.fir1);
	}
	wasvisit[st]=false;
	return re;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>N>>Vk>>q;
	for(INT i=0;i<N-1;i++){
		INT l,r,Rij;
		cin>>l>>r>>Rij;
		lk[l].push_back({r,Rij});
		lk[r].push_back({l,Rij});
	}
	/*solve*/
	cout<<dfs(Vk)<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

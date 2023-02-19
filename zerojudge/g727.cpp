/*
[Q]https://zerojudge.tw/ShowProblem?problemid=g727
[WA]
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
#define endl "\n"

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT n,k;
const INT maxn=100000;
bool eat[maxn+1];
vector<INT> vec[maxn+1];
INT ans=0;
/*fn定義*/
INT bfs(INT n){
	INT re=0;
	deque<INT> que;
	que.push_back(n);
	while(!que.empty()){
		INT now=que.back();
		que.pop_back();
		if(eat[now])continue;//如果已經被吃了，就走
		eat[now]=true;//吃
		re++;//紀錄這裡已經吃了
		if(debug)cout<<now<<","<<re<<" ";
		for(INT i:vec[now]){
			if(eat[i])continue;
			que.push_back(i);
		}
	}
	return re-1;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>n>>k;
	for(INT i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	/*solve*/
	INT ans=0;
	for(INT i=0;i<1;i++){
		if(debug)cout<<i<<":";
		ans=min(k,max(ans,bfs(i)));
		if(debug)cout<<"ans"<<ans<<endl;
		/*re:0*/
		for(INT i=0;i<k;i++){
			eat[i]=false;
		}
	}
	if(debug)cout<<ans<<endl;
	cout<<k-ans<<endl;
	return 0;
}

/*
[I1]
5 4
1 2
4 3
1 4
3 4
[O1]
1
[I2]
6 5
2 3
2 1
3 4
6 5
4 5
[O2]
0

[I3]
2 5
1 2
1 2
1 2
1 2
1 2
[O3]
4
*/

/*think*/
/*

*/

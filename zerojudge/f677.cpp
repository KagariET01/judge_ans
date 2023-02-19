/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f677
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
bool iofast=true;
INT n,m;
INT dsu[1000000];
/*fn定義*/
INT dsu_find(INT a){
	if(dsu[a]==a)return a;//如果自己就是老大，回報自己
	INT root=dsu_find(dsu[a]);//找尋他的老大
	//dsu[a]=n的爸爸
	dsu[a]=root;//把老大當自己爸爸
	return root;//回報自己ㄉ老大
}
void dsu_push(INT a,INT b){
	dsu[dsu_find(a)]=dsu_find(b);
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>n>>m;
	/*solve*/
	for(INT i=0;i<n;i++){
		dsu[i]=i;
	}
	if(debug){
		for(INT i=0;i<n;i++){
			cout<<dsu[i]<<" ";
		}
		cout<<endl;
	}
	while(m--){
		INT a,b;
		cin>>a>>b;
		dsu_push(a,b);
		if(debug){
			for(INT i=0;i<n;i++){
				cout<<dsu[i]<<" ";
			}
			cout<<endl;
		}
	}
	INT bboss=dsu_find(0);
	INT ans=0;
	for(INT i=0;i<n;i++){
		if(dsu_find(i)==bboss)ans++;
	}
	if(debug){
		for(INT i=0;i<n;i++){
			cout<<dsu[i]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
5 3
1 0
0 3
2 4
[O1]
*/

/*think*/
/*

*/

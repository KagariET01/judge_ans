/*
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=b117
[AC]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iomanip>
#include<ctime>
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
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

const INT mxn=1e5;
INT ans=0;
vector<PII> tre[mxn+1],bktre[mxn+1];//tre[起點][i]={終點,花費}
INT n,m;
INT lne[mxn+1];


/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	while(cin>>n>>m){
		for(INT i=0;i<=n;i++){
			tre[i].clear();
			bktre[i].clear();
		}
		for(INT i=0;i<=n;i++){
			lne[i]=1000000000;
		}
		ans=0;
		/*CIN*/
		for(INT i=0;i<m;i++){
			INT a,b,c;
			cin>>a>>b>>c;
			tre[a].push_back({b,c});
			bktre[b].push_back({a,c});
		}
		/*solve*/
		//出去
		priority_queue<PII,vector<PII>,greater<PII>>que;//目前路徑最小的會先被拉出來
		que.push({0,1});//{目前花費,位置}
		lne[1]=0;
		while(que.wassomething()){
			PII nw=que.top();
			que.pop();
			if(lne[nw.SEC]!=nw.FIR)continue;//如果紀錄的和現在的不一樣就跳出(根據bfs的特性，跑過的地方數值絕對比較小)
			ans+=lne[nw.SEC];
			for(PII i:tre[nw.SEC]){
				if(lne[i.FIR]>lne[nw.SEC]+i.SEC){//如果從這邊走過去會比原本的方案好，那就加進去
					lne[i.FIR]=lne[nw.SEC]+i.SEC;
					que.push({lne[i.FIR],i.FIR});
				}
			}
		}
		//回來
		for(INT i=0;i<=n;i++){
			lne[i]=1000000000;
		}
		lne[1]=0;
		que.push({0,1});
		while(que.wassomething()){
			PII nw=que.top();
			que.pop();
			if(lne[nw.SEC]!=nw.FIR)continue;
			ans+=lne[nw.SEC];
			for(PII i:bktre[nw.SEC]){
				if(lne[i.FIR]>lne[nw.SEC]+i.SEC){
					lne[i.FIR]=lne[nw.SEC]+i.SEC;
					que.push({lne[i.FIR],i.FIR});
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
[房間數量 n] [道路數量 m]
{[點1 a] [點2 b] [邊權重 c]}*n
1<=a,b<=n
[O1]
[ans]
若可以從點1走到其他所有點再走回來
輸出最短距離
若不行則輸出0
*/

/*think*/
/*

使用類bfs和類topological sort和greedy

每次執行時都會優先拿目前路徑最短的工作
然後往下走

可以證明第一次走到該點時，工作簿上面的路徑即為最短路徑
然後我不想寫證明，有興趣的幫忙補充謝謝

如果這個工作和紀錄簿上面的"可以最短路"的長度不同
代表說這點走過了
這也可以證，但我不想證

根據上面這兩點，就可以寫出這支code了
詳細的可以直接看code，不然單靠文字是無法描述清楚的

*/

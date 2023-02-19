/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d793
[RE]
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
INT mx[4]={0,1,0,-1};
INT my[4]={1,0,-1,0};
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	INT tc;
	cin>>tc;
	while(tc--){
		INT n,m;
		cin>>n>>m;
		INT mp[n+10][m+10];
		INT step[n+10][m+10];
		bool waswalk[n+10][m+10];
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				cin>>mp[i][j];
				step[i][j]=0;
				waswalk[i][j]=false;
			}
		}
		deque<PII> worklist;
		worklist.push_back({0,0});
		INT runcount=0;
		while(worklist.size()>0){
			if(debug)cout<<runcount++<<" ";
			PII nw=worklist.front();
			worklist.pop_front();
			INT &nx=nw.first;
			INT &ny=nw.second;
			for(INT i=0;i<4;i++){
				INT nextx=nx+mx[i];
				INT nexty=ny+my[i];
				if(nextx<0 || nextx>=n)continue;
				if(nexty<0 || nexty>=m)continue;
				if(debug)cout<<nextx<<","<<nexty<<" ";
				if(mp[nextx][nexty]+step[nx][ny]<step[nextx][nexty] || !waswalk[nextx][nexty]){
					step[nextx][nexty]=mp[nextx][nexty]+step[nx][ny];
					worklist.push_back({nextx,nexty});
					waswalk[nextx][nexty]=true;
				}
			}
			if(debug)cout<<"\n";
		}
		if(debug){
			cout<<endl;
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					cout<<step[i][j]<<",";
				}
				cout<<"\n";
			}
		}
		cout<<step[n-1][m-1]<<endl;
		if(debug)cout<<endl;
	}
	/*solve*/
	return 0;
}

/*
[I1]
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
[O1]
24
15
*/

/*think*/
/*

*/

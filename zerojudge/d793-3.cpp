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
INT n,m;
INT mp[999+10][999+10];
INT step[999+10][999+10];
bool waswalk[999+10][999+10];
deque<PII>worklist;
PII nw;
INT nx,ny;
INT nextx,nexty;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	INT tc;
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				cin>>mp[i][j];
				step[i][j]=0;
				waswalk[i][j]=false;
			}
		}
		/*solve*/
		worklist.clear();
		worklist.push_back({0,0});
		while(worklist.size()>0){
			nw=worklist.front();
			worklist.pop_front();
			nx=nw.first;
			ny=nw.second;
			if(waswalk[nx][ny])continue;
			for(INT i=0;i<4;i++){
				nextx=nx+mx[i];
				nexty=ny+my[i];
				if(nextx<0 || nextx>=n)continue;
				if(nexty<0 || nexty>=m)continue;
				if(!waswalk[nextx][nexty]){
					step[nextx][nexty]=mp[nextx][nexty]+step[nx][ny];
					worklist.push_back({nextx,nexty});
				}
			}
			waswalk[nx][ny]=true;
		}
		cout<<step[n-1][m-1]<<endl;
	}
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

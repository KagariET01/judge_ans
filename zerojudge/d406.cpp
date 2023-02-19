/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d406
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
INT s,n,m;
bool mp[100+5][100+5];
INT ans[100+5][100+5];
deque<PII> dq;
INT sx=0,sy=0;
INT mx[]={-1,1,0,0};
INT my[]={0,0,1,-1};
INT smx[]={1,0,0};
INT smy[]={0,1,-1};
PII nw;
INT nowx,nowy,nextx,nexty;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT counter=1;
	while(cin>>s>>n>>m){
		s--;
		/*CIN*/
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				INT inin;
				cin>>inin;
				mp[i][j]=inin?true:false;
				ans[i][j]=0;
			}
		}
		/*solve*/
		sx=0;
		sy=0;
		while(!mp[sx][sy] && sy<m){
			sy++;
		}
		dq.push_back({sx,sy});
		ans[sx][sy]=1;
		while(!dq.empty()){
			nw=dq.front();
			dq.pop_front();
			nowx=nw.first;
			nowy=nw.second;
			for(INT i=s;i<4;i++){
				nextx=nowx+mx[i];
				nexty=nowy+my[i];
				if(nextx<0||nexty<0||nextx>=n||nexty>=m||ans[nextx][nexty]||(!mp[nextx][nexty]))continue;
				ans[nextx][nexty]=ans[nowx][nowy]+1;
				dq.push_back({nextx,nexty});
			}
		}
		cout<<"Case "<<counter<<":\n";
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
		counter++;
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

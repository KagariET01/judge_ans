/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c145
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

/*struct*/

/*fn宣告*/

/*num*/
bool ma[13][13];
INT n,m;
bool debug=false;
INT mx[]={1,-1};
INT ans=0;
/*fn定義*/
void out(INT x,INT y,INT aa){
	if(!debug)return;
	for(INT i=0;i<aa;i++){
		cout<<" ";
	}
	cout<<x<<","<<y<<"\n";
}
INT find(INT x,INT y,bool arr,INT step=1){
	if(ma[x][y])return 0;
	if(debug)cout<<x<<","<<y<<endl;
	ans=max(ans,step);
	ma[x][y]=true;
	for(INT i=0;i<2;i++){
		INT nx=x,ny=y;
		if(arr)nx+=mx[i];
		else ny+=mx[i];
		if(nx<0||ny<0||nx>=n||ny>=m||ma[nx][ny])continue;
		find(nx,ny,!arr,step+1);
	}
	ma[x][y]=false;
	return ans;
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	cin>>n>>m;
	/*solve*/
	find(0,0,true);
	find(0,0,false);
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

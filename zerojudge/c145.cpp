/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c145
[WA 90%]
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
/*fn定義*/
void out(INT x,INT y,INT aa){
	if(!debug)return;
	for(INT i=0;i<aa;i++){
		cout<<" ";
	}
	cout<<x<<","<<y<<"\n";
}
inline INT find(INT x,INT y,bool arr){
	if(x<0 || y<0 || x>=n || y>=m || ma[x][y]){
		return 0;
	}else{
		ma[x][y]=true;
		//out(x,y,aa);
		INT re=0;
		if(arr){
			INT nx=x+1;
			INT ny=y;
			if(!(x>=n || ma[nx][ny]))re=max(1+find(nx,ny,!arr),re);
			nx=x-1;
			ny=y;
			if(!(x<0 || ma[nx][ny]))re=max(1+find(nx,ny,!arr),re);
		}else{
			INT nx=x;
			INT ny=y+1;
			if(!(y>=m || ma[nx][ny]))re=max(1+find(nx,ny,!arr),re);
			nx=x;
			ny=y-1;
			if(!(y<0 || ma[nx][ny]))re=max(1+find(nx,ny,!arr),re);
		}
		ma[x][y]=false;
		return re;
	}
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
	cout<<max(find(0,0,true),find(0,0,false))<<"\n";
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

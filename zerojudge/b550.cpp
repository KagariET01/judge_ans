/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b550
[give up]
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
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT block[4][3][3]={
	{
		{1,1,1},
		{0,1,0},
		{0,0,0}
	},
	{
		{1,0,0},
		{1,1,0},
		{1,0,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,0,0}
	},
	{
		{0,1,0},
		{1,1,0},
		{0,1,0}
	}
};
INT n,m;
INT mp[11][11];
string str;
vector<pair<INT,PII>> ansblock;
//{方向,{x,y}}
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	cin>>n>>m;
	for(INT i=1;i<=n;i++){
		cin>>str;
		for(INT j=0;j<m;j++){
			if(str[j]=='X'){
				mp[i][j+1]=-1;
			}
		}
	}
	/*solve*/
	INT ans=0; 
	for(INT x=1;x<n;x++){
		for(INT y=1;y<=m;y++){
			/*放置ㄐ木*/
			for(INT r=0;r<4;r++){//4方向
				bool canput=true;
				//確認是否可放
				for(INT i=0;i<3&&canput;i++){
					for(INT j=0;j<3&&canput;j++){
						if(block[r][i][j]){//表這一格需要放方塊
							if(mp[x+i][y+j]){//表那邊有東西，不能放
								canput=false;
							}
						}
					}
				}
				if(canput){
					ans+=1;
					ansblock.push({r,{x,y}});
				}
			}
		}
	}
	cout<<ans<<endl;
	for(pair<INT,PII> i:ansblock){

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

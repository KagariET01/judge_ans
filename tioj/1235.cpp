/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[]
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

INT ctoi(char c){
	switch(c){
		case '*':
			return 0;
		break;
		case 'R':
			return 1;
		break;
		case 'O':
			return 2;
		break;
		case 'Y':
			return 3;
		break;
		case 'G':
			return 4;
		break;
		case 'B':
			return 5;
		break;
		case 'I':
			return 6;
		break;
		case 'P':
			return 7;
		break;
		case 'L':
			return 8;
		break;
		case 'W':
			return 9;
		break;
	}
}

char itoc(INT i){
	switch(i){
		case 0:
			return '*';
		break;
		case 1:
			return 'R';
		break;
		case 2:
			return 'O';
		break;
		case 3:
			return 'Y';
		break;
		case 4:
			return 'G';
		break;
		case 5:
			return 'B';
		break;
		case 6:
			return 'I';
		break;
		case 7:
			return 'P';
		break;
		case 8:
			return 'L';
		break;
		case 9:
			return 'W';
		break;
	}
}

bool jl[9][10],il[9][10],nl[3][3][10];
INT mp[9][9];
vector<INT> ans[9];
void next(INT x,INT y);
bool finished=false;
void solve(INT x=0,INT y=0){
	if(x>=9){//如果全部跑完ㄌ，就把ans印出來，並設定finished為true防止他繼續往下跑
		finished=true;
		for(vector<INT> i:ans){
			for(INT j:i){
				cout<<itoc(j);
			}
			cout<<endl;
		}
	}elif(mp[x][y]){//如果這裡已經有值
		next(x,y);
	}else{
		for(INT i=1;i<=9 && (!finished);i++){
			bool &a=jl[y][i];
			bool &b=il[x][i];
			bool &c=nl[x/3][y/3][i];
			if(!a && !b && !c){//如果行、列、方都沒有數字i，代表說這裡可以放i
				a=true;//先假設這裡放i
				b=true;
				c=true;
				ans[x].push_back(i);
				next(x,y);
				a=false;
				b=false;
				c=false;
				ans[x].pop_back();
				//其實結構有點像DFS，第一個空格填1，那其他空格可以填甚麼......
			}
		}
	}
}
void next(INT x,INT y){
	if(y>=8){
		solve(x+1,0);
	}else{
		solve(x,y+1);
	}
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		for(INT i=0;i<9;i++){
			string c;
			cin>>c;
			for(INT j=0;j<9;j++){
				mp[i][j]=ctoi(c[j]);
			}
		}
		/*solve*/
		for(INT i=0;i<9;i++){
			for(INT j=0;j<9;j++){
				jl[j][mp[i][j]]=true;
				il[i][mp[i][j]]=true;
				nl[i/3][j/3][mp[i][j]]=true;
			}
		}
		solve();
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

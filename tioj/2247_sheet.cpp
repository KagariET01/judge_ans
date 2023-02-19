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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}


INT mx[]={-1,-1,0,0,1,1};
INT my[]={0,1,-1,1,-1,0};


char keyb[3][10]={
	{'q','w','e','r','t','y','u','i','o','p'},
	{'a','s','d','f','g','h','j','k','l',' '},
	{'z','x','c','v','b','n','m',' ',' ',' '}
};

map< pair<char,char> , INT> ptop;

void bfs(INT nwx,INT nwy,char st=' ',INT nwnn=0){//st=剛開始時的字母,nwx,nwy=現在位在的座標,nwnn=st到這裡的距離
	if(0<=nwx && nwx<3 && 0<=nwy && nwy<<10){
		if(st==' ')st=keyb[nwx][nwy];
		if(ptop[{st,keyb[nwx][nwy]}]==0){
			ptop[{st,keyb[nwx][nwy]}]=ptop[{keyb[nwx][nwy],st}]=nwnn;
			for(INT i=0;i<6;i++){
				bfs(nwx+mx[i],nwy+my[i],st,nwnn+1);
			}
		}else{
			return;
		}
	}
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	for(INT i=0;i<3;i++){
		for(INT j=0;j<10;j++){
			bfs(i,j);
		}
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
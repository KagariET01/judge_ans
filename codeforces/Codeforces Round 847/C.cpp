/*
[CF]				[Q]https://codeforces.com/contest/1790/problem/C
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=1;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT);
		INT vec[n][n-1];
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n-1;j++){
				vec[i][j]=read(INT);
			}
		}
		INT have[n+1];
		set0(have);
		INT it[n];
		set0(it);
		for(INT i=0;i<n;i++){
			INT last=0;
			for(INT j=0;j<n;j++){
				if(vec[j][it[j]]==last){
					break;
				}else{
					last=vec[j][it[j]];
				}
			}
			cout<<last<<" ";
			for(INT j=0;j<n;j++){
				if(vec[j][it[j]]==last){
					it[j]++;
				}
			}
		}
		cout<<endl;
	}
	/*solve*/
	return 0;
}

/*
[I1]
5 4 4 2 1 4 2 3 2 1 3 4 1 3 3 2 3 1 3 1 2 5 4 2 1 3 2 1 3 5 4 2 3 5 4 1 3 5 4 2 1 5 4 2 3 4 1 3 4 1 2 3 1 2 4 3 2 1 1 3 2 3

[O1]
[I2]
5
4
4 2 1
4 2 3
2 1 3
4 1 3
3
2 3
1 3
1 2
5
4 2 1 3
2 1 3 5
4 2 3 5
4 1 3 5
4 2 1 5
4
2 3 4
1 3 4
1 2 3
1 2 4
3
2 1
1 3
2 3

*/

/*think*/
/*

*/

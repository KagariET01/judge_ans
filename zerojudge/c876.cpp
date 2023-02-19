/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c876
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
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT x,y;
	cin>>x>>y;
	/*solve*/
	INT mx,mn;
	mx=max(x,y);
	mn=min(x,y);
	INT ansstep=0;
	bool wl=true;
	if(mn%3==1){ansstep=mn/3*2;}
	else if(x==y && mn%3==2){ansstep=mn/3*2;}
	else {ansstep=(mn-1)/3*2+1;}
	if(ansstep%2)cout<<"Win ";
	else cout<<"Lose ";
	cout<<ansstep<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

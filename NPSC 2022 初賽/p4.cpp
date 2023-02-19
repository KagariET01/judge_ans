/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
const INT maxlr=1e6;
INT num[maxlr+1];
UINT looptt[maxlr+1];
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	cin>>n;
	for(INT i=0;i<n;i++){
		INT l,r;
		cin>>l>>r;
		num[l]++;
		num[r]--;
	}
	/*solve*/
	INT tt=0;
	for(INT i=1;i<=maxlr;i++){
		tt+=num[i];
		looptt[i]=tt;
	}
	INT ans=0;
	for(INT i=0;i<maxlr;i++){
		ans+=looptt[i]*(looptt[i]-1)/2;
		if(debug){
			cerr<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	if(debug){
		cerr<<endl;
		for(INT i=0;i<maxlr;i++){
			cout<<looptt[i]<<" ";
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

/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]	[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]	[Q]https://cses.fi/problemset/task/ [題目編號]
[]
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
map<PII,bool> tree;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n,m;
	cin>>n>>m;
	INT q;
	cin>>q;
	INT ans=0;
	while(q--){
		INT x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(y1==y2){
			for(INT i=min(x1,x2);i<=max(x1,x2);i++){
				if(!tree[{i,y1}]){
					tree[{i,y1}]=true;
					ans++;
				}
			}
		}else if(x1==x2){
			for(INT i=min(y1,y2);i<=max(y1,y2);i++){
				if(!tree[{x1,i}]){
					tree[{x1,i}]=true;
					ans++;
				}
			}
		}else{
			INT mx=-1;
			if(x1<x2){mx=1;}
			INT my=-1;
			if(y1<y2){my=1;}
			x2+=mx;
			y2=my;
			while(x1!=x2){
				if(!tree[{x1,y1}]){
					tree[{x1,y1}]=true;
					ans++;
				}
				x1+=mx;
				y1+=my;
			}
		}
	}
	/*solve*/
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

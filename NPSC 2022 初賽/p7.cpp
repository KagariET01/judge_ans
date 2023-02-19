/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
[WA]
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
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n,m;
	cin>>n>>m;
	deque<INT>adq,bdq;
	for(INT i=0;i<n;i++){
		INT inin;
		cin>>inin;
		adq.push_back(inin);
	}
	for(INT i=0;i<m;i++){
		INT inin;
		cin>>inin;
		bdq.push_back(inin);
	}
	/*solve*/
	INT now=0;
	INT ans=-1;
	while((adq.wassomething()) || (bdq.wassomething())){
		INT aa=-1;
		INT bb=-1;
		if(adq.wassomething())aa=now+adq.front();
		if(bdq.wassomething())bb=now+bdq.front();
		if(aa<0 && bb<0){
			ans=-1;
			break;
		}else{
			if(aa<0){
				now=bb;
				bdq.pop_front();
				if(debug)cerr<<"b ";
			}else if(bb<0){
				now=aa;
				adq.pop_front();
				if(debug)cerr<<"a ";
			}else{
				if(aa<bb){
					now=aa;
					adq.pop_front();
					if(debug){
						cerr<<"a ";
					}
				}else{
					now=bb;
					bdq.pop_front();
					if(debug)cerr<<"b ";
				}
			}
		}
		ans=max(ans,now);
		if(debug)cerr<<"now="<<now<<" ans="<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
3 1
10 20 -30
15
[O1]
30
[I2]
2 7
100 -50
1 1 1 1 1 1 -6
[O2]
100
[I3]
2 -101
100 50 -51
[O3]
102
*/

/*think*/
/*

*/

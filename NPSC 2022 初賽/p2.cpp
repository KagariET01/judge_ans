/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
[tioj]		[Q]https://tioj.ck.tp.edu.tw/problems/ [題目編號]
[cses]		[Q]https://cses.fi/problemset/task/ [題目編號]
[vjudge]	[Q]https://vjudge.net/problem/ [題目編號]
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
map<string,bool> astrhave;
map<string,bool> count;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	string astr;
	cin>>astr;
	string nstr="";
	for(INT i=astr.size()-1;i>=0;i--){
		nstr=astr[i]+nstr;
		astrhave[nstr]=true;
		if(debug){
			cerr<<nstr<<endl;
		}
	}
	INT n;
	cin>>n;
	while(n--){
		string bstr;
		cin>>bstr;
		INT bs=bstr.size();
		INT ans=-1;
		string bnowstr="";
		for(INT i=0;i<bs;i++){
			bnowstr=bnowstr+bstr[i];
			if(astrhave[bnowstr])ans=max(ans,min(i+1,bs-(i+1)));
		}
		cout<<ans<<endl;
	}
	/*CIN*/
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

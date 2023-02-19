/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a451
[TLE]
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
struct stru{
	INT first;//n
	INT second;//m
	INT third;//id
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT mf[2];
vector<stru>nmlist;
map<INT,INT>ans;
INT abc[21];
/*fn定義*/
bool vs(stru a,stru b){
	return a.first<b.first;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	INT nn,nm;
	INT nid=0;
	INT mxn=0;
	while(cin>>nn>>nm){
		/*CIN*/
		nmlist.push_back({nn,nm,nid});
		nid++;
		mxn=max(mxn,nn);
	}
	/*solve*/
	sort(nmlist.begin(),nmlist.end(),vs);
	INT nwadd=0;
	abc[0]=1;
	for(INT i=1;i<20;i++){
		abc[i]=abc[i-1]<<1;
	}
	for(INT i=0;i<=mxn;i++){
		if(i==0)mf[i]=0;
		else if(i==1)mf[i]=1;
		else mf[i%2]=mf[0]+mf[1];
		while(nwadd<nmlist.size()&&nmlist[nwadd].first<i){
			nwadd++;
		}
		INT &nwmf=mf[i%2];
		while(nwadd<nmlist.size()&&nmlist[nwadd].first<i+1){
			INT &nwmod=abc[nmlist[nwadd].second];
			INT &nwans=ans[nmlist[nwadd].third];
			nwans=nwmf%nwmod;
			nwadd++;
		}
		if(nwadd>=nmlist.size())break;
	}
	for(INT i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
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

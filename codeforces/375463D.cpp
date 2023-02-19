/*
[CF]				[Q]https://codeforces.com/group/iTpKFww7Hn/contest/375463/problem/D
[WA]
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
#define INT ULLI
#define UINT INT
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
bool debug=0;
bool iofast=true;

INT mod=988244353;

set<INT> se;
map<INT,INT> nmcount;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

bool vser(PII a,PII b){
	return a>b;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	INT n=read(INT);
	while(n--){
		INT nw=read(INT);
		se.insert(nw);
		nmcount[nw]++;
	}
	/*solve*/
	if(n==1){
		cout<<0;
		return 0;
	}
	vector<PII> vec;//{出現次數,編號}
	for(INT i:se){
		vec.push_back(make_pair(nmcount[i],i));
	}
	if(vec.size()==1){
		cout<<"0"<<endl;return 0;
	}
	sort(vec.begin(),vec.end(),vser);//由大排到小
	INT l=0;
	INT r=1;
	INT ans=0;
	INT ses=vec.size();
	vector<PII> outlog;
	bool end=true;
	while(end){
		while(vec[l].FIR<=0){//如果l那一格沒有東西就往右移
			l++;
			if(l>=ses){end=false;break;}
		}
		if(l>=ses || r>=ses)break;
		if(l>=r){//如果l比r右邊
			r=l+1;//將r往右丟
			if(r>=ses){
				end=false;
				break;
			}
		}
		if(l>=ses || r>=ses)break;
		while(vec[r].FIR<=0){//如果r那一格沒有東西就往右移
			r++;
			if(r>=ses){end=false;break;}
		}
		if(l>=ses || r>=ses)break;

		INT outcount=min(vec[l].FIR,vec[r].FIR);//兩種數字相消最多可以得到多少分
		ans+=outcount;
		vec[l].FIR-=outcount;//數字消掉
		vec[r].FIR-=outcount;//數字消掉
		while(outcount--){//將這個結果匯入outlog裡面
			outlog.push_back(make_pair(vec[l].SEC,vec[r].SEC));
		}
	}
	cout<<ans<<endl;
	for(PII i:outlog){
		cout<<i.FIR<<" "<<i.SEC<<endl;
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

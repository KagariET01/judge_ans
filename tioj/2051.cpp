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
#include<stack>
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
bool iofast=0;

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

string s;
INT p=0;
INT ssz;

map<string,INT> resulter(map<string,INT> nw,map<string,INT> gt,string nws,INT nwnm){
	if(nwnm==0){nwnm=1;}
	for(P(string,INT) i:gt){
		nw[i.FIR]+=i.SEC*nwnm;
	}
	if(nws!=""){
		nw[nws]+=nwnm;
		nws="";
	}
	return nw;
}


map<string,INT> solve(INT err){
	map<string,INT> nw;
	map<string,INT> gt;
	nw.clear();
	gt.clear();
	string nws="";
	INT nwnm=0;
	while(true){
		/*dbg*/
		cerr<<"p="<<p<<",err="<<err<<",nwnm="<<nwnm;
		if(p<ssz){
			cerr<<",nwc="<<s[p];
		}
		cerr<<endl;



		if('a'<=s[p] && s[p]<='z'){//小寫字
			nws.push_back(s[p]);
		}elif('A'<=s[p] && s[p]<='Z'){//大寫字
			resulter(nw,gt,nws,nwnm);
			nwnm=0;
			nws="";
			nws.push_back(s[p]);
			p++;
		}elif('0'<=s[p]<='9'){//數字
			nwnm*=10;
			nwnm+=s[p]-'0';
			p++;
		}
		if(p>=ssz || s[p]==')'){//尾端
			return nw;
		}
		if(s[p]=='('){//遞迴開始
			if(nwnm==0){nwnm=1;}
			cerr<<"nwnm="<<nwnm<<endl;
			if(gt.wassomething()){
				for(P(string,INT) i:gt){
					nw[i.FIR]+=i.SEC*nwnm;
				}
				gt.clear();
			}
			if(nws!=""){
				nw[nws]+=nwnm;
				nws="";
			}
			nwnm=0;
			p++;
			gt=solve(err+1);
			cerr<<"loop end, nwnm="<<nwnm<<endl;
			p++;
		}
	}

}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		s=read(string);
		ssz=s.size();
		/*solve*/
		map<string,INT> ans;
		ans=solve(0);
		for(P(string,INT) i:ans){
			cout<<i.FIR<<":"<<i.SEC<<endl;
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
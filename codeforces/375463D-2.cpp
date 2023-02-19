/*
[CF]				[Q]https://codeforces.com/group/iTpKFww7Hn/contest/375463/problem/D
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
		se.insert(nw);//紀錄清單a裡面有nw
		nmcount[nw]++;//nmcount[nw]=nw出現的次數
	}
	/*solve*/
	if(n==1){//如果總數量只有0就直接離開
		cout<<0;
		return 0;
	}
	priority_queue<PII> vec;//{出現次數,編號}
	for(INT i:se){//將資料搬到vec
		vec.push(make_pair(nmcount[i],i));
	}
	INT ans=0;
	vector<PII> outlog;
	while(vec.size()>=2){
		PII a=vec.top();//把資料取出來
		vec.pop();
		PII b=vec.top();
		vec.pop();
		if(a.FIR<=0 || b.FIR<=0)break;//如果沒資料就跳出
		//INT adder=min(a.FIR,b.FIR);//這兩種數字最多能互消幾次
		INT adder=1;
		a.FIR-=adder;//把數字削掉
		b.FIR-=adder;
		if(a.FIR>0)vec.push(a);//如果還有剩下，就把它放回去
		if(b.FIR>0)vec.push(b);
		ans+=adder;
		while(adder--){
			outlog.push_back(make_pair(a.SEC,b.SEC));
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

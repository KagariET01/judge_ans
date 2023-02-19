/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2246
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=h557
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
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;



bool inr(INT x1,INT y1,INT x2,INT y2,INT r){
	INT x=x2-x1;
	x*=x;
	INT y=y1-y2;
	y*=y;
	INT dt=x+y;
	return dt<=r*r;
}

vector<PII> distance_r(PII p1,INT r){//枚舉每個對p1距離r單位的點
	INT xmn=p1.FIR-r;
	INT xmx=p1.FIR+r;
	INT ymn=p1.SEC-r;
	INT ymx=p1.SEC+r;
	vector<PII> re;
	re.clear();
	for(INT x=xmn;x<=xmx;x++){
		for(INT y=ymn;y<=ymx;y++){
			if(inr(p1.FIR,p1.SEC,x,y,r)){
				re.push_back({x,y});
			}
		}
	}
	return re;
}
INT solve(vector<PII> vec,INT r){
	map<PII,INT> mp;
	for(PII i:vec){//枚舉每個圖騰
		vector<PII> canp=distance_r(i,r);//計算出每個距離他r以內的點
		for(PII j:canp){//每個距離他r以內的點都記錄+1
			mp[j]++;
		}
	}
	//全部點計算完成後，mp[i]就代表點i有多少個圖騰距離他r以內
	INT re=0;
	for(pair<PII,INT> i:mp){
		if(i.SEC%2)re++;
	}
	return re;
}

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
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT),r=read(INT);
		vector<PII> vec(n);
		loop(i,0,n){
			cin>>vec[i].FIR;
			cin>>vec[i].SEC;
		}
		/*solve*/
		cout<<solve(vec,r)<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
枚舉每個雕像
當枚舉到一個雕像時
計算距離該雕像r以內的所有點
紀錄那些點碰到的雕像+1



*/

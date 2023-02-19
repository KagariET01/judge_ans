/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[RE+TLE]
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
bool iofast=1;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
const INT mxn=2e5;
const INT mxa=2e5;
set<INT> se;//紀錄那些數值有標記
INT adder[mxn+5];
INT origad[mxn+5];
INT ma[mxa+5];//ma[i]=j代表nw需要+i*j
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
	/*CIN*/
	INT t=1;
	while(t--){
		INT n,q;
		cin>>n>>q;
		//處理初始資料
		INT nwtot=0;
		loop(i,1,n+1){
			nwtot+=read(INT);
			origad[i]=nwtot;
		}
		//處理q比詢問
		while(q--){
			INT id=read(INT);//動作id
			if(id==1){//區間加值
				INT l,r,dd;
				cin>>l>>r>>dd;
				se.insert(l);
				se.insert(r+1);
				adder[l]+=dd;
				adder[r+1]-=dd;
			}else{//區間求和
				INT l,r;
				cin>>l>>r;
				INT nw=origad[r]-origad[l-1];
				if(se.wassomething()){
					set<INT>::iterator it=se.begin();
					set<INT>adset;//若ma[i]不為0，則紀錄i到adset
					INT bef=0;
					while(*it<l && it!=se.end()){
						bef+=adder[*it];
						it++;
					}
					{
						INT wantadd=bef;//需要增加的值
						INT xx=r-(l)+1;//增加的值的數量
						if(wantadd<0){//如果是刪除，那就正負交換
							wantadd=-wantadd;//此值永遠正
							xx=-xx;
						}
						INT abmx=max(wantadd,xx);
						INT abmn=min(wantadd,xx);
						ma[abmx]+=abmn;
						adset.insert(abmx);
					}
					while(*it<=r && it!=se.end()){//[l,r]
						INT wantadd=adder[*it];//需要增加的值
						INT xx=r-(*it)+1;//增加的值的數量
						if(wantadd<0){//如果是刪除，那就正負交換
							wantadd=-wantadd;//此值永遠正
							xx=-xx;
						}
						INT abmx=max(wantadd,xx);
						INT abmn=min(wantadd,xx);
						ma[abmx]+=abmn;
						adset.insert(abmx);
						it++;
					}
					for(INT i:adset){
						nw+=i*ma[i];
						ma[i]=0;
					}
				}
				cout<<nw<<endl;
			}
		}
	}
	/*solve*/
	return 0;
}

/*
[I1]
5 4 32 4 1 8 2 2 2 4 1 3 3 63 2 1 5 2 2 5
[O1]
*/

/*think*/
/*

*/

/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2054
[雙指標]
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
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

bool vser(PII a,PII b){
	return a.FIR<b.FIR;
}

vector<PII>vec;




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		INT l,w;
		cin>>l>>w;
		vec.resize(n);
		for(INT i=0;i<n;i++){
			vec[i]={read(INT),read(INT)};
		}
		/*solve*/
		INT ans=0;
		sort(vec.begin(),vec.end(),vser);
		INT lx=0;
		for(INT rx=0;rx<n;rx++){//第一個雙指標
			while(vec[rx].FIR-vec[lx].FIR>w){
				lx++;
			}
			//第二個雙指標st
			vector<INT> yvec;
			yvec.clear();
			for(INT i=lx;i<=rx;i++){
				yvec.push_back(vec[i].SEC);
			}
			sort(yvec.begin(),yvec.end());
			INT ly=0;
			for(INT ry=0;ry<yvec.size();ry++){
				while(yvec[ry]-yvec[ly]>l){
					ly++;
				}
				ans=max(ans,ry-ly+1);
			}
			//第二個雙指標ed
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
農兩個雙指標
第一個雙指標在最一開始就建立
該雙指標代表選取框的x座標

框好之後建第二個雙指標
異曲同工，這次是代表y座標的
*/

/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/1231
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

vector<PII> vec;//格式：{熱量,保存期限}

bool vser(PII a,PII b){
	if(a.SEC==b.SEC)return a.FIR>b.FIR;//保存期限一樣的話，熱量多的先吃
	else return a.SEC<b.SEC;//保存期限低的先吃
}




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		/*CIN*/
		INT n=read(INT);
		for(INT i=0;i<n;i++){
			vec.push_back({read(INT),read(INT)});
		}
		INT t=read(INT);
		/*solve*/
		INT ans=0;
		sort(vec.begin(),vec.end(),vser);
		priority_queue(INT,vector<INT>,greater<INT>) que;//儲存要吃的熱量
		for(PII i:vec){
			if(i.SEC < que.size() && que.size()<t){//第一式為吃完que裡的東西，i還沒過期，那就可以吃，第二式為所有東西吃完後，比賽還沒結束
				que.push(i.FIR);//吃
				ans+=i.FIR;
			}elif(que.top()<i.FIR){//如果原本吃的熱量比較少
				ans-=que.top();
				que.pop();
				que.push(i.FIR);
				ans+=i.FIR;
			}
		}
		cout<<ans-(t-que.size())<<endl;
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

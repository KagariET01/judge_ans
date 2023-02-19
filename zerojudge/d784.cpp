/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid=d784
[AC]
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
	if(!debug&&iofast)what_the_fuck;
	INT t;
	cin>>t;
	while(t--){
		/*CIN*/
		INT n;
		cin>>n;
		INT now=0;
		INT ans=-10001;
		deque<INT> dq;
		INT mx=-10001;
		for(INT i=0;i<n;i++){
			INT a;
			cin>>a;
			mx=max(mx,a);
			/*solve*/
			dq.push_back(a);
			now+=a;
			while(now<0){
				now-=dq.front();
				dq.pop_front();
			}
			ans=max(ans,now);
		}
		if(dq.size()==0)cout<<mx<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
3
5 1 2 -3 4 5
5 1 2 3 4 5
6 10 -5 7 6 -1 -3
[O1]
9
15
18
*/

/*think*/
/*

*/

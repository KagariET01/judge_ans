/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2248
[DFS]
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
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

const INT mxn=1e5;
INT w[mxn+1];
vector<INT> vec[mxn+1];
map<PII,INT> mp;
INT ans=0;
INT n,k;

void dfs(INT n,INT lst=-1){
	//cerr<<"w["<<n<<"]="<<w[n]<<endl;
	for(INT i:vec[n]){
		if(lst==i)continue;
		//cerr<<n<<">"<<i<<endl;
		dfs(i,n);
		w[n]+=w[i]-k;
		ans+=abs(w[i]-k)*mp[{n,i}];
		w[i]=k;
	}
}






/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT t=1;
	while(t--){
		set0(w);
		for(INT i=0;i<mxn;i++){
			vec[i].clear();
		}
		ans=0;
		mp.clear();
		/*CIN*/
		cin>>n>>k;
		for(INT i=0;i<n;i++){
			cin>>w[i];
		}
		for(INT i=0;i<n-1;i++){
			INT u,v,d;
			cin>>u>>v>>d;
			u--;
			v--;
			vec[u].push_back(v);
			vec[v].push_back(u);
			mp[{u,v}]=mp[{v,u}]=d;
		}
		/*solve*/
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
8 2
4 2 2 1 3 3 0 1
1 2 3
2 3 1
3 4 2
5 6 2
6 7 3
6 8 1
2 6 3
[O1]
21
[I2]
4 3
1 10 0 1
1 4 3
3 2 2
4 2 1
[O2]
16
*/

/*think*/
/*

*/

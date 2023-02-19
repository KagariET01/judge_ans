/*
[Q]https://zerojudge.tw/ShowProblem?problemid=c877
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
/*struct*/
/*fn宣告*/
/*num*/
bool debug=true;
vector<INT> vec[51];
INT ma[51][51];
INT k,m,n,p;
INT ans=0;
INT total=0;
//k為小木屋數
//m為容器大小
//n為作業時間
//連接小木屋數
//編號
/*fn定義*/
/*INT*/void dfs(INT timeless,INT place,INT now=0,INT dbg=0){
	ans=max(now,ans);
	if(debug && ans==total){
		cout<<dbg<<","<<timeless<<","<<place<<","<<now<<"\n";
	}
	if(timeless==0||now+timeless*m<=ans||ans==total)return;
	else{
		//INT re=0;
		for(auto i:vec[place]){
			if(now+timeless*m<=ans||ans==total)return;
			INT cantake=min(ma[i][place],m);
			if(cantake<0)continue;
			ma[i][place]-=cantake;
			ma[place][i]-=cantake;
			/*INT nre=cantake+*/dfs(timeless-1,i,now+cantake,dbg+1);
			ma[i][place]+=cantake;
			ma[place][i]+=cantake;
			/*re=max(re,nre);*/
		}
		//ans=max(ans,re);
		//return re;
	}
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>k>>m>>n>>p;
	while(p--){
		INT a,b,c;
		cin>>a>>b>>c;
		total+=c;
		ma[a][b]=c;
		ma[b][a]=c;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	/*solve*/
	dfs(n,1,0);
	cout<<ans;
	return 0;
}

/*
[I1]
4 1 50 4
1 2 2
1 3 0
2 3 3
3 4 10
[O1]
15
[I2]
4 2 7 4
1 2 1
1 3 3
2 3 0
3 4 20
[O2]
14
*/

/*think*/
/*

*/

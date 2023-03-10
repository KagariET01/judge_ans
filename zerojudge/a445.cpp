/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a445
[AC]
[#]tree,dsu
*/

/*include*/
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
/*自訂義*/
const INT maxn=10000;
/*num*/
INT dsu[maxn];
/*fn定義*/
void dsu_re(INT n){//初始化
	for(INT i=0;i<n;i++){
		dsu[i]=i;
	}
}
INT dsu_find(INT n){//尋找此值的老大
	if(dsu[n]==n)return n;//如果自己就是老大，回報自己
	INT root=dsu_find(dsu[n]);//找尋他的老大
	//dsu[n]=n的爸爸
	dsu[n]=root;//把老大當自己爸爸
	return root;//回報自己ㄉ老大
}
INT dsu_insert(INT a,INT b){//將a和b連在一起
	dsu[dsu_find(a)]=dsu_find(b);
	//讓a的老大歸順b的老大
}
bool dsu_get(INT a,INT b){//查詢a和b是否連線
	return dsu_find(a)==dsu_find(b);
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	INT n,m,q;
	//n為人數
	//m為朋友關係有幾筆
	//q為問題數
	cin>>n>>m>>q;
	dsu_re(n);
	while(m--){
		INT a,b;
		cin>>a>>b;
		dsu_insert(a,b);
	}
	while(q--){
		INT a,b;
		cin>>a>>b;
		if(dsu_get(a,b))cout<<":)\n";
		else cout<<":(\n";
	}
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
dsu[n]裡面，有一些老大
有幾棵樹，就有幾個老大
單顆樹裡的所有節點都連向老大
只需要看兩節點的老大是否相同，就可以知道是不是在同一棵樹上
*/

/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid=d449
[TLE]
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
const INT mxn=10000;
INT dsu[mxn+1];
INT n;
INT m;
/*fn定義*/
void dsu_re(INT n){//初始化
	for(INT i=1;i<=n;i++){
		dsu[i]=i;
	}
}
INT dsu_find(INT a){
	if(dsu[a]==a)return a;
	INT p=dsu_find(dsu[a]);
	dsu[a]=p;
	return p;
}
void dsu_insert(INT a,INT b){//將a和b連在一起
	dsu[dsu_find(a)]=dsu_find(b);
	//讓a的老大歸順b的老大
}
bool dsu_get(INT a,INT b){//查詢a和b是否連線
	return dsu_find(a)==dsu_find(b);
}
void dsu_pop(INT a){
	INT newboss=0;//新老大
	INT aboss=dsu_find(a);//a的老大
	if(aboss==a){//如果自己就是老大
		for(INT i=0;i<n;i++){//找尋跟隨a的人，將它設為老大
			if(i==a)continue;
			if(dsu[i]==a){
				newboss=i;
				break;
			}
		}
	}else{//如果自己不是老大
		newboss=dsu_find(a);//教歸順a的人全部歸順 a的老大
	}
	for(INT i=0;i<n;i++){//所有人跟隨新老大
		if(dsu[i]==a){
			dsu[i]=newboss;
		}
	}
	dsu[a]=a;//自己被孤立了，那自己就是自己的老大
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	while(cin>>n>>m){
		/*re:0*/
		dsu_re(n);
		/*CIN*/
		while(m--){
			INT a,x,y;
			cin>>a;
			if(a==1){
				cin>>x>>y;
				/*solve*/
				dsu_insert(x,y);
			}
			if(a==2){
				cin>>x;
				/*solve*/
				dsu_pop(x);
			}
			if(debug){
				for(INT i=1;i<=n;i++){
					cout<<dsu[i]<<" ";
				}
				cout<<endl;
			}
		}
		set<INT> se;
		for(INT i=1;i<=n;i++){
			se.insert(dsu_find(i));
		}
		cout<<se.size()<<endl;
	}
	return 0;
}

/*
[I1]
4 4
1 1 2
1 1 3
2 1
1 1 4
[O1]
2
*/

/*think*/
/*

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b333
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
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
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define P_B push_back 
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
INT n,m;
set<INT> tree[1001];
INT lv[1001];
INT inc[1001];
bool nxt[1001][1001];
//PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
//INT mx[]={0,1,0,-1};
//INT my[]={1,0,-1,0};
//INT mod=988244353;
/*struct定義*/
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n>>m;
	for(INT i=0;i<m;i++){
		//輸入該列車的停站數
		INT a;
		cin>>a;
		//re:0
		vector<INT>b;
		b.clear();
		INT inin;
		//讀入該列車的所有停靠站編號
		for(INT j=0;j<a;j++){
			cin>>inin;
			b.P_B(inin);
		}
		//now為一個迭代器，從起點站跑到終點站(啟終站不跑)
		INT now;
		//將迭代器移動到起點的下一個車站
		now=b[0]+1;
		for(INT j=1;j<a;j++){
			while(now<b[j]){
				//移動迭代器到第二站之前，且在這之間
				DBG cerr<<now<<" ";
				for(INT k:b){
					if(nxt[now][k]==false){
						nxt[now][k]=true;
						inc[k]++;
						tree[now].insert(k);
					}
				}
				now++;
			}
			now=b[j]+1;
		}
		DBG cerr<<endl;
	}
	DBG{
		cerr<<"link list"<<endl;
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<=n;j++){
				cerr<<nxt[i][j]<<" ";
			}
			cerr<<endl;
		}
		cerr<<endl;
		cerr<<"inc"<<endl;
		for(INT i=1;i<=n;i++){
			cerr<<inc[i]<<" ";
		}
		cerr<<endl;
	}
	/*solve*/
	//拓撲排序，設定起點
	deque<INT> worklist;
	DBG cerr<<"first:";
	for(INT i=1;i<=n;i++){
		if(inc[i]==0){
			worklist.P_B(i);
			lv[i]=1;
			DBG cerr<<i<<" ";
		}
	}
	DBG cerr<<endl;
	//拓撲排序ing
	while(worklist.wassomething()){
		INT now=worklist.front();
		worklist.pop_front();
		DBG cerr<<"do"<<now<<endl;
		for(INT i:tree[now]){
			inc[i]--;
			lv[i]=lv[now]+1;
			if(inc[i]==0){
				worklist.P_B(i);
			}
		}
	}
	INT ans=1;
	for(INT i=1;i<=n;i++){
		ans=max(ans,lv[i]);
	}
	cout<<ans<<endl;
	DBG{
		cerr<<"lv"<<endl;
		for(INT i=1;i<=n;i++){
			cerr<<lv[i]<<" ";
		}
		cerr<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
先給自製範例測資
[I]
10 1
5 1 3 5 7 9
[O]
2
我們可以清楚發現
2,4,6,8,10為lv1車站
1,3,5,7,9為lv2車站
而列車1等級為lv2
(列車等級定義：設列車i等級為a，則區間所有等>=a的車站都會停)

[拓撲排序]
拓撲排序可以排序出事情的先後順序
假設有一棵樹
節點個數3
1>2
1>3
2>3
我們可以畫出下面的樹
1--2--3
 \___/
我們最初可以先做的事情只有事情1
所以事情1的先後順序為1-------------a
因為她一定要先做，才能做其他的事
做完1後，我們可以做2
所以事情2的先後順序為2-------------b
為甚麼做完1後不能直接做3
因為你要先做完2才能去做3
所以要先做完1,2才能做3
那做同樣的運算，事情3的先後順序為3--c
根據a,b和c式可得下列結論
事情1的等級為1
事情2的等級為2
事情3的等級為3
我們還可以看出一件事:
假設有條線a>b
那a的等級一定比b小
[/拓撲排序]
從題目中可得知，[列車略過的車站]的level都比[列車會停的車站]低
再從剛剛的[拓撲排序]最後得到的結論
[
假設有條線a>b
那a的等級一定比b小
]
義即假如我們將[列車略過的車站(a)]連到[列車會停的車站(b)]
就能保證a的等級一定比b小
然後a車站就能順利地被列車略過
把樹建完後，我們再去跑[拓撲排序]
尋找出等級最大的車站
該等級即為所求
*/

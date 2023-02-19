/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d875
[AC]
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/
/*fn宣告*/

/*num*/
INT a,b,c;
INT D[1000000+2];

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	cin>>a>>b>>c;
	c/=b;
	priority_queue<PII> q;//{高,位置}
	for(INT i=1;i<=a;i++){
		PII inin;
		cin>>inin.first;
		inin.first/=b;
		inin.second=i;
		D[i]=inin.first;
		q.push(inin);
	}
	/*solve*/
	INT ans=0;
	while(!q.empty()){
		PII nown=q.top();
		INT &nowid=nown.second;
		INT &nowh=nown.first;
		q.pop();
		if(nowh!=D[nowid]){
			q.push({D[nowid],nowid});//同步資訊
			continue;
		}
		if(nowid-1>=1){
			if(D[nowid-1]-nowh>c){//確認兩者差距是否超過
				INT num=D[nowid-1]-nowh-c;//差距-允許差距=移出數量
				D[nowid-1]-=num;
				ans+=num;
				q.push({D[nowid-1],nowid-1});//將左邊的數值丟進去
			}
		}
		if(nowid+1<=a){
			if(D[nowid+1]-nowh>c){//確認兩者差距是否超過
				INT num=D[nowid+1]-nowh-c;//差距-允許差距=移出數量
				D[nowid+1]-=num;
				ans+=num;
				q.push({D[nowid+1],nowid+1});//將左邊的數值丟進去
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

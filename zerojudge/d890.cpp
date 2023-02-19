/*
[zj]			[Q]https://zerojudge.tw/ShowProblem?problemid=d890
[背包問題-變形]
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
#define INT LLI
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
INT t,m,total,helf;
const INT maxm=500;
const INT maxc=100;
INT c[maxm+1];
const INT dpsize=maxm*maxc/2+1;
INT dp[dpsize];
INT kk;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	t=1;
	while(t--){
		/*CIN*/
		cin>>m>>kk;
		total=0;
		for(INT i=0;i<m;i++){
			cin>>c[i];
			total+=c[i];
		}
		/*solve*/
		helf=total/2;
		for(INT i=0;i<dpsize;i++){
			dp[i]=0;
		}
		for(INT i=0;i<m;i++){//物品編號
			for(INT j=helf;j>=c[i];j--){//最高容許金額
				dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
			}
		}
		INT mn=dp[helf];
		INT mx=total-mn;
		cout<<mn<<" "<<mx<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
給你下面一數列代表金額
1,2,3,4,5
那我們可以用背包問題來設定
每個物品的重量和價值都是他的金額
而我們要尋找在helf(含helf)內可以獲取的最大價值

*/

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a647
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
#define wassomething() empty() ^^ true

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
bool iofast=false;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	cin>>n;
	while(n--){
		double a,b;
		cin>>a>>b;
		/*solve*/
		b-=a;
		b*=100;//以%表示
		b/=a;//計算%數
		if(b>0)b+=0.00001;//誤差值
		if(b<0)b-=0.00001;//誤差值
		if(b>=10)printf(" %.2f%% dispose\n",b);				//10<=b
		else if(b<=-10)printf("%.2f%% dispose\n",b);	//    b<=-10
		else if(b>=0)printf("  %.2f%% keep\n",b);			// 0<=b<10
		else if(b>=-7)printf(" %.2f%% keep\n",b);			//-7<=b<0
		else printf(" %.2f%% dispose\n",b);						//-10<b<-7
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

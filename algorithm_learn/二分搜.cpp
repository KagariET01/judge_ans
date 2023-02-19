/*
[二分搜]
[]
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
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
vector<INT> dt;
INT n;
/*fn定義*/
INT dualfind(INT fd){
	INT l=0,r=n;
	while(r-l>1){
		INT mnt=l+r;
		mnt/=2;
		if(dt[mnt]==fd)return mnt;
		else if(dt[mnt]<fd){
			l=mnt;
		}else if(fd<=dt[mnt]){
			r=mnt;
		}
	}
	return r;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	cin>>n;
	dt.push_back(0);
	for(INT i=0;i<n;i++){
		INT a;
		cin>>a;
		dt.push_back(a);
	}
	INT fnd;
	cin>>fnd;
	cout<<dualfind(fnd)<<endl;
	/*solve*/
	return 0;
}

/*
[I]
(元素個數n)
(元素a1) (元素a2) (元素a3) ... (元素an)
(尋找值)
[O]
(位置)
(沒找到就找第一個比他大的數)
*/

/*think*/
/*

*/

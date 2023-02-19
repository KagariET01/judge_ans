/*
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ 1
[]
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=1;
	while(t--){
		INT n=read(INT),x=read(INT);
		INT a[n+1];
		for(INT i=1;i<=n;i++){
			cin>>a[i];	
		}
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
一數列:a1,a2,a3,a4…,an(1<=n<=2000)
該數列存在(i,j,k,l)
1<=i<j<k<l<=n
ai+aj+ak+al==x
請找出有多少組(i,j,k,l)

[1]想法：
分一半
(i,j)(k,l)
暴力兩次
第一次暴力：
跑遍所有的(k,l)
並把ak+al出現的次數記錄起來
紀錄方法：建map<INT,INT> mp;mp[i]=ak+al出現次數
時間複雜度O(n^2)
第二次暴力
INT ans=0;
跑遍所有的(i,j)                       O(n^2)
Ans+=mp[x-ai-aj];              O(log(n))      (因為我們是使用map)
時間複雜度O(n^2*log(n))
總時間複雜度為O(n^2)+O(n^2*log(n))
=O(n^2*log(n))
=>4000000*log(2000)
=4e6*11
=4.4e7<1e8
如果我沒算錯的話：SAFE

[2]想法：
j<k
但是上面的mp並不會記錄k的值
所以可能會跑出k<j的結果
解決方法：
紀錄k=?時，ak+al有多少個

[3]想法：
上面的感覺都太複雜了，需要另想方法

[4]想法：
Dp[n][x]

*/

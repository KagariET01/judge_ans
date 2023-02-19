/*
[CF]				[Q]https://codeforces.com/contest/1791/problem/F
[set]
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
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=0;
const INT mxn=2e5;
map<INT,INT> anslist;
INT a[mxn+1];



/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

INT addall(INT n){
	INT ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	return ans;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT),q=read(INT);
		vector<INT> vec(n+1);
		set<INT> se;
		for(INT i=0;i<n;++i){
			cin>>vec[i];
			if(vec[i]>=10){
				se.insert(i);
			}
		}
		while(q--){
			INT md=read(INT);
			if(md==1){
				INT l,r;
				cin>>l>>r;
				l--;
				set<INT>::iterator lit=se.lower_bound(l);
				set<INT>::iterator rit=se.lower_bound(r);
				set<INT> del;
				for(;lit!=rit;++lit){
					vec[*lit]=addall(vec[*lit]);
					if(vec[*lit]<10)del.insert(*lit);
				}
				for(INT i:del){
					se.erase(i);
				}
			}else{
				cout<<vec[read(INT)-1]<<endl;
			}
		}
	}
	/*solve*/
	return 0;
}

/*
[I1]
3

5 8
1 420 69 1434 2023
1 2 3
2 2
2 3
2 4
1 2 5
2 1
2 3
2 5

2 3
9999 1000
1 1 2
2 1
2 2

1 1
1
2 1
[O1]
*/

/*think*/
/*

*/

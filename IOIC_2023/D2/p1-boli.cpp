/*
[ioic_2023]	[Q]https://judge.ioicamp.org/contests/2/problems/201
[not ans]
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
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
#define Dloop(i,s,n) for(i=s;i<n;i++)
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;

INT mxint=pow(2,31);
INT alis[4];
/*struct定義*/
/*fn定義*/

bool checker(){
	set<INT> se;
	loop(l,0,4){
		INT nw=mxint;
		loop(r,l,4){
			nw&=alis[r];
			if(se.count(nw)){
				return false;
			}
			se.insert(nw);
		}
	}
	return true;
}



template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}



/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	Dloop(alis[0],0,16){
	Dloop(alis[1],0,16){
	Dloop(alis[2],0,16){
	Dloop(alis[3],0,16){
		if(checker()){
			loop(i,0,4){
				cout<<alis[i]<<" ";
			}
			cout<<endl;
		}
	}
	}
	}
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

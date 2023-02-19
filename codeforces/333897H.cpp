/*
[cf]				[Q]https://codeforces.com/group/H0qY3QmnOW/contest/333897/problem/H
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

bool operator>(string a,string b){
	INT len=min(a.size(),b.size());
	for(INT i=0;i<len;i++){
		if(a[i]>b[i])return true;
		elif(a[i]<b[i])return false;
	}
	if(a.size()>b.size())return true;
	else return false;
}

bool operator<(string a,string b){
	INT len=min(a.size(),b.size());
	for(INT i=0;i<len;i++){
		if(a[i]<b[i])return true;
		elif(a[i]>b[i])return false;
	}
	if(a.size()<b.size())return true;
	else return false;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT n=read(INT);
	set<string>se;
	while(n--){
		string s=read(string);
		if(se.count(s)){
			cout<<s<<endl;
			continue;
		}
		se.insert(s);
		set<string>::iterator it=se.find(s);
		if(it==se.begin()){
			cout<<"-1"<<endl;
		}else{
			it--;
			cout<<*it<<endl;
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

*/

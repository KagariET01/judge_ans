/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a227
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
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
/*fn定義*/
void solve(INT ring,char a,char b,char c){
	if(ring>0){
		solve(ring-1,a,c,b);
		cout<<"Move ring "<<ring<<" from "<<a<<" to "<<c<<endl;
		solve(ring-1,b,a,c);
	}
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT n;
	while(cin>>n){
	/*CIN*/
	/*solve*/
	solve(n,'A','B','C');
	cout<<endl;
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=e339
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
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	INT n;
	cin>>n;
	INT alltotal=0;
	for(INT i=0;i<n;i++){
		/*CIN*/
		INT inin;
		cin>>inin;
		/*solve*/
		alltotal+=inin;
		cout<<alltotal<<" ";
	}
	cout<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

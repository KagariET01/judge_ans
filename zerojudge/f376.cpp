/*
[Q]https://zerojudge.tw/ShowProblem?problemid= [題目編號]
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
/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	vector<INT> vec;
	INT n;
	while(cin>>n){
		/*CIN*/
		vec.push_back(n);
	}
	/*solve*/
	sort(vec.begin(),vec.end());
	//if(vec.size()%2){
		cout<<vec[(vec.size()-1)/2];
	//}else{
	//	cout<<(vec[(vec.size()/2)]+vec[(vec.size()/2)-1])/2;
	//}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

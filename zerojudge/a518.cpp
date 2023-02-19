/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a518
[AC]
*/

/*include*/
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

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	INT a,b;
	while(cin>>a>>b){
		if(a==-1)break;
		cout<<min(abs(a-b),100-abs(a-b))<<"\n";
	}
	return 0;
}

/*
[I1]
3 9
0 99
12 27
-1 -1
[O1]
6
1
15
*/

/*think*/
/*

*/

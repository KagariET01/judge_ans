/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b837
[WA 70%]
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
bool debug=false;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT n;
	cin>>n;
	while(n--){
		INT a,b;
		/*CIN*/
		cin>>a>>b;
		if(a>b)swap(a,b);
		/*solve*/
		INT cc=0;
		INT aa=0,bb=1;
		while(true){
			if(aa>b)break;
			if(aa>=a){
				cout<<aa<<"\n";
				cc++;
			}
			bb=aa+bb;
			aa=bb-aa;
		}
		cout<<cc<<"\n";
		if(n){
			cout<<"------\n";
		}
	}
	return 0;
}

/*
[I1]
6
55 200 
90 140
0 0
1 2
2 5
3 0
[O1]
55
89
144
3
------
0
------
0
1
------
1
1
2
3
------
2
3
5
3
------
0
1
1
2
3
5
*/

/*think*/
/*

*/
/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b606
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
	priority_queue<INT,vector<INT>,greater<INT>> que;
	/*CIN*/
	INT n;
	while(cin>>n){
		if(n){
			for(INT i=0;i<n;i++){
				INT a;
				cin>>a;
				que.push(a);
			}
			INT ans=0;
			n-=1;
			while(n--){
				INT a,b;
				a=que.top();
				que.pop();
				b=que.top();
				que.pop();
				ans+=a+b;
				que.push(a+b);
			}
			cout<<ans<<"\n";
			que=priority_queue<INT,vector<INT>,greater<INT>>();
		}else{
			break;
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

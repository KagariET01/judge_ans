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
bool iofast=true;
INT n;
vector<INT> tree[101];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0)break;
		/*Re:0*/
		for(INT i=0;i<=100;i++){
			tree[i].clear();
		}
		/*CIN*/
		INT a;
		while(cin>>a){
			if(a==0)break;
			INT b;
			while(cin>>b){
				if(b==0)break;
				tree[a].push_back(b);
			}
		}
		/*solve*/
		INT q;
		cin>>q;
		while(q--){
			INT ques;
			cin>>ques;
			deque<INT>dq;
			dq.push_back(ques);
			bool link[101];
			INT counter=n;
			bool waswalk[101];
			for(INT i=0;i<=100;i++){//re:0
				link[i]=false;
				waswalk[i]=false;
			}
			while(!dq.empty()){
				INT nown=dq.front();
				dq.pop_front();
				if(waswalk[nown])continue;
				for(INT nx:tree[nown]){
					if(link[nx]){
						continue;
					}
					link[nx]=true;
					counter--;
					dq.push_back(nx);
				}
				waswalk[nown]=true;
			}
			cout<<counter;
			for(INT i=1;i<=n;i++){
				if(!link[i]){
					cout<<" "<<i;
				}
			}
			cout<<endl;
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

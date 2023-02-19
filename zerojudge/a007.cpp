/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a007
[]
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
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT n;
	vector<INT> aaa={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};
	INT wasdo=5;
	while(cin>>n){
		/*CIN*/
		/*solve*/
		if(count(aaa.begin(),aaa.end(),n)>=1){
			cout<<"質數\n";
			continue;
		}
		while(wasdo<=n){
			bool flag=true;
			for(auto i:aaa){
				if(wasdo%i==0 && wasdo/i>1){flag=false;break;}
			}
			if(flag)aaa.push_back(wasdo);
			wasdo++;
			wasdo++;
		}
		if(count(aaa.begin(),aaa.end(),n)>=1)cout<<"質數\n";
		else cout<<"非質數\n";
		//for(auto i:aaa)cout<<i<<",";
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

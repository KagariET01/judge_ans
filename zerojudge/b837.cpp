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
vector<INT> facenum={0,1,1,2,3,5,13,21,34,55,89,144,233};
/*fn定義*/
void addface(){
	facenum.push_back(facenum[facenum.size()-1]+facenum[facenum.size()-2]);
}
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
		while(facenum.back()<=b){
			addface();
			addface();
		}
		vector<INT>::iterator l=lower_bound(facenum.begin(),facenum.end(),a);
		vector<INT>::iterator r=upper_bound(facenum.begin(),facenum.end(),b);
		if(debug)cout<<*l<<","<<*r<<"\n";
		INT cc=0;
		while(r!=l){
			cout<<*l<<"\n";
			l++;
			cc++;
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
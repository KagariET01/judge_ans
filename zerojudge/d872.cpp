/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid=d872
[貪心]
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	/*CIN*/
	INT n;
	while(cin>>n){
		vector<INT>vec;
		while(n--){
			INT a;
			cin>>a;
			vec.push_back(a);
		}
		/*solve*/
		sort(vec.begin(),vec.end());
		INT ans=0;
		while(!vec.empty()){
			switch(vec.size()){
				case 1:
					ans+=vec[0];
					vec.clear();
				break;
				case 2:
					ans+=vec[1];
					vec.clear();
				break;
				case 3:
					ans+=vec[0]+vec[1]+vec[2];
					vec.clear();
				break;
				default:
					INT a,b,y,z;
					a=vec[0];
					b=vec[1];
					y=vec[vec.size()-2];
					z=vec[vec.size()-1];
					ans+=min(b+a+z+b,z+a+y+a);
					vec.resize(vec.size()-2);
				break;
			}
			if(debug){
				cout<<ans<<",";
				for(INT i:vec){
					cout<<i<<" ";
				}
				cout<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
[I1]
4
1 2 5 10
4
1 98 99 100
5
1 3 6 8 12
[O1]
17
299
29
*/

/*think*/
/*

*/

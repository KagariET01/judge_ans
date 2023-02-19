/*
[zj]		[Q]https://zerojudge.tw/ShowProblem?problemid=c128
[WA line4]
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
map<pair<string,string>,INT> mpnum;//mpnum[{s1,s2}]為一值，紀錄該條邊的數值
map<string,vector<string>> mplink;//mplink[s1]為一個vector，紀錄所有和s1有連線的點
map<string,INT>point;//point[s1]紀錄s1的最重重量
INT n,r;
string fr,ad;
INT season=0;
INT ans=0;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	while(cin>>n>>r){
		if(n==0&&r==0)break;
		/*re:0*/
		season++;
		mpnum.clear();
		mplink.clear();
		fr.clear();
		ad.clear();
		ans=0;
		/*CIN*/
		for(INT i=0;i<r;i++){
			string sa,sb;
			INT hva;
			cin>>sa>>sb>>hva;
			mplink[sa].push_back(sb);
			mplink[sb].push_back(sa);
			mpnum[{sa,sb}]=hva;
			mpnum[{sb,sa}]=hva;
		}
		cin>>fr>>ad;
		/*solve*/
		deque<string>dq;
		dq.push_back(fr);
		point[fr]=100001;
		INT maxans=0;
		while(dq.wassomething()){
			string nw=dq.front();
			dq.pop_front();
			for(string i:mplink[nw]){
				INT nxp;
				nxp=min(mpnum[{nw,i}],point[nw]);
				maxans=max(maxans,nxp);
				if(point[i]<nxp){
					point[i]=nxp;
					dq.push_back(i);
				}
				if(debug)cout<<nw<<"=>"<<i<<",point[i]="<<point[i]<<endl;
			}
		}
		cout<<"Scenario #"<<season<<endl;
		cout<<point[ad]<<" tons"<<endl;
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

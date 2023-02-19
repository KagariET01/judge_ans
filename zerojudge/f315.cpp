/*
[Q]https://zerojudge.tw/ShowProblem?problemid=f315
[分治]
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
INT n;
vector<PII>vec;
INT ans=0;
bool num[100005];
/*fn定義*/
void solve(INT l,INT r){
	if(l==r)return;
	INT mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	INT p1=l,p2=mid+1;
	vector<PII>v;
	while(p1<=mid && p2<=r){
		if(vec[p1].first<vec[p2].first){
			v.push_back(vec[p1]);
			p1++;
		}else{
			ans+=(p1-l)*vec[p2].second;
			v.push_back(vec[p2]);
			p2++;
		}
	}
	while(p1<=mid){
		v.push_back(vec[p1]);
		p1++;
	}
	while(p2<=r){
		ans+=(p1-l)*vec[p2].second;
		v.push_back(vec[p2]);
		p2++;
	}
	for(INT i=l;i<=r;i++){
		vec[i]=v[i-l];
	}
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	/*CIN*/
	cin>>n;
	for(INT i=0;i<n*2;i++){
		INT inin;
		cin>>inin;
		vec.push_back({inin,num[inin]?1:-1});
		num[inin]=!num[inin];
	}
	/*solve*/
	solve(0,n*2-1);
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

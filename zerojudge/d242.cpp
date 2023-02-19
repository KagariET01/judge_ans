/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d242
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
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT dp[500001];
INT num[500001];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	INT inin;
	INT n=0;
	/*CIN*/
	while(cin>>inin){
		num[n]=inin;
		n++;
	}
	/*solve*/
	vector<INT> vec;
	vec.push_back(num[0]);
	dp[0]=1;
	INT mx=1;
	for(INT i=1;i<n;i++){
		if(vec.empty()){
			vec.push_back(num[i]);
			mx++;
			dp[i]=mx;
		}else if(num[i]>vec[vec.size()-1]){
			vec.push_back(num[i]);
			mx++;
			dp[i]=mx;
		}else{
			auto it=lower_bound(vec.begin(),vec.end(),num[i]);
			*it=num[i];
			dp[i]=(INT)(it-vec.begin()+1);
		}
	}
	INT sz=mx;
	cout<<sz<<endl<<"-"<<endl;
	vector<INT> ans;
	for(INT i=n-1;i>=0;i--){
		if(dp[i]==mx){
			mx--;
			ans.push_back(num[i]);
		}
	}
	reverse(ans.begin(),ans.end());
	for(INT i:ans){
		cout<<i<<endl;
	}
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
input搞錯，目前懶得修
*/

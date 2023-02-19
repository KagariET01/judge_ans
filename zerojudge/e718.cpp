/*
[Q]https://zerojudge.tw/ShowProblem?problemid=e718
[遞迴]
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
INT n,m;
bool used[10];
INT a[10000001],b[10000001];
INT ans;
string s[10000000],now;
/*fn定義*/
bool checker(string num,string inin,INT a,INT b){
	bool arr[10]={};
	INT cnt1=0,cnt2=0;
	for(INT i=0;i<n;i++){
		arr[inin[i]-'0']=true;
		if(num[i]==inin[i])cnt1++;
	}
	for(INT i=0;i<10;i++){
		if(used[i]&&arr[i])cnt2++;
	}
	if(cnt1==a && cnt2==(b+a))return true;
	return false;
}
INT findans(INT nowp){
	if(nowp==n){
		for(INT i=0;i<m;i++){
			if(!checker(now,s[i],a[i],b[i]))return 0;
		}
		ans++;
		return 0;
	}
	for(INT i=0;i<10;i++){
		if(!used[i]){
			used[i]=true;
			now[nowp]=char('0'+i);
			findans(nowp+1);
			used[i]=false;
		}
	}
	return 0;
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	cin>>n>>m;
	for(INT i=0;i<n;i++){
		now=now+' ';
	}
	for(INT i=0;i<m;i++){
		cin>>s[i]>>a[i]>>b[i];
	}
	/*solve*/
	findans(0);
	cout<<ans<<"\n";
	return 0;
}

/*
[I1]
2 3
12 0 0
34 0 0
56 0 0
[O1]
12
*/

/*think*/
/*

*/

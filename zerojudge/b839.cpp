/*
[Q]https://zerojudge.tw/ShowProblem?problemid=b839
[WA 50%]
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
bool hackmd=false;
INT n;
string name[51];
INT dsulist[51];
INT dsucount[51];
/*fn定義*/
INT solveLCS(string a,string b,INT as=0,INT bs=0){
	if(!as)as=a.size();
	if(!bs)bs=b.size();
	INT dp[as+1][bs+1];
	for(INT i=0;i<=as;i++){
		for(INT j=0;j<=bs;j++){
			/*re:0*/
			dp[i][j]=0;
			if(i&&j){
				/*solveLCS*/
				if(a[i]==b[j]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
		}
	}
	/*if(debug){
		for(INT i=0;i<=as;i++){
			for(INT j=0;j<=bs;j++){
				cout<<dp[i][j]<<",";
			}
			cout<<endl;
		}
	}*/
	return dp[as][bs];
}
INT dsuboss(INT a){
	if(dsulist[a]==a)return a;
	else{
		INT toto=dsuboss(dsulist[a]);
		dsulist[a]=toto;
		return toto;
	}
}
bool dsucheck(INT a,INT b){
	return dsuboss(a)==dsuboss(b);
}
INT dsupush(INT a,INT b){
	INT aboss=dsuboss(a);
	INT bboss=dsuboss(b);
	dsulist[aboss]=bboss;
	return bboss;
}
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT q;
	cin>>q;
	while(q--){
		/*re:0*/
		n=0;
		for(INT i=0;i<=50;i++){
			name[i].clear();
			dsulist[i]=i;
			dsucount[i]=0;
		}
		/*CIN*/
		cin>>n;
		for(INT i=1;i<=n;i++){
			cin>>name[i];
		}
		/*solve*/
		for(INT i=1;i<=n;i++){
			for(INT j=1;j<i;j++){
					//if(debug)cout<<"yes"<<endl;
				if(dsucheck(i,j)){
					continue;
				}
				else{
					INT as=name[i].size();
					INT bs=name[j].size();
					INT linkpoint=solveLCS(name[i],name[j],as,bs);
					if(linkpoint>=min(as,bs)/2.0){
						dsupush(i,j);
						//if(debug)cout<<"yes"<<endl;
					}
				}
			}
		}
		if(debug){
			for(INT i=1;i<=n;i++){
				cout<<dsulist[i]<<",";
			}
			cout<<endl;
		}
		for(INT i=1;i<=n;i++){
			dsucount[dsuboss(i)]++;
		}
		INT ans=0;
		INT p=0;
		for(INT i=1;i<=n;i++){
			if(dsucount[i]>ans){
				ans=max(dsucount[i],ans);
				p=i;
			}
		}
		if(hackmd)cout<<n*2+1<<",";
		cout<<ans<<endl;
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

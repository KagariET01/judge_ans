/*
[Q]
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
#include<iomanip>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}

/*struct*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
INT al[5][10];//a[i][j]表第i組能力編號為j的人有幾個
INT n;
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast){what_the_fuck;}
	/*CIN*/
	cin>>n;
	while(n--){
		INT t;
		cin>>t;
		INT a,b,c;
		cin>>a>>b>>c;
		al[t][(a<<2)+(b<<1)+c]++;
	}
	/*solve*/
	INT ans=0;
	for(INT i=0;i<8;i++){
		if(!al[1][i])continue;
		for(INT j=0;j<8;j++){
			if(!al[2][j])continue;
			for(INT k=0;k<8;k++){
				if(!al[3][k])continue;
				if((i|j|k)==7)ans+=al[1][i]*al[2][j]*al[3][k];
			}
		}
	}
	cout<<ans<<endl;
	DBG{
		for(INT i=1;i<=3;i++){
			for(INT j=0;j<8;j++){
				cerr<<al[i][j]<<" ";
			}
			cerr<<endl;
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

/*
[Q]https://zerojudge.tw/ShowProblem?problemid=d481
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
#define UINT INT
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
	INT a=0,b=0,c=0,d=0;
	while(cin>>a>>b>>c>>d){
		/*CIN*/
		if(b!=c){
			cout<<"Error\n";
			continue;
		}
		INT xA[a][b];
		INT xB[c][d];
		for(INT i=0;i<a;i++){
			for(INT j=0;j<b;j++){
				cin>>xA[i][j];
			}
		}
		for(INT i=0;i<c;i++){
			for(INT j=0;j<d;j++){
				cin>>xB[i][j];
			}
		}
		/*solve*/
		for(INT i=0;i<a;i++){
			for(INT j=0;j<d;j++){
				INT ans=0;
				for(INT k=0;k<b;k++){
					ans+=xA[i][k]*xB[k][j];
				}
				cout<<ans<<" ";
			}
			cout<<"\n";
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
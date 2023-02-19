/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a451
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
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT a[25][1600000];
INT duo[25];
INT facenum[1600000];
INT moder[25];
/*fn定義*/
/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	INT n,m;
	INT aaa=1;
	for(INT i=0;i<25;i++){
		duo[i]=aaa;
		moder[i]=duo[i]*3/2;
		aaa<<=1;
	}
	facenum[0]=facenum[1]=1;
	for(INT i=0;i<1600000;){
		if(i>=2)facenum[i]=facenum[i-1]+facenum[i-2];
		facenum[i]%=duo[21];
		for(INT j=20;j>=0;j--){
			if(moder[j]<i)break;
			a[j][i]=facenum[i]%duo[j];
		}
		i++;
	}
	if(debug){
		for(INT i=0;i<5;i++){
			for(INT j=0;j<=moder[i];j++){
				cerr<<a[i][j]<<" ";
			}
			cerr<<endl;
		}
	}
	while(cin>>n>>m){
		cout<<a[m][(n-1)%moder[m]]<<endl;
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

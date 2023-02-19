/*
[Q]https://zerojudge.tw/ShowProblem?problemid=e603
[WA]
[擴展歐基米德]
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
INT getHCF(INT a,INT b){//尋找最大公因數
	if(b>a)return getHCF(b,a);
	else if(b)return getHCF(b,a%b);
	else return a;
}
/*num*/
bool debug=false;
/*fn定義*/

/*main*/
int main(){
	/*IO加速*/
	if(!debug)cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	INT a,b;
	while(cin>>a>>b){
		/*CIN*/
		//INT d=getHCF(a,b);
		/*solve*/
		INT bigHCF[3][4];
		for(INT i=0;i<3;i++){
			for(INT j=0;j<4;j++){
				bigHCF[i][j]=0;
			}
		}
		//bigHCF[行]={商,餘,s,t}
		bigHCF[0][2]=1;
		bigHCF[1][3]=1;
		bigHCF[0][1]=a;
		bigHCF[1][1]=b;
		INT i=2;
		while(bigHCF[(i-1)%3][1]){
			bigHCF[i%3][0]=bigHCF[(i-2)%3][1]/bigHCF[(i-1)%3][1];
			bigHCF[i%3][1]=bigHCF[(i-2)%3][1]%bigHCF[(i-1)%3][1];
			bigHCF[i%3][2]=bigHCF[(i-2)%3][2]-bigHCF[i%3][0]*bigHCF[(i-1)%3][2];
			bigHCF[i%3][3]=bigHCF[(i-2)%3][3]-bigHCF[i%3][0]*bigHCF[(i-1)%3][3];
			if(debug){
				for(INT j=0;j<4;j++){
					cout<<bigHCF[i%3][j]<<" ";
				}
				cout<<"\n";
			}
			i++;
		}
		INT d,x,y;
		d=bigHCF[(i-1)%3][0];
		x=bigHCF[(i-2)%3][2];
		y=bigHCF[(i-2)%3][3];
		cout<<x<<" "<<y<<" "<<d<<"\n";
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

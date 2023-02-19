/*
[Q]https://zerojudge.tw/ShowProblem?problemid=a825
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

/*fn定義*/
INT ab(INT a,INT b){
	return a>b;
}
INT ee(INT n){
	INT re=1;
	while(n--)re*=10;
	return re;
}
/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	/*CIN*/
	INT m;
	cin>>m;
	INT num[m];
	for(INT i=0;i<m;i++){
		cin>>num[i];
	}
	sort(num,num+m,ab);
	INT a=0,b=0;
	INT p=0;
	for(INT i=0;i<m;i++){
		INT *it;
		if(a<b)it=&a;
		else it=&b;
		*it*=10;
		*it+=num[i];
	}
	cout<<a*b;
	/*solve*/
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

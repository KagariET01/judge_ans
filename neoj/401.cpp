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
#include<cstring>
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
#define DBG if(debug)
#define FIR first
#define SEC second
#define elif else if
#define ifif if
//#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
//#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}
#define wassomething() empty()==false
#define ERR(n) cerr<<"#n="<<n<<endl
/*struct宣告*/
struct mat;
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*struct定義*/
struct mat{
	INT a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &b)const{
		mat re;
		for(INT i=0;i<2;i++){
			for(INT j=0;j<2;j++){
				for(INT k=0;k<2;k++){
					re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return re;
	}
};
/*fn定義*/
PII padd(PII a,PII b){
	return {a.FIR+b.FIR,a.SEC+b.SEC};
}
PII operator-(PII a,PII b){
	return {a.FIR-b.FIR,a.SEC-b.SEC};
}
INT PII_cross(PII a,PII b){//外積(向量a,向量b) 向量={x位移,y位移}
	return a.FIR*b.SEC-a.SEC*b.FIR;
	//兩vector的關係為逆時針旋轉:值>0
	//同向、反向:值=0
	//順時針:值<0
}

INT PII_dot(PII a,PII b){//內積(向量a,向量b) 向量={x位移,y位移}
	return a.FIR*b.FIR+a.SEC*b.SEC;
	//夾角>90:值<0
	//夾角=90:值=0
	//夾角<90:值>0
}
INT PII_cross_p(PII a,PII b,PII c){
	return PII_cross(b-a,c-a);
}
INT PII_dot_p(PII a,PII b,PII c){
	return PII_dot(b-a,c-a);
}
/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	INT n;
	cin>>n;
	while(n--){
		PII a,b,c,d;
		/*CIN*/
		{
			cin>>a.FIR>>a.SEC;
			cin>>b.FIR>>b.SEC;
			cin>>c.FIR>>c.SEC;
			cin>>d.FIR>>d.SEC;
		}
		/*solve*/
		if(a==c || a==d || b==c || b==d){
			//ac共點,ad共點,bc共點,bd共點
			cout<<"Yes"<<endl;
			continue;
		}
		if(PII_cross_p(a,c,d)==0 && PII_dot_p(a,c,b)<0){
			//a在cd上
			cout<<"Yes"<<endl;
			continue;
		}
		if(PII_cross_p(b,c,d)==0 && PII_dot_p(b,c,b)<0){
			//b在cd上
			cout<<"Yes"<<endl;
			continue;
		}
		if(PII_cross_p(a,c,d)==0 && PII_dot_p(a,c,b)<0){
			//c在ab上
			cout<<"Yes"<<endl;
			continue;
		}
		if(PII_cross_p(b,c,d)==0 && PII_dot_p(b,c,b)<0){
			//d在ab上
			cout<<"Yes"<<endl;
			continue;
		}
		if(PII_dot_p(a,c,d)>0){
			cout<<"Yes"<<endl;
			continue;
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

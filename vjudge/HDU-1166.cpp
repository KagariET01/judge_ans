/*
[vjudge]	[Q]https://vjudge.net/problem/HDU-1166
[CE]
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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false

/*struct*/
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
/*fn宣告*/
/*num*/
bool debug=false;
bool iofast=true;
INT nn;
const INT maxn=50000;
INT tree[maxn<<2];
INT item[maxn];
/*fn定義*/


INT build_tree(INT node=0,INT l=0,INT r=nn-1){//將原始資料建立成線段數，原始數據也須保留，以便刪改
	if(l==r){
		tree[node]=item[l];
		return tree[node];
	}else{
		INT mnt=(l+r)/2;
		tree[node]=build_tree(node*2+1,l,mnt)+build_tree(node*2+2,mnt+1,r);
		return tree[node];
	}
}
void tree_numadd(INT ad,INT num,INT l=0,INT r=nn-1,INT node=0){//修改點資料(ad為原始資料的位置,num為修改後的數字)
	if(l<=ad && ad<=r){
		tree[node]-=item[ad];
		tree[node]+=num;
		if(l!=r){
		INT mnt=(l+r)/2;
		
		tree_numadd(ad,num,l,mnt,node*2+1);
		tree_numadd(ad,num,mnt+1,r,node*2+2);
		}
		item[ad]=num;
	}
}
INT tree_find(INT fl,INT fr,INT node=0,INT l=0,INT r=nn-1){
	if(debug){cout<<"fl="<<fl<<",fr="<<fr<<",node="<<node<<",l="<<l<<",r="<<r<<endl;}
	if(fl<=l && r<=fr){return tree[node];}//若目前尋找的範圍(fl,fr)和框的範圍(l,r)相同
	if(fl==fr){return item[fl];}//如果只要找該數值
	else{
		INT mnt=(l+r)/2;
		INT re=0;
		if(fl<=mnt){//mnt左邊
			re+=tree_find(fl,fr,node*2+1,l,mnt);
		}
		if(mnt<fr){//mnt右邊
			re+=tree_find(fl,fr,node*2+2,mnt+1,r);
		}
		return re;
	}
}


/*main*/
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	INT t;
	cin>>t;
	for(INT i=1;i<=t;i++){
		/*CIN*/
		cin>>nn;
		for(INT i=0;i<nn;i++){
			cin>>item[i];
		}
		/*solve*/
		build_tree();
		cout<<"Case "<<t<<":"<<endl;
		string str;
		while(cin>>str){
			if(str=="End")break;
			if(str=="Query"){
				INT l,r;
				cin>>l>>r;
				l--;
				r--;
				cout<<tree_find(l,r)<<endl;
			}
			if(str=="Add"){
				INT a,b;
				cin>>a>>b;
				a--;
				tree_numadd(a,item[a]+b);
			}
			if(str=="Sub"){
				INT a,b;
				cin>>a>>b;
				a--;
				tree_numadd(a,item[a]-b);
			}
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

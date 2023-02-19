/*
[Q]https://vjudge.net/problem/HDU-1754
[WA]
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
#define DBG if(debug)
#define CIN( nn ) DBG{cout<<"input:"<<endl;}cin >> nn ;
#define COUT( nn ) DBG{cout<<"output:{";}cout << nn ; DBG{cout<<"}"<<endl;}
/*struct*/
/*num*/
bool debug=false;
bool iofast=true;
bool couttree=false;
const INT maxn=200001;
INT item[maxn];
INT tree[maxn<<1];
INT n;
INT m;
/*fn*/
INT build_tree(INT node=0,INT l=0,INT r=n-1){
	if(l==r){
		tree[node]=item[l];
		return tree[node];
	}else{
		INT mnt=(l+r)/2;
		tree[node]=max(build_tree(node*2+1,l,mnt),build_tree(node*2+2,mnt+1,r));
		return tree[node];
	}
}
INT tree_numadd(INT ad,INT num,INT l=0,INT r=n-1,INT node=0){
	if(l<=ad && ad<=r){
		if(l==r){
			tree[node]=num;
			return num;
		}
		if(l!=r){
			INT mnt=(l+r)/2;
			
			tree[node]=tree_numadd(ad,num,l,mnt,node*2+1);
			tree[node]=max(tree_numadd(ad,num,mnt+1,r,node*2+2),tree[node]);
		}
		item[ad]=num;
		return tree[node];
	}else{
		return tree[node];
	}
}
INT tree_find(INT fl,INT fr,INT node=0,INT l=0,INT r=n-1){
	if(debug)cout<<"fl="<<fl<<",fr="<<fr<<",node="<<node<<",l="<<l<<",r="<<r<<endl;
	if(fl<=l && r<=fr)return tree[node];
	if(fl==fr)return item[fl];
	else{
		INT mnt=(l+r)/2;
		INT re=0;
		if(fl<=mnt){
			re=max(tree_find(fl,fr,node*2+1,l,mnt),re);
		}
		if(mnt<fr){
			re=max(tree_find(fl,fr,node*2+2,mnt+1,r),re);
		}
		return re;
	}
}
/*main*/
int main(){
	/*IO fast*/
	if(!debug || iofast){what_the_fuck;}
	/*CIN*/
	CIN(n>>m);
	for(INT i=0;i<n;i++){
		CIN(item[i]);
	}
	/*solve*/
	build_tree();
	while(m--){
		char c;
		INT a,b;
		CIN(c>>a>>b);
		if(c=='Q'){
			COUT(tree_find(a-1,b-1)<<endl);
		}else{
			tree_numadd(a-1,b);
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

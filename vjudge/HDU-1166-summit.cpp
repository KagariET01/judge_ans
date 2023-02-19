/*
[vjudge]	[Q]https://vjudge.net/problem/HDU-1166
[TLE]
*/
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
using namespace std;
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define endl "\n"
#define wassomething() empty()==false
#define DBG if(debug)
struct super_pair{
	INT x1=0;
	INT x2=0;
	INT x3=0;
	INT x4=0;
	INT x5=0;
};
bool debug=true;
bool iofast=true;
bool printtree=true;
INT nn;
const INT maxn=50001;
INT tree[maxn<<2];
INT item[maxn];
INT treesize=0;
void couttree(INT n=treesize){
	if(debug || printtree){
		INT mx=1;
		INT nw=1;
		for(INT i=0;i<=n;i++){
			cerr<<tree[i]<<" ";
			if(nw==mx){
				nw=1;
				mx<<=1;
				cerr<<endl;
			}else{
				nw++;
			}
		}
	}
}
INT build_tree(INT node=0,INT l=0,INT r=nn-1){
	if(l==r){
		tree[node]=item[l];
		treesize=max(treesize,node);
		return tree[node];
	}else{
		INT mnt=(l+r)/2;
		tree[node]=build_tree(node*2+1,l,mnt)+build_tree(node*2+2,mnt+1,r);
		return tree[node];
	}
}
void tree_numadd(INT ad,INT num,INT l=0,INT r=nn-1,INT node=0){
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
	if(fl<=l && r<=fr){return tree[node];}
	if(fl==fr){return item[fl];}
	else{
		INT mnt=(l+r)/2;
		INT re=0;
		if(fl<=mnt){
			re+=tree_find(fl,fr,node*2+1,l,mnt);
		}
		if(mnt<fr){
			re+=tree_find(fl,fr,node*2+2,mnt+1,r);
		}
		return re;
	}
}
int main(){
	/*IO加速*/
	if(!debug&&iofast)what_the_fuck;
	INT t;
	cin>>t;
	for(INT i=1;i<=t;i++){
		cin>>nn;
		for(INT i=0;i<nn;i++){
			cin>>item[i];
		}
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
			couttree(treesize);
		}
	}
	return 0;
}


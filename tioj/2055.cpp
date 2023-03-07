/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2055
[AC]
*/


/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
//#include<bits/stdc++.h>
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
#include<cstring>
#include<iomanip>
#include<ctime>
/*using namespace*/
using namespace std;
/*define type*/
#define what_the_fuck cin.tie(0);/*cout.tie(0);*/ios::sync_with_stdio(false)
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
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*num*/
bool debug=0;
bool iofast=true;
PII mv[]={{0,1},{1,0},{0,-1},{-1,0}};
INT mx[]={0,1,0,-1};
INT my[]={1,0,-1,0};
INT mod=988244353;
/*fn定義*/
template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

struct seg_tree{
	vector<INT> vec;
	vector<INT> tre;
	INT sz=0;
	INT insert_p=1;
	INT size(){
		return sz;
	}
	void resize(INT n){
		vec.resize(n+2);
		tre.resize(n*4+4);
		sz=n;
	}
	void clear(){
		vec.clear();
		tre.clear();
		sz=0;
		insert_p=1;
	}
	INT merge(INT a,INT b){
		return min(a,b);
	}
	INT dobuild(INT l,INT r,INT mnt){
		//cerr<<l<<","<<r<<endl;
		if(l==r){
			tre[mnt]=vec[l];
		}else{
			INT cen=l+(r-l)/2;
			//cerr<<l<<","<<cen<<endl;
			INT dl=dobuild(l,cen,mnt<<1);
			INT dr=dobuild(cen+1,r,(mnt<<1)|1);
			tre[mnt]=merge(dl,dr);
		}
		return tre[mnt];
	}
	void build(){
		dobuild(1,sz,1);
	}
	INT doedt(INT edp,INT v,INT l,INT r,INT mnt){
		if(l<=edp && edp<=r){
			if(l==r){
				tre[mnt]=v;
				vec[l]=v;
			}else{
				INT cen=l+(r-l)/2;
				INT dl=doedt(edp,v,l,cen,mnt<<1);
				INT dr=doedt(edp,v,cen+1,r,(mnt<<1)|1);
				tre[mnt]=merge(dl,dr);
			}
		}
		return tre[mnt];
	}
	void edt(INT edp,INT v){
		doedt(edp,v,1,sz,1);
	}
	INT dofind(INT fl,INT fr,INT l,INT r,INT mnt){
		INT re=1e9;
		if(fl<=l && r<=fr)re=tre[mnt];
		else{
			INT al=max(fl,l);
			INT ar=min(fr,r);
			if(al<=ar){
				INT cen=l+(r-l)/2;
				INT dl=dofind(fl,fr,l,cen,mnt<<1);
				INT dr=dofind(fl,fr,cen+1,r,(mnt<<1)|1);
				re=merge(dl,dr);
			}
		}
		//cerr<<fl<<","<<fr<<","<<l<<","<<r<<","<<mnt<<"="<<re<<endl;
		return re;
	}
	INT find(INT fl,INT fr){
		return dofind(fl,fr,1,sz,1);
	}
};





/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	INT n;
	while(cin>>n){
		/*CIN*/
		seg_tree tre;
		tre.resize(n);
		for(INT i=1;i<=n;i++){
			cin>>tre.vec[i];
		}
		/*solve*/
		tre.build();
		for(INT i=0;i<n;i++){
			INT l,r;
			cin>>l>>r;
			cout<<tre.find(l,r)+1<<endl;
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

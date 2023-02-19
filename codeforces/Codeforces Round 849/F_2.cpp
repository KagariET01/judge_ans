/*
[CF]				[Q]https://codeforces.com/contest/1791/problem/F
[懶人標計]
[TLE]
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
#define wassomething() empty()==false
#define REre return re
#define P(n,m) pair<n,m>
#define read(n) reader<n>()
#define set0(n) memset(n,0,sizeof(n))
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;
const INT mxn=2e5;
map<INT,INT> anslist;
INT a[mxn+1];



/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}
INT addall(INT n){
	INT ans=0;
	if(anslist[n]){
		return anslist[n];
	}
	while(n){
		ans+=n%10;
		n/=10;
	}
	anslist[n]=ans;
	return ans;
}

struct landmark{
	vector<INT> vec;
	vector<INT> tre;
	INT sz=0;
	void resize(INT n){
		sz=n;
		vec.clear();
		tre.clear();
		vec.resize(n+1);
		tre.resize(2*n+10);
	}
	bool tch(INT l1,INT r1,INT l2,INT r2){
		INT l=max(l1,l2);
		INT r=min(r1,r2);
		if(l<=r)return true;
		else return false;
	}
	void doinsert(INT adl,INT adr,INT dta,INT l,INT r,INT nw){
		if(adl<=l && r<=adr){
			tre[nw]+=dta;
			return;
		}
		if(tch(adl,adr,l,r)){
			INT mnt=(l+r)/2;
//			//cerr<<"l:"<<l<<",r:"<<r<<",mnt:"<<mnt<<endl;
			doinsert(adl,adr,dta,l,mnt,nw*2+1);
			doinsert(adl,adr,dta,mnt+1,r,nw*2+2);
		}
	}
	void insert(INT adl,INT adr,INT dta){
		doinsert(adl,adr,dta,0,sz,0);
	}
	void movedown(INT nw){
		tre[nw*2+1]+=tre[nw];
		tre[nw*2+2]+=tre[nw];
		tre[nw]=0;
	}
	INT dofind(INT n,bool clear,INT l,INT r,INT nw){
		if(l==r && l==n){
			INT re=tre[nw];
			if(clear)tre[nw]=0;
			//cerr<<"l="<<l<<",r="<<r<<",nw="<<nw;
			//cerr<<",re="<<re<<endl;
			return re;
		}elif(l<=n && n<=r){
			movedown(nw);
			INT mnt=(l+r)/2;
			INT a=dofind(n,clear,l,mnt,nw*2+1);
			INT b=dofind(n,clear,mnt+1,r,nw*2+2);
			INT re=max(a,b);
			//cerr<<"l="<<l<<",r="<<r<<",nw="<<nw;
			//cerr<<",re="<<re<<endl;
			return re;
		}else{
			return 0;
		}
	}
	INT find(INT n,bool clear=false){
		return dofind(n,clear,0,sz,0);
	}
};
landmark landtree;




/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=read(INT);
	while(t--){
		INT n=read(INT),q=read(INT);
		landtree.resize(n);
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		while(q--){
			INT whatdo=read(INT);
			if(whatdo==1){
				INT l=read(INT),r=read(INT);
				landtree.insert(l,r,1);
			}else{
				INT p=read(INT);
				INT dotime=landtree.find(p,true);
				while(dotime--){
					a[p]=addall(a[p]);
				}
				cout<<a[p]<<endl;
			}
		}
	}
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

/*
[seg tree]
[線段樹]
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
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
//#define UINT unsigned INT
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

INT mod=988244353;
/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}


INT adder(INT a,INT b){
	return a+b;
}


struct seg_tree{
	INT sz=0;
	vector<INT> vec;
	vector<INT> tre;
	vector<INT> landtag;
	void init(INT n){//resize
		sz=n;
		vec.clear();
		vec.resize(n+2);
		tre.clear();
		tre.resize(n*4+4);
		landtag.clear();
		landtag.resize(n*4+4);
	}
	void jedit(INT p,INT n){//只是編輯(需要使用build
		vec[p]=n;
	}
	INT merger(INT a,INT b){//運算元素，兩個值要如何進行運算
		return a+b;
	}
	void dobuild(){
		build(0,0,sz);
	}
	INT build(INT nw,INT l,INT r){
		if(l==r){
			tre[nw]=vec[l];
		}else{
			INT mnt=l+(r-l)/2;
			INT a=build(nw*2+1,l,mnt);
			INT b=build(nw*2+2,mnt+1,r);
			tre[nw]=merger(a,b);
		}
		return tre[nw];
	}
	INT overlap(INT al,INT ar,INT bl,INT br){//如果兩區間有重疊處，回傳重疊的長度，若無，則回傳0
		INT l=max(al,bl);
		INT r=min(ar,br);
		if(l<=r){
			return r-l+1;
		}else{
			return -1;
		}
	}
	void copylandtag(INT nw,INT l,INT r){//將自己的懶人標記加到tree，並把懶人標記往子樹傳
		tre[nw]+=landtag[nw]*(r-l+1);
		if(l!=r){
			landtag[nw*2+1]+=landtag[nw];
			landtag[nw*2+2]+=landtag[nw];
		}
		landtag[nw]=0;
	}
	bool eat(INT al,INT ar,INT bl,INT br){//查詢[bl,br]是不是在[al,ar]裡面
		if( (al<=bl &&bl<=ar) && (al<=br && br<=ar) ){
			return true;
		}else return false;
	}
	void doedt(INT p,INT n){
		edt(p,n,0,0,sz);
	}
	void edt(INT p,INT n,INT nw,INT l,INT r){//修改值(免build)
		if(l<=p && p<=r){//如果要修改的值在lr裡面就修改
			tre[nw]-=vec[p];
			tre[nw]+=n;
			INT mnt=l+(r-l)/2;
			edt(p,n,nw*2+1,l,mnt);
			edt(p,n,nw*2+2,mnt+1,r);
			vec[p]=n;
		}else return;//沒有就跳出
	}
	void doloopadd(INT ad,INT addl,INT addr){
		loopadd(ad,addl,addr,0,0,sz);
	}
	void loopadd(INT ad,INT addl,INT addr,INT nw,INT l,INT r){
		INT xx=overlap(addl,addr,l,r);
		if(xx<=-1)return;
		else{
			if(eat(addl,addr,l,r)){
				landtag[nw]+=ad;
				return;
			}
			tre[nw]+=xx*ad;
			INT mnt=l+(r-l)/2;
			if(l!=r){
				loopadd(ad,addl,addr,nw*2+1,l,mnt);
				loopadd(ad,addl,addr,nw*2+2,mnt+1,r);
			}
			vec[l]+=ad;
			vec[r]+=ad;
		}
	}
	
	INT dosearch(INT sl,INT sr){
		return srch(sl,sr,0,0,sz);
	}

	INT srch(INT sl,INT sr,INT nw,INT l,INT r){
		INT xx=overlap(sl,sr,l,r);
		if(xx<=-1)return 0;
		else{
			copylandtag(nw,l,r);
			if(eat(sl,sr,l,r)){//如果現在位置在sl,sr裡面，回傳此值
				return tre[nw];
			}else{
				INT mnt=l+(r-l)/2;
				if(l!=r){
					INT a=srch(sl,sr,nw*2+1,l,mnt);
					INT b=srch(sl,sr,nw*2+2,mnt+1,r);
					return a+b;
				}else{
					return tre[nw];
				}
			}
		}
	}
};






/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=1;
	while(t--){
		INT n,q;
		cin>>n>>q;
		seg_tree atre;
		atre.init(n);
		for(INT i=1;i<=n;i++){
			atre.jedit(i,read(INT));
		}
		atre.dobuild();
		while(q--){
			INT id=read(INT);
			if(id==1){
				INT l,r,d;
				cin>>l>>r>>d;
				atre.doloopadd(d,l,r);
			}else{
				INT l,r;
				cin>>l>>r;
				cout<<atre.dosearch(l,r)<<endl;
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

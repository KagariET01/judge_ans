/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/ [ID]
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid= [ID]
[cses]			[Q]https://cses.fi/problemset/task/ [ID]
[AtCoder]		[Q]https://atcoder.jp/contests/ [ID] /tasks/ [ID] _ [PID]
[CF]				[Q]
[ioic_2023]	[Q]https://judge.ioicamp.org/problems/ [ID]
[]
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
#define Aloop(i,s,n,ad) for(INT i=s;i<n;i+=ad)
#define loop(i,s,n) for(INT i=s;i<n;i++)
#define Dloop(i,s,n) for(i=s;i<n;i++)
#define ADloop(i,s,n,ad) for(i=s;i<n;i+=ad)
/*struct宣告*/
/*fn宣告*/
/*num*/
bool debug=0;
bool iofast=true;


/*struct定義*/
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
		return max(a,b);
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
		tre[nw]+=landtag[nw];
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
			tre[nw]=max(tre[nw],n);
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
			tre[nw]+=ad;
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
					return merger(a,b);
				}else{
					return tre[nw];
				}
			}
		}
	}
};
/*fn定義*/
const INT mxn=1e5;
struct dta{
	INT l=0,r=0,v=0;
};
vector<dta> scaner;
seg_tree tre;
vector<INT> ans;




template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*CIN*/
	INT t=1;
	while(t--){
		INT n,m,q;
		cin>>m>>n>>q;
		scaner.resize(n);
		ans.resize(n,-1);
		loop(i,0,n){
			cin>>scaner[i].l>>scaner[i].r>>scaner[i].v;
		}
		tre.init(m);
		for(INT i=1;i<=q;i++){
			INT l,r,v;
			cin>>l>>r>>v;
			tre.doloopadd(v,l,r);
			for(INT j=0;j<n;j++){
				if(ans[j]>=0)continue;//if it have ans, pass
				if(tre.overlap(l,r,scaner[j].l,scaner[j].r)>0){//if it can find ans at here, find
					INT nwmx=tre.dosearch(scaner[j].l,scaner[j].r);
					if(nwmx>=scaner[j].v){
						ans[j]=i;
					}
				}
			}
		}
		for(INT i:ans){
			cout<<i<<" ";
		}
	}
	
	/*solve*/
	return 0;
}

/*
[I1]
5 4 4

1 3 2
4 4 10
1 5 8
2 3 5

3 5 2
1 4 1
1 2 4
5 5 6
[O1]
*/

/*think*/
/*
[1]
對答案二分搜
[2]
使用線段樹
每一個Q都向線段樹丟資料(log n)
再去枚舉哪個監視器報警了(n log n)

*/

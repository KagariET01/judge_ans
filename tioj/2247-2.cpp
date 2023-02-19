/*
[tioj]			[Q]https://tioj.ck.tp.edu.tw/problems/2247
[zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=h558
[AC]
*/

/*include*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>

/*using namespace*/
using namespace std;

/*define type*/
#define what_the_fuck cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
#define ULLI unsigned long long int
#define char unsigned char
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

map<P(char,char),INT> ptop;
map<P(char,char),bool> pwk;
map<PII,INT> INTptop;
INT ctoi(char c){
	return c-'A';
}

char itoc(INT i){
	return 'A'+i;
}

/*struct定義*/
/*fn定義*/

template<typename TPE>TPE reader(){
	TPE a;
	cin>>a;
	return a;
}

INT mx[]={-1,-1,0 ,0,1 ,1};
INT my[]={0 ,1 ,-1,1,-1,0};


char keyb[3][10]={
	{'Q','W','E','R','T','Y','U','I','O','P'},
	{'A','S','D','F','G','H','J','K','L',' '},
	{'Z','X','C','V','B','N','M',' ',' ',' '}
};

struct bfsdta{
	INT nwx=-1;
	INT nwy=-1;
	char st=' ';
	INT nwnn=0;
};
bfsdta mk(INT x,INT y){
	bfsdta re;
	re.nwx=x;
	re.nwy=y;
	re.st=keyb[x][y];
	re.nwnn=0;
	return re;
}

deque<bfsdta> dq;

void bfs(INT nwx,INT nwy,char st=' ',INT nwnn=0){//st=剛開始時的字母,nwx,nwy=現在位在的座標,nwnn=st到這裡的距離
	if(0<=nwx && nwx<3 && 0<=nwy && nwy<10){
		if(st==' ')st=keyb[nwx][nwy];
		if(!pwk[{keyb[nwx][nwy],st}]){
			pwk[{st,keyb[nwx][nwy]}]=pwk[{keyb[nwx][nwy],st}]=true;
			ptop[{st,keyb[nwx][nwy]}]=ptop[{keyb[nwx][nwy],st}]=nwnn;
			INTptop[{ctoi(st),ctoi(keyb[nwx][nwy])}]=INTptop[{ctoi(keyb[nwx][nwy]),ctoi(st)}]=nwnn;
			for(INT i=0;i<6;i++){
				bfsdta nx;
				nx.nwx=nwx+mx[i];
				nx.nwy=nwy+my[i];
				nx.st=st;
				nx.nwnn=nwnn+1;
				if(0<=nx.nwx && nx.nwx<3 && 0<=nx.nwy && nx.nwy<10)
				dq.push_back(nx);
			}
			return;
		}else{
			return;
		}
	}
}


/*main*/
int main(){
	if(!debug&&iofast){what_the_fuck;}
	srand(time(NULL));
	/*sheet*/
	for(INT i=0;i<3;i++){
		for(INT j=0;j<10;j++){
			dq.push_back(mk(i,j));
		}
	}
	pwk.clear();
	while(dq.wassomething()){
		bfsdta nw=dq.front();
		dq.pop_front();
		bfs(nw.nwx,nw.nwy,nw.st,nw.nwnn);
	}
	/*for(char c='A';c<='Z';c++){
		for(char ci=c;ci<='Z';ci++){
			cout<<c<<">"<<ci<<":"<<ptop[{c,ci}]<<endl;
		}
	}*/
	/*main*/
	INT n=read(INT);
	string s=read(string);
	INT txt[n+2];
	for(INT i=0;i<n;i++){
		txt[i]=ctoi(s[i]);
	}
	INT dp[n+1][30][30];//n為目前的位置,後兩者為食指目前的位置，n從1開始，其他從0開始
	memset(dp,1e9+10,sizeof(dp));
	dp[0][ctoi('F')][ctoi('J')]=0;
	INT ans=1e9;
	for(INT i=0;i<=n;i++){
		INT nt=-1;
		if(i<n)nt=txt[i];
		for(INT l=0;l<=ctoi('Z');l++){
			for(INT r=0;r<=ctoi('Z');r++){
				if(i==n){
					ans=min(ans,dp[i][l][r]);
				}else{
					INT mladd=INTptop[{l,nt}];
					INT mradd=INTptop[{r,nt}];
					INT &dpnw=dp[i][l][r];
					INT &dpl=dp[i+1][nt][r];
					INT &dpr=dp[i+1][l][nt];
					dpl=min(dpl,dpnw+mladd);
					dpr=min(dpr,dpnw+mradd);/*
					if(dp[i][l][r]<(INT)1e8){
						cerr<<i<<","<<itoc(l)<<","<<itoc(r)<<":"<<dp[i][l][r]<<endl;
						cerr<<itoc(l)<<" to "<<itoc(nt)<<":"<<mladd<<endl;
						cerr<<itoc(r)<<" to "<<itoc(nt)<<":"<<mradd<<endl;
						cerr<<endl;
					}*/
				}
			}
		}
	}
	//cerr<<"tst"<<endl;
	cout<<ans<<endl;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/
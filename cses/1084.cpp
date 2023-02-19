/*
[Q]https://cses.fi/problemset/task/1084
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ulli long long int
using namespace std;
bool asmallb(ulli a,ulli b){
	return a<b;
}
int main(){
	ulli n,m,k;
	cin>>n>>m>>k;
	ulli app[n],apart[m];
	for(ulli i=0;i<n;i++){
		cin>>app[i];
	}
	for(ulli i=0;i<m;i++){
		cin>>apart[i];
	}
	sort(app,app+n,asmallb);
	sort(apart,apart+m,asmallb);
	ulli i=0,j=0,ans=0;
	while(i<n && j<m){
		ulli nowapp=app[i],nowapart=apart[j];
		if(nowapp-k<=nowapart&&nowapart<=nowapp+k){
			ans++;
			i++;
			j++;
			continue;
		}
		if(nowapp-k>nowapart){
			j++;
			continue;
		}
		if(nowapp+k<nowapart){
			i++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
4 3 5
60 45 80 60
30 60 75
[O1]
2
*/
/*
[think]
45 60 60 80
30 60 75
*/
/*
[summit]
[I3]
10 10 1000
59 5 65 15 42 81 58 96 50 1
18 59 71 65 97 83 80 68 92 67
[O3]
10
*/
/*
[Q]https://cses.fi/problemset/task/1620
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ulli unsigned long long int
using namespace std;
int main(){
	ulli n,t;
	cin>>n>>t;
	ulli k[n],maxk=0,mink=0;
	for(ulli i=0;i<n;i++){
		cin>>k[i];
		maxk=max(maxk,k[i]);
		if(mink){
			mink=min(mink,k[i]);
		}else{
			mink=k[i];
		}
	}
	if(t==1){
		cout<<mink;
		return 0;
	}
	vector<ulli> anslist(maxk*t/n+2,0);
	ulli ans=0,ansmin=mink*t/n-1,ansmax=maxk*t/n+1;
	while(true){
		if(ansmax-ansmin==1){
			ans=ansmax;
		}else{
			ans=(ansmax+ansmin)/2;
		}
		ulli make=0;
	    ulli canmin=0;
		for(ulli i=0;i<n;i++){
			make+=ans/k[i];
			if(i){
				canmin=min(ans%k[i],canmin);
			}else{
				canmin=ans%k[i];
			}
		}
		if(make>t){
			ansmax=ans;
		}
		if(make<t){
			ansmin=ans;
		}if(make>=t && anslist[ans-1]<t && anslist[ans-1]!=0){
			ans-=canmin;
			break;
		}
		anslist[ans]=make;
	}
	cout<<ans;
	return 0;
}
/*
[I1]
3 7
3 2 5
[O1]
8
*/
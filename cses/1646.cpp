#include<iostream>
using namespace std;
#define ulli unsigned long long int
int main(){
	int n,m;
	cin>>n>>m;
	ulli numttlist[n+1];
	numttlist[0]=0;
	for(int i=1;i<=n;i++){
		ulli nn;
		cin>>nn;
		numttlist[i]=numttlist[i-1]+nn;
	}
	while(m--){
		ulli a,b;
		cin>>a>>b;
		cout<<numttlist[b]-numttlist[a-1]<<"\n";
	}
	return 0;
}

/*
[I1]
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
*/

/*
1,12,123
*/
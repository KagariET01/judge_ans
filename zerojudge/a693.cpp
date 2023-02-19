#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m){
		int food[n+1];
		food[0]=0;
		int x;
		for(int i=1;i<=n;i++){
			cin>>x;
			food[i]=food[i-1]+x;
		}
		for(int i=0;i<m;i++){
			int l,r;
			cin>>l>>r;
			cout<<food[r]-food[l-1]<<"\n";
		}
	}
	return 0;
}
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int ans=0;
	for(int i=5;;i*=5){
		int add=n/i;
		if(add>0){ans+=add;}
		else{break;}
	}
	cout<<ans;
	return 0;
}
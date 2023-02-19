#include<iostream>
#include<cmath>
using namespace std;
void solve(int n,int a=1,int b=2,int c=3){
	if(n){
		solve(n-1,a,c,b);
		cout<<a<<" "<<c<<"\n";
		solve(n-1,b,a,c);
	}
}
int main(){
	int n;
	cin>>n;
	cout<<pow(2,n)-1<<"\n";
	solve(n=n);
	return 0;
}
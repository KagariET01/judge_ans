#include<iostream>
#include<cmath>
using namespace std;
int tcount=0;
int fcount=0;
int tfinder(int n){
	if(n%2){
		return 0;
	}else{
		return 1+tfinder(n>>1);
	}
}
int ffinder(int n){
	if(n%5){
		return 0;
	}else{
		return 1+ffinder(n/5);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		tcount+=tfinder(i);
		fcount+=ffinder(i);
	}
	cout<<min(tcount,fcount);
	return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
unsigned long long int intpow(unsigned long long int a,unsigned long long int b){
	if(b){
		int x=(a*intpow(a,b-1));
		int y=x/1000000000;
		y*=1000000000;
		if(y){return x-y-7;}
		return x-y;
	}else{
		return 1;
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(b){
			cout<<(intpow(a,b))<<"\n";
		}else{
			cout<<"1\n";
		}
	}
	return 0;
}
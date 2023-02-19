#include<iostream>
#include<cmath>
using namespace std;
long long int intpow(long long int a,long long int b){
	if(b){
		return a*intpow(a,b-1);
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
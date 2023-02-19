#include<iostream>
#include<cmath>
using namespace std;
long long int intpow(long long int a,long long int b){
	
	long long int ans=1;
	for(int i=0;i<b;i++){
		ans*=a;
	}
	return ans;
	
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(b>0){
			cout<<(intpow(a,b))<<"\n";
		}else{
			cout<<"1\n";
		}
	}
	return 0;
}
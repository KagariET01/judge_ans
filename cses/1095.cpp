#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(b){
			cout<<unsigned long long int(pow(a,b))<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}
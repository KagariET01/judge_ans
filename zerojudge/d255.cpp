#include<iostream>
#include<cmath>
using namespace std;
int gcd(int i,int j){
	if(i<j){
		return gcd(j,i);
	}else{
		if(j==0){
			return i;
		}else{
			return gcd(j,i%j);
		}
	}
}

int main(){
	int n;
	while(true){
		cin>>n;
		if(n!=0){
			int g=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					g+=gcd(i,j);
				}
			}
			cout<<g<<"\n";
		}else{break;}
	}
	return 0;
}
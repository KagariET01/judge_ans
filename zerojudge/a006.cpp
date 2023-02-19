#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int b24ac;
	b24ac=int(pow(b,2))-4*a*c;
	if(b24ac>0){
		double xa,xb;
		xa=(-b+sqrt(b24ac))/(2*a);
		xb=(-b-sqrt(b24ac))/(2*a);
		cout<<"Two different roots x1="<<xa<<" , x2="<<xb;
	}else if(b24ac==0){
		int xa;
		xa=(-b)/(2*a);
		cout<<"Two same roots x="<<xa;
	}else{
		cout<<"No real root";
	}
	return 0;
}
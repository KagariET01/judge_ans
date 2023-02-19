#include<iostream>
using namespace std;
int f91list[100];
int f91(int n){
	if(n<=100){
		if(not(f91list[n])){
			f91list[n]=f91(f91(n+11));
		}
		return f91list[n];
	}else if(n>=101){
		return n-10;
	}
}
int main(){
	for(int i=0;i<100;i++){
		f91list[i]=0;
	}
	while(true){
		int a;
		cin>>a;
		if(a){
			cout<<"f91("<<a<<") = "<<f91(a)<<"\n";
		}else{
			break;
		}
	}
}
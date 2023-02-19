#include<iostream>
#include<cmath>
using namespace std;
int p[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int solve(int now,int max,int a=0,int b=0,int c=0){
	if(now==max){
		if(a==b && b==c){
			return 1;
		}else{
			return 0;
		}
	}else{
		int an=solve(now+1,max,a+p[now],b,c);
		if(an){
			return an;
		}
		int bn=solve(now+1,max,a,b+p[now],c);
		if(bn){
			return bn;
		}
		int cn=solve(now+1,max,a,b,c+p[now]);
		if(cn){
			return cn;
		}else{
			return 0;
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	int can=solve(0,n);
	if(can){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}
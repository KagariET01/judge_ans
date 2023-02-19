#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int n,m;
		cin>>n>>m;
		n-=2;
		m-=2;
		int w,h;
		w=n/3;
		h=m/3;
		if(n%3){w++;}
		if(m%3){h++;}
		cout<<w*h<<"\n";
	}
}
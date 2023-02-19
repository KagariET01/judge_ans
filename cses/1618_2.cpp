#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int tcount=0;
int fcount=0;
map<int,int> tans;
map<int,int> fans;
int ffinder(int n){
	int a=0;
	while(n%5==0){
		n/=5;
		a++;
	}
	return a;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	tans[0]=tans[1]=0;
	fans[0]=fans[1]=fans[2]=fans[3]=fans[4]=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		//tcount+=tfinder(i);
		fcount+=ffinder(i);
	}
	cout<<fcount;
	return 0;
}
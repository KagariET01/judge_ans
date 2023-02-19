#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int a;
	string b;
	cin>>a;
	cin>>b;
	int num=0;
	int lovenum=0;
	for(int i=0;i<b.size();i++){
		int n;
		n=b.size()-i-1;
		num+=int(pow(a,n)*(int(b[i])-int('0')));
		lovenum+=int(pow((int(b[i])-int('0')),b.size()));
	}
	if(num-lovenum){cout<<"NO";}
	else{cout<<"YES";}
	return 0;
}
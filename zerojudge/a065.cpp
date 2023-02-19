#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	string a;
	cin>>a;
	for(int i=0;i<6;i++){
		cout<<max(a[i],a[i+1])-min(a[i],a[i+1]);
	}
	return 0;
}
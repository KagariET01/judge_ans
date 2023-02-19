#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	while(cin>>a){
		cin>>b;
		int k;
		k=int(b[0]-a[0]);
		k+=26;
		k%=26;
		cout<<k<<"\n";
	}
	return 0;
}
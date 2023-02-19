#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a,f;
		cin>>a;
		cin>>f;
		for(int j=0;j<f;j++){
			for(int k=1;k<=a;k++){
				for(int l=0;l<k;l++){
					cout<<k;
				}
				cout<<"\n";
			}
			for(int k=a-1;k>=1;k--){
				for(int l=0;l<k;l++){
					cout<<k;
				}
				cout<<"\n";
			}
			cout<<"\n";
		}
	}
}
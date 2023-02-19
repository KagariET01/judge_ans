#include<iostream>
#include<string>
using namespace std;
int f(string n){
	if(n.size()==1){
		return stoi(n);
	}else{
		int ntt=0;
		for(int i=0;i<n.size();i++){
			ntt+=int(n[i])-int('0');
		}
		return f(to_string(ntt));
	}
}
int main(){
	while(true){
		int a;
		cin>>a;
		if(a){
			cout<<f(to_string(a))<<"\n";
		}else{
			break;
		}
	}
}
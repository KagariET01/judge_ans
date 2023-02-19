#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	while(true){
		string a;
		cin>>a;
		if(a=="0"){break;}
		int tt=0;
		for(int i=0;i<a.length();i++){
			if(i%2){tt+=(int(a[i])-int('0'));}
			else{tt-=(int(a[i])-int('0'));}
		}
		if(tt%11==0){cout<<a<<" is a multiple of 11.\n";}
		else{cout<<a<<" is not a multiple of 11.\n";}
	}
	return 0;
}
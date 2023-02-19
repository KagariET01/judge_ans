#include<iostream>
#include<string>
using namespace std;
int self_numbers[1000010];
int del(int n){
	int newn=n;
	string strn=to_string(n);
	for(int i=0;i<strn.size();i++){
		newn+=int(strn[i])-int('0');
	}
	if(newn<=1000010){
		self_numbers[newn]=0;
	}
	return 0;
}
int main(){
	for(int i=0;i<1000010;i++){
		self_numbers[i]=1;
	}
	for(int i=1;i<=1000000;i++){
		if(self_numbers[i]){
			cout<<i<<"\n";
			del(i);
		}else{
			del(i);
		}
	}
	return 0;
}
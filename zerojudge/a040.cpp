#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int fir,las;
	cin>>fir;
	cin>>las;
	int was_do=0;
	for(int i=fir;i<=las;i++){
		string num=to_string(i);
		int num_len=num.length();
		int total=0;
		for(int j=0;j<num_len;j++){
			total+=int(pow(int(num[j])-int('0'),num_len));
		}
		if(not(total-i)){
			if(was_do){
				cout<<" ";
			}
			cout<<i;
			was_do=1;
		}
	}
	if(not(was_do)){
		cout<<"none";
	}
	return 0;
}
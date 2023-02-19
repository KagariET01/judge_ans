#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int cou=0,lef=0,rig=0;
		for(int i=0;i<str.size();i++){
			switch(str[i]){
				case '(':
					cou++;
					lef++;
					break;
				
				case ')':
					rig++;
					break;
				
			}
			if(lef<rig){
				cou=0;
				break;
			}
		}
		if(lef!=rig){
			cou=0;
		}
		if(true){
			cout<<cou<<"\n";
		}
	}
	return 0;
}
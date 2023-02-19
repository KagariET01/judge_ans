#include<iostream>
#include<string>
using namespace std;
int main(){
	int a;
	cin>>a;
	string z;
	getline(cin,z);
	while(a--){
		string str;
		getline(cin,str);
		int textlist[30];
		for(int i=0;i<30;i++){
			textlist[i]=0;
		}
		for(int i=0;i<str.size();i++){
			int nowt=int(str[i]);
			if(nowt>=int('a') && nowt<=int('z')){
				textlist[nowt-int('a')]+=1;
			}
			else if(nowt>=int('A') && nowt<=int('Z')){
				textlist[nowt-int('A')]+=1;
			}
		}
		int uma=0;
		for(int i=0;i<30;i++){
			if((textlist[i])>uma){
				uma=textlist[i];
			}
		}
		for(int i=0;i<30;i++){
			if(textlist[i]>=uma){
				cout<<char(i+int('a'));
			}
		}
		cout<<"\n";
	}
	return 0;
}
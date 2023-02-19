#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//sqrt
int main(){
	int a;
	cin>>a;
	string b;
	getline(cin,b);
	while(a--){
		string s;
		getline(cin,s);
		int l=int(sqrt(s.size()));
		if(l*l==s.size()){
			char tlist[l][l];
			for(int i=0;i<l;i++){
				for(int j=0;j<l;j++){
					tlist[i][j]=s[i*l+j];
				}
			}
			for(int i=0;i<l;i++){
				for(int j=0;j<l;j++){
					cout<<tlist[j][i];
				}
			}
			cout<<"\n";
		}else{
			cout<<"INVALID\n";
		}
	}
	return 0;
}
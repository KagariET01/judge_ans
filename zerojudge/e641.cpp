#include<iostream>
#include<map>

using namespace std;
int main(){
	map<char,int> soundexnum;
	string s[]={"AEIOUHWY","BFPV","CGJKQSXZ","DT","L","MN","R"};
	for(int i=0;i<7;i++){
		for(int j=0;j<(s[i]).size();j++){
			soundexnum[s[i][j]]=i;
		}
	}
	string inputtext;
	int last;
	while(cin>>inputtext){
		for(int i=0;i<inputtext.size();i++){
			if(soundexnum[inputtext[i]] && soundexnum[inputtext[i]]-last){
				cout<<soundexnum[inputtext[i]];
			}
			last=soundexnum[inputtext[i]];
		}
		cout<<"\n";
	}
	
	
	
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main(){
	int a;
	cin>>a;
	string gg;
	getline(cin,gg);
	while(a--){
		string f,s,aaa;
		getline(cin,aaa);
		getline(cin,f);
		getline(cin,s);
		stringstream fs(f);
		vector<int> f_list;
		while(fs >> f){
			f_list.push_back(stoi(f));
		}
		stringstream ss(s);
		vector<string> s_list;
		while(ss >> s){
			s_list.push_back(s);
		}
		for(int i=1;i<=f_list.size();i++){
			for(int j=0;j<f_list.size();j++){
				if(f_list[j]==i){
					cout<<s_list[j]<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}
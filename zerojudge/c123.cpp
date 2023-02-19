#include<stack>
#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
int main(){
	int a;
	string a_s;
	while(true){
		getline(cin,a_s);
		a=stoi(a_s);
		if(a==0){break;}
		string b;
		while(true){
			getline(cin,b);
			if(b=="0"){break;}
			queue<int>final_trank;
			stack<int> station;
			stringstream tra(b);
			int train_count=0;
			while(tra>>b){
				final_trank.push(stoi(b));
				train_count++;
			}
			for(int i=1;i<=train_count;i++){
				station.push(i);
				while(station.size()>0){
					if(station.top()==final_trank.front()){
						station.pop();
						final_trank.pop();
					}else{
						break;
					}
				}
			}
			if(station.size()>0){
				cout<<"No\n";
			}else{
				cout<<"Yes\n";
			}
		}
		cout<<"\n";
	}
	
	
	return 0;
}
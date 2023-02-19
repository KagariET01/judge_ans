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
		stack<char> sta;
		int cou=0,can=1;
		for(int i=0;i<str.size() && can;i++){
			switch(str[i]){
				case '(':
					cou++;
					can++;
					sta.push(str[i]);
					break;
				case '[':
					cou++;
					can++;
					sta.push(str[i]);
					break;
				case '{':
					cou++;
					can++;
					sta.push(str[i]);
					break;
				case '<':
					cou++;
					can++;
					sta.push(str[i]);
					break;
				
				case ')':
					if(sta.top()=='('){
						sta.pop();
						can--;
					}else{
						can=0;
					}
					break;
				case ']':
					if(sta.top()=='['){
						sta.pop();
						can--;
					}else{
						can=0;
					}
					break;
				
				case '}':
					if(sta.top()=='{'){
						sta.pop();
						can--;
					}else{
						can=0;
					}
					break;
				
				case '>':
					if(sta.top()=='<'){
						sta.pop();
						can--;
					}else{
						can=0;
					}
					break;
				
				
			}
		}
		if(can==1){
			cout<<cou<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool a(char a,char b,int c, int d){
	return a<b;
}
int main(){
	string str;
	cin>>str;
	sort(all(str));
	vector<string> v;
	do{
		v.push(str);
	}while(next_permutation(all(str)));
	cout<<v.size<<"\n";
	for(string y:v){
		cout<<y<<"\n";
	}
	return 0;
}
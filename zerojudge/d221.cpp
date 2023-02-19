#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	int n;
	while(true){
		cin>>n;
		if(!n){break;}
		priority_queue<unsigned long long int,vector<unsigned long long int>,greater<unsigned long long int>> vec;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			vec.push(a);
		}
		unsigned long long int prize=0;
		for(int i=1;i<n;i++){
			unsigned long long int x,y;
			x=vec.top();
			vec.pop();
			y=vec.top();
			vec.pop();
			vec.push(x+y);
			prize+=(x+y);
		}
		cout<<prize<<"\n";
	}
	return 0;
}
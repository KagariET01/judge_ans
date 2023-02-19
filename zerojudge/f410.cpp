#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int a;
	cin>>a;
	int slist[a];
	priority_queue<int,vector<int>,greater<int>>duoq;
	priority_queue<int,vector<int>,less<int>>suoq;
	for(int i=0;i<a;i++){
		int b;
		cin>>b;
		if(b%2){
			suoq.push(b);
		}else{
			duoq.push(b);
		}
	}
	while(!duoq.empty()){
		cout<<duoq.top()<<" ";
		duoq.pop();
	}
	while(!suoq.empty()){
		cout<<suoq.top()<<" ";
		suoq.pop();
	}
	return 0;
}

/*
[I1]
5
1 2 3 4 5
[O1]
2 4 5 3 1
[I2]
4
5 46 83 119
[O2]
46 119 83 5
*/
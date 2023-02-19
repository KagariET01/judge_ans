#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct treedata{
	int x;
	int y;
	int h;
};
struct treevs{
	bool operator()(treedata a,treedata b){
		return a.x*a.y>=b.x*b.y;
	}
};
int main(){
	int n;
	cin>>n;
	priority_queue<treedata,vector<treedata>,treevs>treelist;
	for(int i=0;i<n;i++){
		treedata now;
		cin>>now.x>>now.y>>now.h;
		treelist.push(now);
		
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		int now=(treelist.top()).h;
		treelist.pop();
		int next=(treelist.top()).h;
		ans=max(ans,now-next);
	}
	cout<<ans;
	return 0;
}
/*
[I1]
5
3000 1000 50
8000 7000 100
0 0 100
3000 5000 300
10000 10000 150
[O1]
200
*/
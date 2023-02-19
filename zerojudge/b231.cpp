#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;



int main(){
	int n;
	while(cin>>n){
		int allprinttime=0,ans=0;
		priority_queue<pair<int,int>> worklist;
		for(int i=0;i<n;i++){
			int pt,mt;
			cin>>pt>>mt;
			worklist.push(make_pair(mt,pt));
		}
		//sudo apt install books
		for(int i=0;i<n;i++){
			int nowprint=worklist.top().second;
			int nowinstall=worklist.top().first;
			allprinttime+=nowprint;
			ans=max(ans,allprinttime+nowinstall);
			worklist.pop();
		}
		cout<<ans<<"\n\n";
	}
	
	return 0;
}
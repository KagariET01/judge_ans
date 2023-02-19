/*
[Q]https://cses.fi/problemset/task/1645
[AC]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<stack>
#include<deque>
using namespace std;
#define ulli unsigned long long int
#define lli long long ulli
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	ulli n,x;
	cin>>n;
	deque< pair<ulli,ulli> > vec;
	for(int i=0;i<n;i++){
		cin>>x;
		ulli ans=0;
		if(vec.size()){
			deque< pair<ulli,ulli> >::iterator it;
			it=vec.end();
			ulli runcount=vec.size();
			while(runcount--){
				it--;
				if((*it).first<x){
					ans=(*it).second+1;
					break;
				}
			}
		}
		cout<<ans<<' ';
		while(vec.size()&&(vec.back()).first>=x){
			vec.pop_back();
		}
		vec.push_back({x,i});
	}
	return 0;
}
/*
[I1]
8
2 5 1 4 8 3 2 5
[O1]
0 1 0 3 4 3 3 7
*/

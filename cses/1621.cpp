/*
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	set<ulli> se;
	for(int i=0;i<n;i++){
		ulli x;
		cin>>x;
		se.insert(x);
	}
	cout<<se.size();
	return 0;
}
/*
*/
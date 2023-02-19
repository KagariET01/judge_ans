#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
	string str;
	cin>>str;
	sort(str.begin(),str.end());
	vector<string> ans;
	do{
		ans.push_back(str);
	}while(next_permutation(str.begin(),str.end()));
	cout<<ans.size()<<"\n";
	for(int i=0;i<(ans.size());i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
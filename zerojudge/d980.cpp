#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		priority_queue<long long int> llist;
		long long int in;
		for(int j=0;j<3;j++){
			cin>>in;
			llist.push(in);
		}
		string ans="Scalene";
		long long int l_list_list[3];
		for(int j=0;j<3;j++){
			l_list_list[2-j]=(llist.top());
			if(l_list_list[2-j]<=0){
				ans="Invalid";
			}
			llist.pop();
		}
		{//Invalid
			if(l_list_list[0]+l_list_list[1]<=l_list_list[2] || l_list_list[0]<=0){
				ans="Invalid";
			}
		}
		if(ans=="Scalene"){//
			if(l_list_list[0]==l_list_list[1] || l_list_list[1]==l_list_list[2]){
				ans="Isosceles";
			}
			if(l_list_list[0]==l_list_list[1] && l_list_list[1]==l_list_list[2]){
				ans="Equilateral";
			}
		}
		cout<<"Case "<<i<<": "<<ans<<"\n";
	}
	
	return 0;
}

/*
[sample input]
4
1 2 5
1 1 1
4 4 2
3 4 5
[sample output]
Case 1: Invalid
Case 2: Equilateral
Case 3: Isosceles
Case 4: Scalene
*/
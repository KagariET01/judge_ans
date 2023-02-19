#include<iostream>
#include<algorithm>
using namespace std;
bool chooser(int a,int b){
	string a_str,b_str;
	a_str=to_string(a);
	b_str=to_string(b);
	if(a_str[a_str.size()-1]!=b_str[b_str.size()-1]){
		return a_str[a_str.size()-1]<b_str[b_str.size()-1];
	}else{
		return a>b;
	}
}
int main(){
	int a;
	while(cin>>a){
		int aalist[a];
		for(int i=0;i<a;i++){
			cin>>aalist[i];
		}
		sort(aalist,aalist+a,chooser);
		for(int i=0;i<a;i++){
			cout<<aalist[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

/*
[sample input 1]
7
38 106 98 26 13 46 51
6
1 2 3 4 5 0
5
98 76 12 34 55
6
33 33 88 88 83 38
[sample output 1]
51 13 106 46 26 98 38
0 1 2 3 4 5
12 34 55 76 98
83 33 33 88 88 38
*/
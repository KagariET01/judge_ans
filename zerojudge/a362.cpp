#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct item{
	int hi=0;
	int wi=0;
	int idn=0;
};
bool chooser(item a,item b){
	if(a.hi!=b.hi){
		return a.hi<b.hi;
	}else if(a.wi!=b.wi){
		return a.wi<b.wi;
	}else{
		return a.idn<b.idn;
	}
}
int main(){
	int n;
	while(cin>>n){
		vector<item> original;
		vector<item> after;
		for(int i=0;i<n;i++){
			item now;
			cin>>now.hi>>now.wi;
			now.idn=i;
			original.push_back(now);
			after.push_back(now);
		}
		sort(&(after[0]),&(after[n]),chooser);
		int ans=0;
		for(int i=0;i<n;i++){
			//cout<<"after[i].idn="<<(after[i]).idn<<"\n";//debug
			ans+=abs(i-(after[i]).idn);
		}
		cout<<ans<<"\n";
	}
	return 0;
}


/*
[I1]
5
5 20
10 25
78 40
25 25
5 15
[O1]
8
[I2]
8
5 15
3 5
9 13
13 20
24 30
40 50
9 12
5 15
[O2]
18
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	long long int a,tt=0;
	vector<long long int> ttlist;
	ttlist.push_back(0);
	while(cin>>a){
		a=abs(a);
		tt=0;
		long long int i=0;
		while(tt<a || (tt-a)%2==1){
			i++;
			if(ttlist.size()<i){
				tt=ttlist[i];
				//cout<<"up,tt="<<tt<<",i="<<i<<",tt+i="<<tt+i<<"\n";//debug
			}
			else{
				tt=ttlist[i-1]+i;
				if(ttlist.size()==i){
					ttlist.push_back(tt);
				}
				//cout<<"down,tt="<<tt<<",i="<<i<<",tt+i="<<tt+i<<"\n";//debug
			}
		}
		cout<<i<<"\n";
		a=0;
	}
	return 0;
}

#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string weblist;
		int viewlist;
		int vmax=0,maxcount=0;;
		string wmax[10];
		for(int j=0;j<10;j++){
			cin>>weblist>>viewlist;
			if(viewlist>vmax){
				vmax=viewlist;
				maxcount=1;
				wmax[0]=weblist;
			}else if(viewlist==vmax){
				wmax[maxcount]=weblist;
				maxcount+=1;
			}
		}
		cout<<"Case #"<<i+1<<":\n";
		for(int j=0;j<maxcount;j++){
			cout<<wmax[j]<<"\n";
		}
	}
	return 0;
}
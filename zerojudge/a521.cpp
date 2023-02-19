#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int flist[x];
		for(int i=0;i<4;i++){
			cin>>flist[i];
		}
		for(int i=4;i<x;i++){
			flist[i]=flist[i-4]+flist[i-1];
		}
		nth_element(flist,flist+(x/2),flist+x);
		cout<<flist[x/2]<<"\n";
	}
	return 0;
}
/*
[I1]
2
5 3 2 4 1
7 3 2 4 1
[O1]
3
4
*/
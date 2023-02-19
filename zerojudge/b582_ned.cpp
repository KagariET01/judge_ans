#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool stb(int a,int b){
	return a<b;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin>>a;
	while(a--){
		int b;
		cin>>b;
		int xlist[b];
		int ylist[b];
		for(int i=0;i<b*2;i++){
			cin>>xlist[i];
			cin>>ylist[i];
		}
		nth_element(xlist,xlist+(b/2),xlist+b);
		nth_element(ylist,ylist+(b/2),ylist+b);
		
		unsigned long long int sum=0;
		for(int i=0;i<b;i++){
			sum+=abs(xlist[i]-xlist[b/2]);
			sum+=abs(ylist[i]-ylist[b/2]);
			cout<<"xlist[i]="<<xlist[i]<<"ylist[i]"<<ylist[i]<<"\n";
		}
		cout<<sum<<"\n";
	}
	return 0;
}


/*
[I1]
2
1
0 0
4
1 0 0 1 -1 0 0 -1
[O1]
0
4
*/
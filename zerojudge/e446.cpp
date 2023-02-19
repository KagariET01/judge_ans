#include<iostream>
using namespace std;
int hlist[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int printlist[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int out(int maxn){
	maxn--;
	for(int i=maxn;i>=2;i--){
		cout<<printlist[i]<<" ";
	}
	cout<<printlist[1]<<"\n";
	return 0;
}
int ss(int run,int maxn){
	if(run==1){
		for(int i=1;i<maxn;i++){
			if(not(hlist[i])){
				printlist[run]=i;
				out(maxn);
				break;
			}
		}
	}else{
		for(int i=1;i<maxn;i++){
			if(not(hlist[i])){
				printlist[run]=i;
				hlist[i]=1;
				ss(run-1,maxn);
				hlist[i]=0;
			}
		}
	}
	return 0;
}
int main(){
	int a;
	cin>>a;
	ss(a,a+1);
	return 0;
}
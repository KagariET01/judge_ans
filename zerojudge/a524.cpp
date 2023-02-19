#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int alist[n+1];
		for(int i=1;i<=n;i++){
			alist[i-1]=i;
		}
		do{
			for(int i=0;i<n;i++){
				cout<<n-alist[i]+1;
			}
			cout<<"\n";
		}while(next_permutation(alist,alist+n));
	}
	return 0;
}
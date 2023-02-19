/*
[Q]https://cses.fi/problemset/task/1624
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
int main(){
	char a[9][9];
	for(int i=0;i<8;i++){
		cin>>a[i];
	}
	int queenlist[8];
	for(int i=0;i<8;i++){
		queenlist[i]=i;
	}
	ulli ans=0;
	do{
		bool can=true;
		for(int i=0;i<8;i++){
			if(a[i][queenlist[i]]=='*'){
				can=false;
				break;
			}
			for(int j=0;j<8;j++){
				if(i==j){
					continue;
				}
				int ij=abs(i-j);
				if(queenlist[j]-ij==queenlist[i] || queenlist[j]+ij==queenlist[i]){
					can=false;
				}
			}
		}
		if(can){
			ans++;
		}
	}while(next_permutation(queenlist,queenlist+8));
	cout<<ans;
	return 0;
}
/*
[I1]
........
........
..*.....
........
........
.....**.
...*....
........
[O1]
65
*/
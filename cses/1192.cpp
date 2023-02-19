/*
[Q]https://cses.fi/problemset/task/1192
[AC]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
int maplist[1001][1001];
int n,m;
void solver(int x,int y){
	maplist[x][y]=0;
	/*UP*/
	if(y){
		if(maplist[x][y-1])solver(x,y-1);
	}
	/*DOWN*/
	if(y-(m-1)){
		if(maplist[x][y+1])solver(x,y+1);
	}
	/*LEFT*/
	if(x){
		if(maplist[x-1][y])solver(x-1,y);
	}
	/*RIGHT*/
	if(x-(n-1)){
		if(maplist[x+1][y])solver(x+1,y);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		for(int j=0;j<m;j++){
			if(str[j]=='#'){
				maplist[i][j]=0;
			}else{
				maplist[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maplist[i][j]){
				solver(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
[I1]
5 8
########
#..#...#
####.#.#
#..#...#
########
[O1]
3
*/
/*
[THINK]
______>n
......|
......|
......|
      V
	  m
#=0
.=1
*/
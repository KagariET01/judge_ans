/*
[Q]https://cses.fi/problemset/task/1142
[TLE 09]
[TLE 10]
*/

/*include*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define ulli unsigned long long int
#define lli long long int
#define pii pair<int,int>
#define plli pair<lli,lli>
#define pulli pair<ulli,ulli>
#define INT lli
#define UINT unsigned INT

/*struct*/

/*num*/

/*fn*/

/*main*/
int main(){
	UINT n;
	cin>>n;
	UINT k[n];
	UINT maxk=0;
	UINT mink=0;
	UINT lbr=0;/*左值大於右值數量*/
	UINT lsr=0;/*左值小於等於右值數量*/
	for(UINT i=0;i<n;i++){
		cin>>k[i];
		maxk=max(maxk,k[i]);
		if(mink){
			mink=min(mink,k[i]);
		}else{
			mink=k[i];
		}
		if(i){
			if(k[i-1]>k[i]){
				lbr++;
			}else{
				lsr--;
			}
		}
	}
	if(lbr>lsr){
		for(UINT i=0;i<(n/2);i++){
			swap(k[i],k[n-i-1]);
		}
	}
	map<UINT,UINT> highpoint;/*紀錄每個高度的竿子的位置*/
	UINT ans=0;
	for(UINT i=0;i<n;i++){
		if(i){
			/*如果現在這個比上一個矮*/
			if(k[i-1]>k[i]){
				/*偵測是否要加入*/
				if(!(highpoint.count(k[i]))){
					/*需要加入，從高度矮的開始找*/
					for(UINT j=k[i]+1;j<=maxk;j++){
						/*如果該高度有資料*/
						if(highpoint.count(j)){
							highpoint[k[i]]=highpoint[j];
							break;
						}
					}
				}
				for(UINT j=k[i]+1;j<=maxk;j++){
					if(highpoint.count(j)){
						highpoint.erase(j);
					}
				}
			}else if(k[i-1]<k[i]){
				/*你比上一個高，直接進去，不要多問*/
				highpoint[k[i]]=i;
			}
			/*計算ans*/
			if(i>=n-1 || k[i+1]<k[i]){
				/*下一個會變矮，或者已經到結尾再計算*/
				/*下一個會長高或一樣高的話，丟給下一次計算就好*/
				/*如果已經到結尾了，就一定要計算*/
				for(UINT j=mink;j<=k[i];j++){
					/*該高度有資料再計算即可，若無資料則代表可以更高*/
					if(highpoint.count(j)){
						UINT thisans=(i-highpoint[j]+1)*j;/*距離*高度*/
						ans=max(thisans,ans);
					}
				}
			}
		}else{
			/*如果是第一個，先做初始化*/
			ans=k[i];
			highpoint[k[i]]=i;
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
8
4 1 5 3 3 2 4 1
[O1]
10
*/

/*think*/
/*

*/
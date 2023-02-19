/*
[Q]
[]
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
#include<stack>
#include<cstring>
#include<unordered_map>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
string a[200005];
unordered_map<string,INT> ma;
INT m,n;
INT ans;
/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	{/*CIN*/
		cin>>m>>n;
		for(INT i=0;i<n;i++){
			cin>>a[i];
		}
	}
	{/*solve*/
		INT blockcolorcount=0;
		for(INT i=0;i<m;i++){
			if(!ma[a[i]])blockcolorcount++;
			ma[a[i]]++;
		}
		ans+=(blockcolorcount==m);
		for(INT L=0,R=m;R<n;L++,R++){
			//偵查範圍為L+1到R(含)
			ma[a[L]]--;
			if(ma[a[L]]==0)blockcolorcount--;//如果把L砍掉後，該顏色在區間只剩0，則總顏色數--
			if(ma[a[R]]==0)blockcolorcount++;//如果R那格沒有重複顏色，就++
			ma[a[R]]++;
			ans+=(blockcolorcount==m);
		}
	}
	cout<<ans;
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*
直接用string的原因是因為它有可能會超過ULLI的範圍
(max=10^150)
*/

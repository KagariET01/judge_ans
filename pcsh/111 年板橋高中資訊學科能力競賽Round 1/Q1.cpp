/*
[Q]
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
#include<deque>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
#define INT ulli
#define UINT int
#define pii pair<INT,INT>
#define puiui pair<UINT,UINT>
const INT maxnm=500;
INT n,m,a,b;
INT rc;
string maplist[maxnm+5];
int main(){
	//cin.tie(0);
	//cout.tie(0);
	//ios_base::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
	a%=4;
	a+=4;
	b%=4;
	if(a>=b) rc=(a-b)%4;
	else if(b>a)rc=(a+4-b)%4;
	if(rc<0){
        rc=4+rc;
	}
	for(INT i=0;i<n;i++){
        cin>>maplist[i];
	}


	if(rc==0){
        for(INT i=0;i<n;i++){
            for(INT j=0;j<m;j++){
                cout<<maplist[i][j];
            }
            cout<<"\n";
        }
	}else if(rc==1){
	    for(INT i=0;i<m;i++){
            for(INT j=n-1;j>=0;j--){
                cout<<maplist[j][i];
                //cout<<"["<<i<<"."<<j<<"]";
            }
            cout<<"\n";
	    }
	}else if(rc==2){
	    for(INT i=n-1;i>=0;i--){
            for(INT j=m-1;j>=0;j--){
                cout<<maplist[i][j];
                //cout<<"["<<i<<"."<<j<<"]";
            }
            cout<<"\n";
	    }
	}else if(rc==3){
	    for(INT i=m-1;i>=0;i--){
            for(INT j=0;j<n;j++){
                cout<<maplist[j][i];
                //cout<<"["<<i<<"."<<j<<"]";
            }
            cout<<"\n";
	    }
	}
	return 0;
}

/*
[AC]
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>

using namespace std;

#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

/*num*/
bool debug=false;
bool iofast=true;
/*fn*/
/*main*/
int main(){
    if(!debug && iofast){ET01;}
    /*cin*/
    INT i;
    cin>>i;
    /*solve*/
    INT a;
    //INT x=1;
    //INT y=i*2-1;
    a=(i*2)*i-(i*2-1);
    INT e=8*i-4;
    cout<<a<<" "<<e;
    return 0;
}

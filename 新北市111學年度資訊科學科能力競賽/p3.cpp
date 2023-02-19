/*
[數論]
[三角函數]
[模擬]
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
#define INT int
#define FINT double
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

/*num*/
bool debug=false;
bool iofast=true;
INT n;
FINT x=0;
FINT y=0;
/*fn*/
/*main*/
int main(){
    if(!debug && iofast){ET01;}
    cin>>n;
    INT nowangle=0;
    for(INT i=0;i<n;i++){
        /*cin*/
        FINT angle;
        FINT imove;
        FINT fx;
        FINT fy;
        cin>>angle>>imove>>fx>>fy;
        nowangle+=angle;
        nowangle%=360;

        /*solve*/
    }
    return 0;
}

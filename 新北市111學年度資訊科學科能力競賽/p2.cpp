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
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>
#define ET01 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

/*num*/
bool debug=false;
bool iofast=true;
bool wasdo=false;
/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    string str;
    while(getline(cin,str)){
        /*cin*/
        vector<INT>vec;
        INT num=0;
        for(char c:str){
            if(c==' '){
                vec.push_back(num);
                num=0;
            }else{
                num=num*10+INT(c-'0');
            }
        }
        vec.push_back(num);
        /*solve*/
        INT mx=0;
        for(INT i:vec){
            mx=max(mx,i);
        }
        if(wasdo)cout<<endl;
        if(mx==vec[0])cout<<"0";
        else cout<<mx;
        wasdo=true;
    }
    return 0;
}

/*
[]
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
#define endl "\n"

/*num*/
bool debug=true;
bool iofast=true;
map<INT,PII> caradd;
vector<INT> dolist;

/*fn*/
/*main*/
INT main(){
    if(!debug && iofast){ET01;}
    string str;
    vector<INT> vec[3010];
    INT a=0;
    while(getline(cin,str)){
        /*cin*/
        if(str=="\\")break;
        INT num=0;
        INT mn=1;
        INT j=0;
        for(char c:str){
            if(c==' '){
                vec[a].push_back(num*mn);
                num=0;
                mn=1;
            }
            else if(c=='-')mn=-1;
            else{
                num=num*10+(INT)(c-'0');
            }
        }
        vec[a].push_back(num*mn);
        a++;
    }
    /*solve*/
    for(INT i=0;i<a-1;i++){// 記錄每台車的位置
        //i為塔號
        for(INT j=1;j<vec[i].size();j++){
            //j為塔的停車格座標
            if(vec[i][j]==0)continue;
            PII ad={i,j};
            caradd[vec[i][j]]=ad;
        }
    }
    if(debug)cerr<<"65"<<endl;
    for(INT j:vec[a-1]){
        if(j<0){//car leave
            PII ad=caradd[-j];
            INT towel=ad.first;
            INT num=ad.second;
            vec[towel][num]=0;
            vec[towel][0]=num;
        }else{//car coming
            //find space
            bool wasfind=false;
            INT adder=0;
            INT towel=0;// 塔
            INT finaladd=0;
            while(!wasfind){
                for(towel=0;towel<a-1;towel++){
                    INT toweladd=vec[towel][0];//原始位置
                    toweladd+=adder;//轉動
                    toweladd%=vec[towel].size()-1;//n+1=1
                    if(toweladd==0)toweladd=vec[towel].size()-1;//0=1
                    if(vec[towel][ toweladd ]==0){
                        finaladd=toweladd;
                        wasfind=true;
                        break;
                    }
                    //另一邊
                    toweladd=vec[towel][0];//原始位置
                    toweladd-=adder;//轉動
                    toweladd+=vec[towel].size()-1;//避免負數
                    toweladd%=vec[towel].size()-1;//n+1=1
                    if(toweladd==0)toweladd=vec[towel].size()-1;//0=1
                    if(vec[towel][ toweladd ]==0){
                        finaladd=toweladd;
                        wasfind=true;
                        break;
                    }
                }
                if(wasfind)break;
                adder++;
            }

            vec[towel][0]=finaladd;
            PII ad={towel,finaladd};
            vec[towel][ finaladd ]=j;
            caradd[j]=ad;
        }
    }
    for(INT i=0;i<a-1;i++){
        if(i)cout<<endl;
        for(INT j=0;j<vec[i].size();j++){
            if(j)cout<<" ";
            cout<<vec[i][j];
        }
    }
    return 0;
}
/*
[I1]
4 234 0 345 456
2 123 0 0 0
-123 222 333
[O1]
4 234 0 345 456
2 222 333 0 0
*/

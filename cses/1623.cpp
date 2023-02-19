/*
[Q]https://cses.fi/problemset/task/1623
*/
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> apple;
bool firsttime;
int n;
long long int nownum;
long long int ans;
int finder(int add){
    if(add==n){
        ans=min(abs(nownum),ans);
    }else{
        nownum+=apple[add];
        finder(add+1);
        nownum-=apple[add]*2;
        finder(add+1);
        nownum+=apple[add];
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        apple.push_back(a);
        ans+=a;
    }
    nownum=0;
    finder(0);
    cout<<ans;
    return 0;
}
/*
[I1]
5
3 2 7 4 1
[O1]
1
*/


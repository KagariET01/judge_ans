/*
[Q]https://cses.fi/problemset/task/1645
[]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<stack>
#include<deque>
using namespace std;
#define ulli unsigned long long int
#define lli long long ulli
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ulli n;
    cin>>n;
    vector< pair<ulli,ulli> >x;
    for(ulli i=0;i<n;i++){
		int z;
        cin>>z;
		x.push_back({z,i});
    }
    deque< pair<ulli,ulli> > st;
    for(ulli i=0;i<n;i++){
		if(i){
			deque< pair<ulli,ulli> >::iterator stit=st.end();
			stit--;
			ulli ans=0;
            ans=(*stit).second+1;
			while((*stit).first>=x[i].first){
                if(stit==st.begin()){
                    ans=0;
                    break;
                }
                stit--;
                ans=(*stit).second+1;
            }
			cout<<ans<<" ";
			st.push_back(x[i]);
		}else{
			cout<<"0 ";
			st.push_back(x[i]);
			continue;
		}
        deque< pair<ulli,ulli> >::iterator stit=st.begin();
        deque< pair<ulli,ulli> >::iterator stedit=st.end();
        stedit--;
		while(stit!=stedit){
            if((*stit).first>=(*stedit).first){
                deque< pair<ulli,ulli> >::iterator delit=stit;
                stit++;
                st.erase(delit);
            }else{
                stit++;
            }
        }
    }
	return 0;
}
/*
*/

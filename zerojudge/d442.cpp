#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
int main(){
	set<int> happynum;
	set<int> unhappynum;
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		int n,thisnum;
		cin>>n;
		thisnum=n;
		bool wasit=true;
		set<int> check;
		while(true){
			//check(true)
			set<int>::iterator check_it;
			check_it=happynum.find(n);
			if(n==1){
				wasit=true;
				break;
			}
			//check(false)
			check_it=check.find(n);
			if(check_it!=check.end()){
				wasit=false;
				break;
			}
			check_it=unhappynum.find(n);
			if(check_it!=unhappynum.end()){
				wasit=false;
				break;
			}
			
			
			
			check.insert(n);
			
			//pow total;
			string n_s=to_string(n);
			int nextnum=0;
			for(int i=0;i<n_s.size();i++){
				nextnum+=int(pow(n_s[i]-int('0'),2));
			}
			n=nextnum;
		}
		if(wasit){
			cout<<"Case #"<<i<<": "<<thisnum<<" is a Happy number.\n";
			set<int>::iterator check_it;
			check_it=check.begin();
			for(int i=0;i<check.size();i++){
				happynum.insert(*check_it);
				check_it=next(check_it);
			}
		}else{
			cout<<"Case #"<<i<<": "<<thisnum<<" is an Unhappy number.\n";
			set<int>::iterator check_it;
			check_it=check.begin();
			for(int i=0;i<check.size();i++){
				unhappynum.insert(*check_it);
				check_it=next(check_it);
			}
		}
	}
	
	
	return 0;
}
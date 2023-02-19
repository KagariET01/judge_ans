#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
int main(){
	int t;
	for(int z=1;z<=t;z++){
		cin>>t;
		if(not(t)){break;}
		cout<<"Scenario #"<<z;
		vector<int> a_queue;
		while(t--){
			int n;
			cin>>n;
			while(n--){
				int teamnum;
				cin>>teamnum;
				vector<int>::iterator a;
				a=find(a_queue.begin(),a_queue.end(),teamnum);
				if(a==null){
					a_queue.append(teamnum);
				}
			}
		}
		while(true){
			string a_input;
			cin>>a_input;
			if(a_input=="ENQUEUE"){
				int teamnum;
				cin>>teamnum;
				vector<int>::iterator a;
				a=find(a_queue.begin(),a_queue.end(),teamnum);
				if(a==null){
					a_queue.append(teamnum);
				}
			}else if(a_input=="DEQUEUE"){
				cout<<a_queue.front<<"\n";
				a_queue.pop_front;
			}else if(a_input=="STOP"){
				cout<<"\n"
				break;
			}
			
			if(a_queue.size==0){
				cout<<"\n"
				break;
			}
		}
	}
	return 0;
}
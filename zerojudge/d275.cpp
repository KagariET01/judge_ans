#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	int a;
	cin>>a;
	string z;
	getline(cin,z);
	for(int i=0;i<a;i++){
		string b;
		getline(cin,b);
		bool loop=true;
		int bsize=b.size();
		if(b[0]==b[bsize-1]){loop=false;}
		else if(bsize<=2){loop=false;}
		else{
			stringstream bb(b);
			bb>>b;
			char last=b[1];
			while(bb>>b){
				if(b[0]==last){loop=false;break;}
				last=b[1];
			}
			
		}
		if(loop){cout<<"LOOP\n";}
		else{cout<<"NO LOOP\n";}
	}
	return 0;
}
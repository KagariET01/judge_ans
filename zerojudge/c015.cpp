#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int a;
	cin>>a;
	while(a--){
		string fir_s;
		cin>>fir_s;
		int counter=0;
		while(true){
			int fir_i=stoi(fir_s);
			char las_s[fir_s.size()];
			for(int i=0;i<fir_s.size();i++){
				las_s[fir_s.size()-i-1]=fir_s[i];
			}
			int las_i=stoi(las_s);
			if(counter!=0){
				if(fir_i==las_i){
					cout<<counter<<" "<<fir_i<<"\n";
					break;
				}
			}
			fir_s=to_string(fir_i+las_i);
			counter++;
			
		}
	}
	return 0;
}
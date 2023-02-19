#include<iostream>
#include<string>
using namespace std;
int main(){
	int a=0;
	cin>>a;
	for(int i=0;i<a;i++){
		int h=0,w=0;
		cin>>h;
		cin>>w;
		int l[h][w];
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				cin>>l[j][k];
			}
		}
		int g=1;
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				int nj=h-j-1;
				int nk=w-k-1;
				if(l[j][k]!=l[nj][nk]){
					g=0;
					break;
				}
			}
			if(not(g)){
				break;
			}
		}
		if(g){cout<<"go forward\n";}
		else{cout<<"keep defending\n";}
	}
}
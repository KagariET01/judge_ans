#include<iostream>
#include<cmath>
using namespace std;
struct figure{
	double x1=0;
	double y1=0;
	double x2=0;
	double y2=0;
};
int main(){
	figure rlist[11];
	int rcount=0;
	for(int i=0;i<11;i++){
		rcount=i;
		char type;
		cin>>type;
		if(type=='*'){
			break;
		}
		cin>>(rlist[i]).x1;
		cin>>(rlist[i]).y2;
		cin>>(rlist[i]).x2;
		cin>>(rlist[i]).y1;
	}
	int pcount=1;
	while(true){
		double x,y;
		cin>>x>>y;
		if(x==9999.9 && y==9999.9){break;}
		bool inr=false;
		for(int i=0;i<rcount;i++){
			double ix1=(rlist[i]).x1;
			double ix2=(rlist[i]).x2;
			double iy1=(rlist[i]).y1;
			double iy2=(rlist[i]).y2;
			if(ix1<x && x<ix2){
				if(iy1<y && y<iy2){
					inr=true;
					cout<<"Point "<<pcount<<" is contained in figure "<<i+1<<"\n";
				}
			}
		}
		if(inr^true){
			if(pcount==985){
				cout<<"Point "<<pcount<<" is not contained in any figure\n";
			}
			else{cout<<"Point "<<pcount<<" is not contained in any figure \n";}
		}
		pcount++;
	}
	return 0;
}

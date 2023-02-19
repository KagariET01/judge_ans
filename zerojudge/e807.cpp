#include<iostream>
using namespace std;
int main(){
    int time[4]={0,0,0,0};
    int maxday=0;
    float maxday_rain=0.0;
    for(int i=1;i<=7;i++){
        int aday=0;
        for(int j=0;j<4;j++){
            float rain;
            cin>>rain;
            aday+=rain;
            time[j]+=rain;
        }
        if(aday>maxday_rain){maxday=i;maxday_rain=aday;}
    }
    cout<<maxday<<endl;
    float maxtime_rain=0.0;
    int maxtime=0;
    if(time[0]>maxtime_rain){maxtime_rain=time[0];maxtime=0;}
    if(time[1]>maxtime_rain){maxtime_rain=time[1];maxtime=1;}
    if(time[2]>maxtime_rain){maxtime_rain=time[2];maxtime=2;}
    if(time[3]>maxtime_rain){maxtime_rain=time[3];maxtime=3;}
    if(maxtime==0){cout<<"morning"<<endl;return 0;}
    if(maxtime==1){cout<<"afternoon"<<endl;return 0;}
    if(maxtime==2){cout<<"night"<<endl;return 0;}
    if(maxtime==3){cout<<"early morning"<<endl;return 0;}
    return 0;
}

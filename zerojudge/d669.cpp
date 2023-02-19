#include <iostream>

using namespace std;

int main(){
    while(true){
        int ha,ma,hb,mb,a=0,b=0;
        cin>>ha;
        cin>>ma;
        cin>>hb;
        cin>>mb;
        if(ha||ma||hb||mb){
            a=ha*60+ma;
            b=hb*60+mb;

            b-=a;
            if(b<0){b+=1440;}

            cout<<b<<"\n";
        }else{break;}





    }
    return 0;
}

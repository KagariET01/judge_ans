#include <iostream>

using namespace std;

int main(){
    unsigned long long int n;
    cin>>n;
    for(int i=0;i<n;i++){
        unsigned long long int total_money=0,f=0;
        cin>>f;
        for(int j=0;j<f;j++){
            unsigned long long int area,animal,lv,this_total=0;
            cin>>area;
            cin>>animal;
            cin>>lv;
            this_total=area*lv;
            total_money+=this_total;
        }
        cout<<total_money<<"\n";
    }





    return 0;
}

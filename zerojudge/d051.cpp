#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    double a;
    cin>>a;
    cout<<setprecision(3)<<fixed<<(a-32)*5/9<<endl;
    return 0;
}

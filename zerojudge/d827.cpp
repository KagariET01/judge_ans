#include <iostream>

using namespace std;

int main(){
    int a=0;
    cin>>a;
    cout<<(int(a%12)*5+int(a/12)*50)<<endl;

    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int Z,I,M,L,now=1;
    while(true){
        cin>>Z;
        cin>>I;
        cin>>M;
        cin>>L;
        int h_list[10000]={0};
        if(not(Z||I||M||L)){break;}
        int i=0;
        while(not(h_list[L])){
            h_list[L]=i;
            int n_rand=(Z*L+I);
            n_rand%=M;
            L=n_rand;
            i++;
        }
        cout<<"Case "<<now<<": "<<i-h_list[L]<<"\n";
        now++;
    }
    return 0;
}

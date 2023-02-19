#include <iostream>

using namespace std;

int main(){
    int n,m,k,now=0,i=0;
    cin>>n;
    cin>>m;
    cin>>k;
    while(true){
        if(not(k)){
            if(n>=32){
                n-=32;
                cout<<now<<": Wayne eats an Apple pie, ";
                if(n>1){cout<<"and now he has "<<n<<" dollars.\n";}
                else if(n==1){cout<<"and now he has 1 dollar.\n";}
                else{cout<<"and now he doesn't have money.";}
                k=1;
                i++;
            }else{break;}
        }
        else{
            if(n>=55){
                n-=55;
                cout<<now<<": Wayne drinks a Corn soup, ";
                if(n>1){cout<<"and now he has "<<n<<" dollars.\n";}
                else if(n==1){cout<<"and now he has 1 dollar.\n";}
                else{cout<<"and now he doesn't have money.";}
                k=0;
                i++;
            }else{break;}
        }
        now+=m;

    }
    if(not(i)){cout<<"Wayne can't eat and drink.";}



    return 0;
}

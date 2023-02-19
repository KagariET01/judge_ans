#include<iostream>
using namespace std;
int main(){
    int n,star;
    cin>>n>>star;
    star/=1000;
    int max_num;
    int max_score;
    for(int i=0;i<n;i++){
        int cp,iv,score;
        cin>>cp>>iv;
        score=cp;
        if(iv>=0&&iv<=29){score+=(star*10);}
        if(iv>=30&&iv<=39){score+=(star*50);}
        if(iv>=40&&iv<=45){score+=(star*100);}
        if(score>max_score){max_score=score;max_num=i+1;/*cout<<"max_num="<<max_num<<endl;cout<<"max_score="<<max_score<<endl;*/}
    }
    cout<<max_num<<" "<<max_score<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef list<int> listint;
int main(){
    int all=87;
    listint circle;
    while(all){
        circle.clear();
        cin>>all;
        if(all){
            cout<<"Discarded cards: ";
            for(int f1=1;f1<=all;f1++){
                circle.push_back(f1);
            }
            while(circle.size()>1){
                cout<<*(circle.begin());
                if(circle.size()>2){
                    cout<<", ";
                }
                circle.pop_front();
                int s=*(circle.begin());
                circle.pop_front();
                circle.push_back(s);
            }
            cout<<'\n'<<"Remaining card: "<<*(circle.begin())<<endl;
        }
    }
    return 0;
}

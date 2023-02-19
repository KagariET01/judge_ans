#include<iostream>
#include<list>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m],ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int counter1=0;
            {
                for(int x=0;x<m;x++){
                   counter1+=b[i][x];
                }
                for(int y=0;y<n;y++){
                   counter1+=b[y][j];
                }
                counter1-=b[i][j];
            }
            if(counter1%2==1){
                if(a[i][j]==1){ans[i][j]=0;}
                if(a[i][j]==0){ans[i][j]=1;}
            }
            if(counter1%2==0){
                ans[i][j]=a[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

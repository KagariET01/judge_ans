#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int n,i=1;
	while(cin>>n){
		int last,nownum;
		int numlist[n];
		set<int> se;
		set<int>::iterator se_it;
		bool wasit=true;
		for(int i=0;i<n;i++){
			cin>>numlist[i];
		}
		
		
		for(int i=0;i<n && wasit;i++){
		    for(int j=0;j<=i && wasit;j++){
				int sum=numlist[i]+numlist[j];
				se_it=se.find(sum);
				if(se_it!=se.end()){
					wasit=false;
					break;
				}else{
					se.insert(numlist[i]+numlist[j]);
					se_it=se.lower_bound(numlist[i]+numlist[j]);
				}
		    }
		}
		if(wasit){
			cout<<"Case #"<<i<<": It is a B2-Sequence.\n\n";
		}else{
			cout<<"Case #"<<i<<": It is not a B2-Sequence.\n\n";
		}
		i++;
	}
	
	return 0;
}


/*
[sample input 1]
4
1 2 4 8
4
3 7 10 14
5
13 14 15 16 17
[sample output 1]
Case #1: It is a B2-Sequence.

Case #2: It is not a B2-Sequence.

Case #3: It is not a B2-Sequence.

*/
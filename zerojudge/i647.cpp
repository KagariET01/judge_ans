/*
[Q]https://zerojudge.tw/ShowProblem?problemid=i647
[]
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#define ulli unsigned long long int
#define lli long long int
/*宣告變數*/
string instr;
int x[31];/*原數*/
int xcopy[31];/*原數copy*/
int b[31];/*動作數*/
int bend=0;/*b數位數*/
int in[31];/*進位*/
int xmod[31];/*x餘數*/
int modnum[]={3,5,3,4,4,2,8,9,9};/*怪數*/
int ccopyx[31];/*x備份*/
/*宣告函式*/
void instrtox();/*將文字轉換到x*/
void instrtob();/*將文字轉換到b*/
void clearb();/*清理b*/
void clearx();/*清理x*/
ulli bendcount();/*計算b是幾位數*/
void clearin();/*清理in*/
void mult();/*乘法*/
void divi();/*除法+餘數*/
bool subt(int a=0);/*剪髮*/
void addi(int a=0);/*家法*/
void xxmodmove();/*將xmod移到x*/
void copyxxcopy();/*複製x到xcopy*/
void copyxcopyxmod();/*複製xcopy到xmod*/
void copyxcopyx();/*複製xcopy到x*/
void copymodnumb();/*複製modnum到b*/
bool checkxmod();/*確認xmod是否有數值，若有則true*/
void copyxccopyx();/*複製x到ccopyx*/
void copyxxccopy();/*複製ccopyx到x*/
void xprinter();
int main(){
	int m;
	cin>>instr>>m;
	instrtox();
	while(m--){
		int a;
		cin>>a;
		cin>>instr;
		instrtob();
		if(a==1){/*乘法*/
			mult();
			copymodnumb();
			divi();
			xxmodmove();
			xprinter();
			clearb();
		}else if(a==2){/*除法*/
			copyxccopyx();
			divi();
			if(checkxmod()){
				cout<<"ERROR\n";
				copyxxccopy();
				clearb();
				continue;
			}else{
				copymodnumb();
				divi();
				xxmodmove();
			}
		}else if(a==3){/*次方*/
			cout<<"fuckyou";
		}
	}
	return 0;
}
/*函式庫*/

	void instrtox(){/*將文字轉換到x*/
		int j=0;
		for(int i=instr.size()-1;i>=0;i--){
			x[j]=int(instr[i])-int('0');
			j++;
		}
	}
	void instrtob(){/*將文字轉換到b*/
		int j=0;
		for(int i=instr.size()-1;i>=0;i--){
			b[j]=int(instr[i])-int('0');
			j++;
		}
	}
	void clearb(){/*清理b*/
		for(int i=0;i<31;i++){
			b[i]=0;
		}
		bend=0;
	}
	void clearx(){/*清理x*/
		for(int i=0;i<31;i++){
			x[i]=0;
		}
		bend=0;
	}
	ulli bendcount(){/*計算b是幾位數*/
		for(int i=0;i<31;i++){
			if(b[i]){
				bend=i;
			}
		}
		return bend;
	}
	void clearin(){/*清理in*/
		for(int i=0;i<31;i++){
			in[i]=0;
		}
	}
	void mult(){/*乘法*/
		for(int i=0;i<30;i++){
			int ansx,ansin;
			ansx=(x[i]*b[i]+in[i])%10;
			ansin=(x[i]*b[i]+in[i])/10;
			in[i+1]=ansin;
			x[i]=ansx;
		}
		clearin();
	}
	void divi(){/*除法+餘數*/
		copyxxcopy();
		clearx();
		for(int i=30-bendcount();i>=0;i--){
			while(true){
				if(subt(i)){
					x[i]++;
				}else{
					addi(i);
					break;
				}
			}
		}
		copyxcopyxmod();
	}
	bool subt(int a=0){/*剪髮*/
		for(int i=0;i<30-a;i++){
			xcopy[i+a]-=b[i];
			if(xcopy[i+a]<0){
				xcopy[i+a+1]--;
				xcopy[i+a]+=10;
			}
		}
		if(xcopy[30]<0){
			return false;
		}else{
			return true;
		}
	}
	void addi(int a=0){/*家法*/
		for(int i=0;i<30-a;i++){
			xcopy[i+a]+=b[i];
			if(xcopy[i+a]>0){
				xcopy[i+a+1]++;
				xcopy[i+a]-=10;
			}
		}
	}
	void xxmodmove(){/*將xmod移到x*/
		for(int i=0;i<31;i++){
			x[i]=xmod[i];
		}
	}
	void copyxxcopy(){/*複製x到xcopy*/
		for(int i=0;i<31;i++){
			xcopy[i]=x[i];
		}
	}
	void copyxcopyxmod(){/*複製xcopy到xmod*/
		for(int i=0;i<31;i++){
			xmod[i]=xcopy[i];
		}
	}
	void copyxcopyx(){/*複製xcopy到x*/
		for(int i=0;i<31;i++){
			x[i]=xcopy[i];
		}
	}
	void copymodnumb(){/*複製modnum到b*/
		for(int i=0;i<31;i++){
			b[i]=modnum[i];
		}
	}
	bool checkxmod(){/*確認xmod是否有數值，若有則true*/
		for(int i=0;i<31;i++){
			if(xmod[i]){
				return true;
			}
		}
		return false;
	}
	void copyxccopyx(){/*複製x到ccopyx*/
		for(int i=0;i<31;i++){
			ccopyx[i]=x[i];
		}
	}
	void copyxxccopy(){/*複製ccopyx到x*/
		for(int i=0;i<31;i++){
			x[i]=ccopyx[i];
		}
	}
	void xprinter(){
		void nowcanprint=false;
		for(int i=31;i>=0;i--){
			if(x[i]){
				nowcanprint=true;
			}
			if(nowcanprint){
				cout<<x[i];
			}
		}
		cout<<"\n";
	}

/*
[I1]
3 4
2 2
2 1
1 3
3 3
[O1]
ERROR
3
9
729
[I2]
998244352 2
1 1000000000
1 1000000000
[O2]
996488706
282173455
*/
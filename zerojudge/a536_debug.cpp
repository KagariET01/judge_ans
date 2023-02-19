/*
[Q]
[]
*/

/*include*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT LLI
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/

/*fn定義*/

/*main*/
int main(){
	{/*IO加速*/
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
	}
	UINT f=0;
	for(UINT e=0;e<=10;e++){
		for(UINT c=2;c<=10;c++){
			/*aans*/
			UINT a=e+f;
			UINT aans=(a-1)/(c-1);
			/*bans*/
			UINT bf=f,be=e,bc=c;
			UINT ba=be+bf;
			UINT bans=0;
			while(ba/bc){
				UINT now=ba/bc;
				bans+=ba/bc;
				ba=ba%bc+now;
			}
			if(aans==bans){
				cout<<"e="<<e<<",c="<<c<<",ans="<<aans<<"\n";
			}else{
				cout<<"e="<<e<<",c="<<c<<",aans="<<aans<<",bans="<<bans<<"\n";
			}
		}
	}
	return 0;
}

/*
[I1]
2
9 0 3
5 5 2
[O1]
4
9
*/

/*think*/
/*
我之前有解過類似的(但我忘記題目編號了)
新的解法如下:
先把空瓶全部集中e+f
	先拿c個瓶子去換可樂
	換完後會回收1個瓶子
縮排的兩個步驟合計下來，瓶子增減為-(c-1)
重複n次，瓶子增減為-(c-1)*n
而我們要盡可能的把瓶子換到不能再換
所以我們可以得出下面的算式
(先假設f=0，不然我會瘋掉)
e=(c-1)*n+1
(換到可樂是支出-，反向則是收入+)
[Ellie]诶ET01為甚麼後面有+1
因為換最後一次的時候，你要拿c個瓶子
雖然最後total只會減少c-1個
但是你要先生出c個瓶子，店家才會給你1個瓶子
如果你只有c-1個瓶子，你還是不夠換，因為店家要求c個(不管待會給的1個瓶子)
希望這樣解釋可以讓你理解那個+1是從哪來的

回到題目，題目要我們輸出n，所以我們將上述公式進行轉換
e=(c-1)*n+1
e-1=(c-1)*n
(e-1)/(c-1)=n
最後把f加回來
剛剛我們假設e是[所有瓶子]
現在轉換過來
以e+f代替[所有瓶子]
...我知道你們數學家想講甚麼，我就懶，怎樣，不然我會瘋掉
[Ellie](竊竊私語)其實ET01早就瘋了
最後我們能得到
(e+f-1)/(c-1)=n
n即為所求
[數學家](這句話怎麼異常熟悉)
*/

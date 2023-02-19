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
#include<stack>
#include<cstring>
#include<unordered_map>

/*using namespace*/
using namespace std;

/*define type*/
#define ULLI unsigned long long int
#define LLI long long int
#define INT int
#define UINT unsigned INT
#define PII pair<INT,INT>
#define PUIUI pair<UINT,UINT>

/*struct*/

/*fn宣告*/

/*num*/
const int MAX_N = 5001;
long long dp[MAX_N][MAX_N]; // dp[l][r] 代表輸入為子區間 [l, r] 時的答案
int x[MAX_N]; // 輸入
long long s[MAX_N]; // 前綴和陣列
/*fn定義*/
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        s[i] = x[i] + s[i - 1]; // 計算前綴和陣列
    }
    for(int r = 1; r <= n; r++) {
        for(int l = r; l > 0; l--) { // 這樣的計算順序會滿足在計算 dp[l][r] 時， dp[l + 1][r] 和 dp[l][r - 1] 都已計算出來
            // TODO: 請填上 dp[l][r] 怎麼從 dp[l + 1][r] 和 dp[l + 1][r] 計算出來
        }
    }
    cout << dp[1][n] << endl;
}
/*main*/
int main(){
	/*IO加速*/
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	/*CIN*/
	/*solve*/
	solve();
	return 0;
}

/*
[I1]
[O1]
*/

/*think*/
/*

*/

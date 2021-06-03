#include<bits/stdc++.h>
using namespace std;
int n, m;
int bash(int player, int left) {
	if (left == 0)return player;
	for (int i = 1; i <= m; i++) {
		if (bash((player + 1) % 2, left - i) != player) {
			return (player + 1) % 2;
		}
	}
	return player;
}
//改dp dp[1][n]=!(dp[0][n-1]&dp[0][n-2]&...&dp[0][n-m])  只要有一个为0（先手输的情况）这时先手拿i个便为胜
//dp[1][n]=!(!(dp[1][n-1]&!dp[0][n-m-1]))=dp[1][n-1]&!dp[0][n-m-1]
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		//if (n % (m + 1) != 0)cout << "first"<<endl;
		if (bash(1, n) == 0)cout << "first"<<endl;
		else cout << "second" << endl;
	}
}
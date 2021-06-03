#include<bits/stdc++.h>
using namespace std;
int dp[205];
int n, m;
int w[35], val[35];
int _01bag() {
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > 0; j--) {    //注意这里j从m开始 因需要不断利用上一个物品的信息 若从1开始会覆盖掉上一个的信息
			if (j >= w[i])
				dp[j] = max(dp[j - w[i]] + val[i], dp[j]);
		}
	}
	return dp[m];
}
int _completebag() {
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=m; j--) {
			if (j >= w[i])
				dp[j] = max(dp[j - w[i]] + val[i], dp[j]);
		}
	}
	return dp[m];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> w[i] >> val[i];
	return 0;
}
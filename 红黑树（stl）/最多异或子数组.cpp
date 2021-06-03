#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n;
int dp[10005];
map<int,int> sum;
int main()
{
	cin >> n;
	int sumnow = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sumnow = sumnow ^ a[i];
		if (sum.find(sumnow) != sum.end()) {
			dp[i] = dp[sum[sumnow]] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
		sum[sumnow] = i;
	}
	cout << dp[n];
	return 0;
}

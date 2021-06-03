#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int arr[maxn];
int n;
int dp[maxn][16];    //dp[i][j]代表从i位置起2^j个数中的最小值
void rmq_ini()
{	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = arr[i];
	}

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i+(1<<j-1) <= n; i++) {
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	rmq_ini();
	int l, r,k;
	while (scanf("%d%d", &l, &r) == 2) {
		k = log2(r - l + 1);      //原理即为[l,r]∈[l,l+2^k]∪[r-2^k+1,r];
		cout << min(dp[l][k], dp[r - (1 << k) + 1][k]) << endl;
	}
	return 0;
}
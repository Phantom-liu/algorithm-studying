#include<bits/stdc++.h>
using namespace std;
struct bucket {
	int value;
	vector<int> same;
};
const int maxn = 1e3 + 5;
int n;
int dp[maxn][21];
int a[maxn];
unordered_map<int, int> m;
void rmq_ini()
{
	for (int i = 1; i <= n; i++) {
		dp[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j - 1) <= n; i++) {
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	}
}
int rmq(int l, int r) {
	int k = log2(r - l + 1);
	return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main()
{
	cin >> n;
	bucket buc[maxn];
	int cnt = 0, ans = 0;;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (m.count(a[i]))buc[m[a[i]]].same.push_back(i);
		else {
			m[a[i]] = cnt;
			buc[cnt].same.push_back(i);
			buc[cnt++].value = a[i];
		}
	}
	rmq_ini();
	for (int i = 0; i < cnt; i++) {
		int len = buc[i].same.size();
		if (len == 1)continue;
		for (int j = 0; j < len; ) {
			int k, res;
			for (k = j + 1; k < len; k++) {
				if (rmq(buc[i].same[k - 1], buc[i].same[k]) != buc[i].value) {
					break;
				}
			}
			res = buc[i].same[k - 1] - buc[i].same[j];
			ans = max(ans, res);
			j = k;
		}
	}
	cout << ans;
	return 0;
}
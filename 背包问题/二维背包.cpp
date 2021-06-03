#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
int w1[maxn],w2[maxn],val[maxn];
int dp[maxn][maxn];
int _2dbag() {
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > 0; j--) {
			for (int k = m; k > 0; k--) {
				int x = max(j - w1[i], 0);
				int y = max(k - w2[i], 0);
				dp[j][k] = max(dp[j][k], dp[x][y]);
			}
		}
	}
	return dp[m][m];
}
int n1,m1,m2,a[100],b[100],w[100], dp1[100][5000];
int oxygenmin() {   //信息学奥赛1271 潜水员
	memset(dp1, 0x3f, sizeof dp1);
	for (int i = 1; i <= n1; i++) {
		for (int j = m1; j >= 0; j++) {
			for (int k = m2; k >= 0; k++) {
				if (a[i] >= j && b[i] >= k)dp[j][k] = min(dp[j - a[i]][k - b[i]], w[i]);
				else {
					int x = max(j - a[i], 0);
					int y = max(k - b[i], 0);
					dp[j][k] = min(dp[j][k], dp[x][y]+w[i]);
				}
			}
		}
	}
	return dp[m1][m2];
}
int main()
{

}
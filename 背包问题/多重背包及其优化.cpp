#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
int w[55], val[55], num[55];
//朴素做法
int limitedbag() {
	int dp1[55][maxn];
	memset(dp1, 0, sizeof dp1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= num[i]; k++) {
				if (w[i] > j) {
					dp1[i][j] = dp1[i - 1][j];
					break;
				}
				if (k*w[i] <= j) {
					dp1[i][j] = k==1?max(dp1[i-1][j], dp1[i - 1][j - k * w[i]] + k * val[i])
						: max(dp1[i][j], dp1[i - 1][j - k * w[i]] + k * val[i]);
				}
				else break;
			}//cout << dp1[i][j] << " ";
		}//cout << endl;
	}//cout << endl;
	//return dp1[n][m];
	int dp[maxn];
	memset(dp, 0, sizeof dp);
	//滚动数组优化第一维
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > num[i] * w[i]; j--) {  
			for (int k = 1; k <= num[i]; k++) {    //将k*w[i] 看成单独的物品 用01背包处理方式
				dp[j] = max(dp[j], dp[j -k*w[i]] + k*val[i]);
			}
		}
		for (int j=1;j<=min(num[i]*w[i],m);j++){   //注意这里j从1开始 类似完全背包（每次使用已更新的数据）
			if(j>=w[i])
			dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
		}
		/* for(int j=1;j<=m;j++)cout << dp[j] << " ";
		cout << endl; */
		// 或者写成01背包形式
		/*for (int j = m; j > 0; j--) {
			for (int k = 1; k <= num[i]; k++) {
				if (k*w[i] <= j)dp[j] = max(dp[j], dp[j - k * w[i]] + k * val[i]);
				else break;
			}
		}
		for (int j = 1; j <= m; j++) {
			cout << dp[j] << " ";
		}
		cout << endl;*/
	}
	return dp[m];
}
int binaryopti() {
	int cnt = 1;
	int dp[maxn];
	int wei[maxn], value[maxn];
	for (int i = 1; i <= n; i++) {
		int j;
		for (j = 0; (1 << j+1)-1 <= num[i]; j++) { //1<<j+1就是(∑2^k)+1,我们最后求的s是剩余量 即num[i]-∑2^k
			wei[cnt] = (1 << j)*w[i];
			value[cnt++] = (1 << j)*val[i];
		}
		int s = num[i]+1- (1 << j);
		if (s) {
			wei[cnt] = s*w[i];
			value[cnt++] = s*val[i];
		}
	}
	memset(dp, 0, sizeof dp);
	for (int i = 1; i < cnt; i++) {
		for (int j = m; j > 0; j--) {
			if (j >= wei[i])dp[j] = max(dp[j], dp[j - wei[i]] + value[i]);
		}
	}
	return dp[m];
}
int dequeopti()
{
	int dp[maxn];
	memset(dp, 0, sizeof dp);
	int cpy[maxn];
	for (int i = 1; i <= n; i++) {
		memcpy(cpy, dp, sizeof dp);  //需顺序更新dp数组
		for (int j = 0; j < w[i]; j++) {
			deque<int> q;
			for (int k = j; k <= m; k += w[i]) {
				if (!q.empty() && q.front() < k - num[i] * w[i]) {  //当队首元素已过期 队首出队
					q.pop_front();
				}
				if (!q.empty()) {   //队首元素一定为可选的件数(x>=1)中价值最高的  cpy[k]代表x=0；
					dp[k] = max(cpy[k], cpy[q.front()] + (k - q.front()) / w[i] * val[i]);  
				}
				while (!q.empty() && cpy[k] >= cpy[q.back()] + (k - q.back()) / w[i] * val[i]) {
					q.pop_back();  //加入k后若队内单调性不再满足 需从队尾pop(类似单调栈)
				}
				q.push_back(k);
			}
		}
	}
	return dp[m];
}
int main()
{
	freopen("zzl.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> val[i] >> w[i] >> num[i];
	limitedbag();
	cout<<dequeopti();
	return 0;
}
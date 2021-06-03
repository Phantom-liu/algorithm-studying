#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> g[maxn];
int value[maxn],deg[maxn],vis[maxn];
int n, sum ;
queue<int> q;
int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int dfs(int dele = maxn-1) {
	sum = 0; memset(vis, 0, sizeof(vis));
	vis[dele] = 1;
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		q.push(i);
		vis[i] = 1;
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (auto z : g[k]) {
				if (!vis[z]) {
					q.push(z);
					vis[z] = 1;
				}
			}
		}
		sum++;
	}
	return sum;
}
int main()
{
	cin >> n;
	memset(deg, 0, sizeof(deg));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)cin >> value[i];
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(value[i], value[j]) != 1)
			{
				g[i].push_back(j); deg[i]++;
				g[j].push_back(i); deg[j]++;
			}
		}
	}
	int initial = dfs();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (initial < dfs(i))cnt++;
	}
	cout << cnt;
	return 0;
}
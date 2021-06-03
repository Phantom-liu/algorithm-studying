#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
int from, to, deepth = 0;
struct Node {
	int value;
	vector<Node*> next;
	int num;
	int deep;
	Node() {
		deep = -1; value = num = 0;
	}
};
Node nod[maxn];
void deepset(Node *head, int deepnow = -1) {
	if (head == NULL)return;
	head->deep = ++deepnow;
	if (deepth < deepnow)deepth = deepnow;
	int l = nod[head->num].next.size();
	if (l == 1) return;
	for (int i = 0; i < l; i++)
	{
		if (head->next[i]->deep < 0)
			deepset(head->next[i], deepnow);
	}
	return;
}
int main()
{
	freopen("zz.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nod[i].value;
		nod[i].num = i;
	}
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d%d", &from, &to);
		nod[from].next.push_back(&nod[to]);
		nod[to].next.push_back(&nod[from]);
	}
	deepset(&nod[1]);
	if (deepth == 0) {
		cout << nod[1].value;
		return 0;
	}
	vector<int> leaves[100];
	for (int i = 1; i <= n; i++)leaves[nod[i].deep].push_back(i);
	int len = leaves[deepth].size();
	int dp[maxn][2];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; i++) {
		dp[leaves[deepth][i]][0] = 0;
		dp[leaves[deepth][i]][1] = nod[leaves[deepth][i]].value;
	}
	deepth--;
	int left = leaves[deepth].size();
	while (deepth + 1) {
		left = leaves[deepth].size();
		for (int i = 0; i < left; i++) {
			int s = leaves[deepth][i];
			int l = nod[s].next.size();
			for (int j = 0; j < l; j++)
			{
				if (dp[nod[s].next[j]->num][0] || dp[nod[s].next[j]->num][1]) {
					dp[s][0] += max(dp[nod[s].next[j]->num][1], dp[nod[s].next[j]->num][0]);
					dp[s][1] += dp[nod[s].next[j]->num][0];
				}
			}
			dp[s][1] += nod[s].value;
		}
		deepth--;
	}
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}
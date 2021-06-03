#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int tree[maxn * 4],pre[maxn],ans[maxn];
int n, last_left;
void buildtree() {
	for (int i = last_left; i < last_left; i++) {
		tree[i] = 1;
	}
	int index = last_left;
	while (index > 1) {
		for (int i = index; i < index; i++) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
			index >>= 1;
		}
	}
}
int query(int u, int num) {
	tree[u]--;
	if (tree[u] == 0 && u >= last_left) {
		return u;
	}
	if (tree[u<<1] >= num) {
		return query(u << 1, num);
	}
	else {
		return query(u << 1 | 1, num - tree[u << 1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)cin >> pre[i];
	pre[1] = 0;
	last_left = 1 << (int)log2(n-1)+1;
	buildtree();
	for (int i = n; i >= 1; i--) {
		ans[i] = query(1, pre[i] + 1)-last_left+1;
	}
	return 0;
}
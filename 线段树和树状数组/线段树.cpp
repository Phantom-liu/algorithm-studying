#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct {
	int l, r, len;
}tree[4*maxn];
int pre[maxn], ans[maxn];
void buildtree(int left, int right, int u) {
	tree[u].l = left;
	tree[u].r = right;
	tree[u].len = right - left + 1;
	if (left == right)return;
	buildtree(left, (left + right) >> 1, u << 1);
	buildtree((left + right) >> 1 + 1, right, (u << 1) + 1);
}
int query(int u,int num) {
	tree[u].len--;
	if (tree[u].l == tree[u].r)return tree[u].l;
	if (tree[u << 1].len < num) {
		return query((u << 1) + 1, num - tree[u << 1].len);
	}
	else {
		return query(u << 1, num);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)cin >> pre[i];
	pre[1] = 0;
	buildtree(1, n, 1);
	for (int i = 1; i <= n; i++) {
		ans[i] = query(1, pre[i] + 1);
	}
	for (int i = 1; i <= n; i++)cout << ans[i]<<endl;
	return 0;
}
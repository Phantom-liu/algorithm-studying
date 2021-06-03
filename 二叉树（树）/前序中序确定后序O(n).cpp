#include<bits/stdc++.h>
using namespace std;
int	n;
struct bitnode {
	int left, right;
	bitnode() :left(0), right(0) {}
};
const int maxn = 1e5 + 5;
int pre[maxn], in[maxn], vis[maxn];
int root;
bitnode tree[maxn];
void solve() {
	root = pre[0];
	vis[pre[0]] = 1;
	int cur1 = 0, cur2 = 0;
	while (cur1 < n - 1 || cur2 < n - 1) {
		while (in[cur2] != pre[cur1]) {
			tree[pre[cur1]].left = pre[cur1 + 1];
			vis[pre[cur1 + 1]] = 1;
			cur1++;
		}
		while (vis[in[cur2]]) {
			cur2++;
		}
		tree[in[cur2 - 1]].right = pre[cur1 + 1];
		vis[pre[cur1+1]] = 1;
		cur1++;
	}
}
void posterorder(int root)
{
	if (tree[root].left) {
		posterorder(tree[root].left);
	}
	if (tree[root].right) {
		posterorder(tree[root].right);
	}
	cout << root << " ";
}
int main() {
	freopen("input10.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	clock_t s = clock();
	solve();
	clock_t e = clock();
	cout << e - s;
	//posterorder(root);
	return 0;
}
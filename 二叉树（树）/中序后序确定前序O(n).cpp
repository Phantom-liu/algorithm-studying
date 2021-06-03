#include<bits/stdc++.h>
using namespace std;
int	n;
struct bitnode {
	int left, right;
	bitnode() :left(0), right(0) {}
};
const int maxn = 1e5 + 5;
int post[maxn], in[maxn], vis[maxn];
int root;
bitnode tree[maxn];
void solve() {
	root = post[n - 1];
	vis[post[n - 1]] = 1;
	int cur1 = n - 1, cur2 = n - 1;
	while (cur1 > 0 || cur2 > 0) {
		while (in[cur2] != post[cur1]) {
			tree[post[cur1]].right = post[cur1 - 1];
			vis[post[cur1 - 1]] = 1;
			cur1--;
		}
		while (vis[in[cur2]]) {
			cur2--;
		}
		tree[in[cur2 + 1]].left = post[cur1 - 1];
		vis[post[cur1 - 1]] = 1;
		cur1--;
	}
}
void preorder(int root)
{
	cout << root << " ";
	if (tree[root].left) {
		preorder(tree[root].left);
	}
	if (tree[root].right) {
		preorder(tree[root].right);
	}
}
/*
9
5 4 2 6 8 9 7 3 1
4 5 2 1 6 3 8 7 9
*/
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	clock_t s = clock();
	solve();
	clock_t e = clock();
	//cout << e - s;
	preorder(root);
	return 0;
}
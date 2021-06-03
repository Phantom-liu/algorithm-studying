//poj2528
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, t;
long long a[100005];
long long tree[100000 * 4 + 5], add[100000 * 4 + 5];
#define lson l,mid,u<<1
#define rson mid+1,r,u<<1|1
void push_up(int u) {
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
void buildtree(int l, int r, int u) {
	add[u] = 0;
	if (l == r) {
		tree[u] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(lson);
	buildtree(rson);
	push_up(u);
}
void push_down(int u, int m) {
	if (add[u]) {
		add[u << 1] += add[u];
		add[u << 1 | 1] += add[u];
		tree[u << 1] += (m - (m >> 1))*add[u];
		tree[u << 1 | 1] += (m >> 1)*add[u];
		add[u] = 0;
	}
}
void update(int a, int b, long long c, int l, int r, int u) {
	if (a <= l && b >= r) {
//		tree[u] += (r - l + 1)*c;
		add[u] += c;
		return;
	}
	//push_down(u, r - l + 1);
	int mid = (l + r) >> 1;
	if (a <= mid) {
		tree[u<<1] += (min(b,mid) - max(a,l)+1)*c;
		update(a, b, c, lson);
		//或者加上所有注释 并将上两行改为     update(a, b, c, lson);
	}	
	if (b > mid) {
		tree[u<<1|1] += (min(r,b) - max(mid,a-1))*c;
		update(a, b, c, rson);
		//或者加上所有注释 并将上两行改为     update(a, b, c, rson);
	}
	//push_up(u);
}
long long query(int a, int b, int l, int r, int u) {
	if (a <= l && b >= r) {
		return tree[u];
	}
	push_down(u, r - l + 1);
	int mid = l + r >> 1;
	long long ans = 0;
	if (a <= mid)ans += query(a, b, lson);
	if (b > mid)ans += query(a, b, rson);
	return ans;
}
int main()
{
	freopen("zz.txt", "r", stdin);
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	buildtree(1, n, 1);
	while (t--) {
		char s[2];
		int a, b; long long c;
		scanf("%s", s);
		if (s[0] == 'C') {
			scanf("%d %d %lld", &a, &b, &c);
			tree[1] += (b - a + 1)*c;   //用注释的方法可省略此行
			update(a, b, c, 1, n, 1);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(a, b, 1, n, 1));
		}
	}
	return 0;
}
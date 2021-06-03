#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
const int maxn = 100005;
int tree[maxn],pre[maxn],ans[maxn];
int n;
void add(int x,int d) {
	while (x <= n) {
		tree[x] += d;
		x += lowbit(x);
	}
}
int sum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int findpos(int k) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (sum(mid) < k) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)cin >> pre[i];
	pre[1] = 0;
	for (int i = 1; i <= n; i++) {
		tree[i] = lowbit(i);
	}
	for (int i = n; i > 0; i--) {
		int x = findpos(pre[i] + 1);
		add(x, -1);
		ans[i] = x;
	}
	return 0;
}
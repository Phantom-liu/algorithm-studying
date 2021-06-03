#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int mod = 1000000007;
ll n, q, a[maxn];
int pos[maxn];
int l, r;
int mutifac=1;
int com[2][100005];
void cmd(int x, ll b,ll num) {
	if (x == 1) {
		a[num]*= b;
		a[num] %= mod;
	}
	else {
		a[num] += b;
		a[num] %= mod;
	}
}
void pri(int cnt, int b) {
	for (; pos[b+l] < cnt; pos[b+l]++) {
		cmd(com[pos[b+l]][0], com[pos[b+l]][1], b+l);
	}
	printf("%d\n", a[b+l]);
}
int main()
{
	cin >> n >> q;
	l = 5000, r = 5000 + n + 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++)scanf("%d", &a[l + i]);
	for (int i = 1; i <= q; i++) {
		int x1, x2;
		cin >> x1 >> x2;
		if (x1 == 5) {
			pri(cnt, x2);
			continue;
		}
		if (x1 == 3) {
			a[l] = x2;
			pos[l--] = cnt+1;
			continue;
		}
		if (x1 == 4) {
			a[r] = x2;
			pos[r++] = cnt+1;
			continue;
		}
		com[++cnt][0] = x1;
		com[cnt][1] = x2;
	}
	//for (int i = 1; i <= cnt; i++) { cout << com[i][0] << "  "; }
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int	n;
int a[maxn];
int rl[maxn];
int ad[maxn];
stack<int> maxrl;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int res = 0;
	maxrl.push(1);
	int i = 2;
	while (!maxrl.empty() && i <= n) {
		if (a[i] > a[maxrl.top()]) {
			maxrl.push(i);
		}
		else if (a[i] == a[maxrl.top()]) {
			res = max(res, i - maxrl.top());
		}
		else {
			int now;
			while (!maxrl.empty()&&a[maxrl.top()]>a[i]) {
				maxrl.pop();
			}
			if (a[i] == a[maxrl.top()])res = max(res, i - maxrl.top());
			else maxrl.push(i);
		}
		i++;
	}
	cout << res;
	return 0;
}
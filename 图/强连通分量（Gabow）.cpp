#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int dfn[maxn],instack[maxn];
stack<int> s1, s2;  //s1顶点入栈 分量出栈  s2动态维护分量的栈
vector<int> g[maxn];
int t = 0, cnt = 0;
int n, m;
void gabow(int u)
{
	dfn[u] = ++t;
	instack[u] = 1;
	s1.push(u); s2.push(u);
	for (auto v : g[u]) {
		if (!dfn[v]) {
			gabow(v);
		}
		else if (instack[v]) {
			while (dfn[s2.top()] > dfn[v])
				s2.pop();
		}
	}
	if (u == s2.top()) {
		while (s1.top() != u) {
			instack[s1.top()] = 0;
			s1.pop();
		}
		instack[s1.top()] = 0;
		s1.pop(); s2.pop();
		cnt++;
	}
}
int main()
{
	freopen("zz.txt","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])gabow(i);
	}
	cout << cnt << endl;
	return 0;
}
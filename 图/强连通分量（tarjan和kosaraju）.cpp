#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
vector<int> node[maxn],inver[maxn];
int n, m;
vector <int> S;
stack<int> s;
int low[maxn], dfn[maxn];
int t = 0,cnt=0;
int vis[maxn],instack[maxn];
int scc[maxn];
//tarjan
void tarjan(int v)
{
	dfn[v] = ++t;
	low[v] = t;
	for (auto z : node[v]) {
		if (!dfn[z]) {
			instack[z] = 1;
			s.push(z);
			tarjan(z);
			low[v] = min(low[v], low[z]);
			continue;
		}
		if (instack[z]) {
			low[v] = low[z];
		}
	}
	if (low[v] == dfn[v]) {
		while (s.top() != v) {
			instack[s.top()] = 0;
			s.pop();
		}
		instack[s.top()] = 0;
		s.pop();
		cnt++;
	}
	cout << dfn[v] << "  " << low[v]<<"  "<<v<< endl;
}
//kosaraju
void dfs1(int v) {
	vis[v] = 1;
	for (auto z : node[v]) {
		if (!vis[z])dfs1(z);
	}
	S.push_back(v);
}
void dfs2(int v) {
	scc[v] = cnt;
	for (auto z : inver[v]) {
		if (!scc[z])dfs2(z);
	}
}
void kosaraju() {
	cnt = 0;
	S.clear();
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs1(i);
	}
	for (int i = n-1; i >= 0; i--) {
		if (!scc[S[i]]) {
			cnt++;
			dfs2(S[i]);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= n; j++) {
			if (scc[j] == i) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	freopen("zz.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		node[from].push_back(to);
		inver[to].push_back(from);  //反向边的图(korasaju)
	}
	//
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			s.push(i);
			instack[i] = 1;
			tarjan(i);
		}
	}
	cout << cnt << endl;
	//kosaraju
	kosaraju();
	cout << cnt << endl;
}
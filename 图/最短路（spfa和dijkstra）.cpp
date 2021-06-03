#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> g[10005];
ll n, m, s;
ll dis[10005];
bool vis[10005];
queue <ll> q;
void spfa() {
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	q.push(s);
	vis[s] = s;
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		vis[now] = 0;
		for (auto to : g[now]) {
			ll w = to.second, v = to.first;
			if (dis[now] + w < dis[v]) {
				dis[v] = dis[now] + w;
				if (vis[v] == 0) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
priority_queue<pll, vector<pll>, greater<pll> > q1;
void dijk()
{
	memset(dis, 0x3f, sizeof dis); 
	q1.push(make_pair(0, s));
	dis[s] = 0;
	while (!q1.empty()) {
		ll now = q1.top().second;
		q1.pop();
		/* if (vis[now]) {
			continue;
		} 
		vis[now] = 1; */
		for (auto to : g[now]) {
			ll v = to.second, w = to.first;
			if (dis[now] + w < dis[v]) {
				dis[v] = dis[now] + w;
				q1.push({ dis[v],v });
			}
		}
	}
}
int main()
{
	cin >> n >> m>>s;
	ll u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		//g[u].push_back({ v,w }); //spfa
		g[u].push_back({ w,v }); //dijk pair自带排序为第一维
	}
	//spfa();
	dijk();
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	return 0;
}
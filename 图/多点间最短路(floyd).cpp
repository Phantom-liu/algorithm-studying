#include<bits/stdc++.h>
using namespace std;
int g[110][110];
int n, m;
int main()
{
	cin >> n >> m;
	int u, v, w;
	memset(g, 0x3f, sizeof g); 
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		g[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", g[i][j], (j == n) ? '\n':' ');
	return 0;
}
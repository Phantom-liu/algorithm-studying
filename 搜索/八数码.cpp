#include<bits/stdc++.h>
using namespace std;
const int maxn = 362880;
const int factory[10] = { 1,1,2,6,24,150,720,5040,40320,362880 };
struct node {
	int state[9];
	int dis;
	int cantor;
};
int path[maxn];
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
int vis[maxn];
int start[9], goal[9];
int cantor(int a[], int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				cnt++;
			}
		}
		res += cnt * factory[n - 1 - i];
	}
	if (vis[res])return -1;
	else {
		vis[res] = 1;
		return res;
	}
}
node ans,s;
int bfs() {
	queue<node> q;
	node head;
	head.dis = 0;
	memcpy(head.state, start, sizeof start);
	head.cantor = cantor(head.state, 9);
	s = head;
	q.push(head);
	while (!q.empty()) {
		head = q.front();
		q.pop();
		int z=0;
		while (head.state[z])z++;
		int x = z % 3, y = z / 3;
		for (int i = 0; i < 4; i++) {
			int newx = x + dir[i][0];
			int newy = y + dir[i][1];
			if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
				int newz = 3 * newy + newx;
				node atara(head);
				atara.dis++;
				swap(atara.state[newz], atara.state[z]);
				int last = head.cantor;// cout << last << endl;
				int cant = cantor(atara.state, 9);
				if (memcmp(atara.state, goal, sizeof goal) == 0) {
					atara.cantor = cant;
					ans = atara;
					path[cant] = last;
					return atara.dis;
				}
				if (cant!=-1) {
					path[cant] = last;
					atara.cantor = cant;
					q.push(atara);
				}
			}
		}
	}
	return -1;
}
int res[9];
int* cantor_inv(int cant,int n) {
	int pre = cant - 1;
	int cnt = 0;
	int vis[9] = { 0 };
	for (int i = 0; i < n; i++) {
		int j = 0;
		cnt = pre / factory[n - 1 - i];
		if(cnt!=0)while (cnt != 0) { j++; if (!vis[j])cnt--; }
		else while (vis[j])j++;
		res[i] = j;
		vis[j] = 1;
		pre %= factory[n - 1 - i];
	}
	return res;
}
/*
1 2 3 4 5 6 7 0 8
2 3 0 1 5 6 4 7 8
*/
int main()
{
	for (int i = 0; i < 9; i++)cin >> start[i];
	for (int i = 0; i < 9; i++)cin >> goal[i];
	int num = bfs();
	if (num != -1) {
		cout << num << endl;
		int last = ans.cantor;
		while (last != s.cantor) {
			int *i;
			cantor_inv(last, 9);
			for (i = res;i<res+9; i++) {
				cout << *i << " ";
			}
			cout << endl;
			last = path[last];
			//cout << last << "  " << s.cantor;
			//if (last == s.cantor)cout << "fuck!";
		}
	}
	else cout << "impossible!" << endl;
	return 0;





}
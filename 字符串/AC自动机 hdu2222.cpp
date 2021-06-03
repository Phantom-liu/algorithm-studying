#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int trie[maxn][26], cnt;  //数组建树
int fail[maxn];
int cntword[maxn];    //记录相同单词输入的数量（本题用于判断是否出现过 出现过置为-1）
int n;
void insert(char *s) {
	int now = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		int next = s[i] - 'a';
		if (!trie[now][next]) {
			trie[now][next] = ++cnt;
			memset(trie[cnt], 0, sizeof trie[cnt]);
		}
		now = trie[now][next];
	}
	cntword[now]++;
}
void getfail() {
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (trie[0][i]) {
			fail[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[now][i]) {
				int p = fail[now];
				while (p != 0) {
					if (trie[p][i])break;
					p = fail[p];
				}
				fail[trie[now][i]] = trie[p][i];
				q.push(trie[now][i]);
			}
			else {
				trie[now][i] = trie[fail[now]][i];
			}
		}
	}
}
int query(char *s) {
	int now = 0, ans = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		now = trie[now][s[i] - 'a'];
		int p = now;
		while (p != 0) {
			if (cntword[p] != -1) {
				ans += cntword[p];
				cntword[p] = -1;
			}
			p = fail[p];
		}

	}
	return ans;
}
void initial()
{
	cnt = 0;
	memset(cntword, 0, sizeof cntword);
	memset(fail, 0, sizeof fail);
	memset(trie[0], 0, sizeof trie[0]);
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		initial();
		char tmp[maxn << 1];
		for (int i = 1; i <= n; i++) {
			scanf("%s", tmp);
			insert(tmp);
		}
		getfail();
		scanf("%s", tmp);
		cout << query(tmp) << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, p;
int sg[maxn], s[maxn];
//巴什游戏
void getsg()
{
	memset(sg, 0, sizeof sg);
	for (int i = 1; i <= n; i++) {
		if (i <= m) {
			sg[i] = i; continue;
		}
		sg[i] = sg[i-m-1];
	}
}
//尼姆游戏
int sgnim[maxn], s[maxn]; //s为是否在集合出现过
int fibo[15] = { 1,2,3,5,8,13,21,34,55,89,144,233,377,610,987 };
void getsg_nim()
{
	for (int i = 0; i <= maxn; i++) {
		sg[i] = i;
		memset(s, 0, sizeof s);
		for (int j = 0; j < 15 && fibo[j] <= i; j++) {
			s[sg[i - fibo[j]]] = 1;
		}
		for (int j = 0; j <= i; j++) {
			if (!s[j]) {
				sg[i] = j;
				break;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	getsg();
	//bash game
	if (sg[n])cout << "first" << endl;
	else cout << "second" << endl;
	//nim game
	cin >> n >> m >> p;
	getsg_nim();
	if (sg[n] ^ sg[m] ^ sg[p])cout << "fibo" << endl;
	else cout << "nacci" << endl;
	return 0;
}

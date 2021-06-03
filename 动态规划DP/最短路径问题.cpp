#include<bits/stdc++.h>
using namespace std;
int walk(int a[][100], int i, int j,int len,int high) {
	if (i == len - 1 && j == high - 1)return a[i][j];
	if (j == high - 1) {
		return a[i][j] + walk(a, i + 1, j, len, high);
	}
	if (i == len - 1) {
		return a[i][j] + walk(a, i,  j + 1, len, high);
	}
	int right = walk(a, i + 1, j, len, high);
	int down = walk(a, i, j + 1, len, high);
	return a[i][j] + min(right, down);
}

/*int main()
{
	int a[100][100];
	int l, h;
	cin >> l >> h;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < h; j++)
			cin >> a[i][j];
	}
	cout << walk(a, 0, 0, l, h) << "\n";
	return 0;
}*/

//¶¯Ì¬¹æ»®
int main()
{
	int a[100][100],res[100][100];
	int l, h;
	cin >> l >> h;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < h; j++)
			cin >> a[i][j];
	}
	clock_t start = clock();
	res[l][h - 1] = res[l - 1][h] = 0;
	for (int i = l-1; i>=0; i--)
	{
		res[i][h - 1] = res[i + 1][h - 1] + a[i][h - 1];
	}
	for (int j = h - 1; j >= 0; j--)
	{
		res[l-1][j] = res[l-1][j+1] + a[l-1][j];
	}
	for (int i = l - 2; i >= 0; i--) {
		for (int j = h - 2; j >= 0; j--) {
			res[i][j] = min(res[i + 1][j], res[i][j + 1]) + a[i][j];
		}
	}
	clock_t end = clock();
	printf("%d timespend: %dms\n", res[0][0],start-end);
	start = clock();
	int k = walk(a, 0, 0,l,h);
	end = clock();
	printf("%d timespend: %dms\n", k, start - end);
}








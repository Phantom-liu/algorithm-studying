#include<bits/stdc++.h>
using namespace std;
int least(int now,int cnt)
{
	if (now < 0)return 1e5;
	if (now == 0)return cnt;
	return min(min(least(now - 5, cnt + 1), least(now - 7, cnt + 1)),least(now - 2, cnt + 1));
}
int main()
{
	int m;
	cin >> m;
	clock_t start = clock();
	cout << least(m, 0)<<"\n";
	clock_t end = clock();
	cout << end - start << "ms" << endl;
	//DP
	start = clock();
	int res[1000];
	for (int i = 0; i <= m; i++)
	{
		res[i] = 1e6;
	}
	res[0] = 0; res[2] = res[5] = res[7] = 1;
	for (int i = 8; i <= m; i++)
	{
		res[i] = min(min(res[i - 5], res[i - 7]), res[i - 2])+1;
	}
	cout << res[m] << endl;
	end = clock();
	cout << end - start << "ms" << endl;
	return 0;
}
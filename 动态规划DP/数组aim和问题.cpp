#include<bits/stdc++.h>
using namespace std;
bool isSum(int a[], int i, int sum, int aim,int len) {
	if (i == len) {
		return sum == aim;
	}
	return isSum(a, i + 1, sum, aim,len) || isSum(a, i + 1, sum + a[i], aim,len);
}
int main()
{
	int a[100];
	for (int i = 0; i < 100; i++)
		a[i] = rand() % 100;
	clock_t start = clock();
	bool m = isSum(a, 0, 0, 1900, 18);
	clock_t end = clock();
	cout << m << "\n";
	cout << end - start << "ms" << endl;
	start = clock();
	//¶¯Ì¬¹æ»®£º
	bool res[18][2000];
	memset(res, 0, sizeof(res));
	res[17][1900] = 1;
	for (int j = 16; j >= 0; j--)
	{
		for (int i=0; i <= 1900; i++)
			res[j][i] = res[j + 1][i] || res[j + 1][i + a[j]];
	}
	end = clock();
	cout << end - start << "ms"<<endl;
	cout << res[0][0];
	return 0;
}
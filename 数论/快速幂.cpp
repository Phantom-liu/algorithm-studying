#include<iostream>
#include<ctime>
using namespace std;
const int mod = 1e4 + 7;
struct martix {
	int m[105][105];
	int col,row;
	martix(int r,int c,int d = 0) {
		row = r;
		col = c;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				m[i][j] = d;
	}
	void print() {
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++)
				cout << m[i][j] << " ";
			cout << endl;
		}
	}
};
int quickpow(int a,int n) {
	int res=1, base=a;
	while (n) {
		if (n & 1) {
			res = (res*base) % mod;
		}
		base = (base * base) % mod;
		n >>= 1;
	}
	return res;
}
martix multi_martix(martix &a, martix &b) {
	martix res(a.row, b.col);
	for (int i = 1; i <= a.row; i++) {
		for (int j = 1; j <= b.col; j++) {
			for (int k = 1; k <= a.col; k++) {
				res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
			}
		}
	}
	return res;
}
martix quickpow_martix(martix &m, int n) {
	int row = m.row, col = m.col;
	martix res(row,col);
	for (int i = 1; i <= col; i++)res.m[i][i] = 1;
	martix base(m);
	while (n) {
		if (n & 1) {
			res = multi_martix(base, res); 
		}
		base = multi_martix(base, base);
		n >>= 1;
	}
	return res;
}
int main()
{
	clock_t s = clock();
	martix a(100, 100, 1);
	quickpow_martix(a, 3000000);
	//a.print();
	clock_t e = clock();
	cout << e - s << endl;
	return 0;
}
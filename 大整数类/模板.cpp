#include<bits/stdc++.h>
using namespace std;
const int BASE = 10000000;
static const int WIDTH = 7;
struct BigInt
{
	vector<int> s;
	BigInt(long long num = 0) { *this = num; }
	BigInt operator = (const string str)
	{
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for (int i = 0; i < len; i++)
		{
			int end = str.length() - i * WIDTH;
			int start = max(0, end - WIDTH);
			sscanf_s(str.substr(start, end - start).c_str(), "%d ", &x);
			s.push_back(x);
		}
		return *this;
	}
	BigInt operator = (long long num)
	{
		s.clear();
		do
		{
			s.push_back(num%BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}
	BigInt operator=(BigInt num) {
		s.clear();
		for (int i = 0; i < num.s.size(); i++)s.push_back(num.s[i]);
		return *this;
	}
};

ostream& operator<<(ostream &out, BigInt &s)
{
	for (int i=s.s.size()-1;i>=0;i--)
		out << s.s[i]<<" ";
	return out;
}
void print(BigInt s)
{
	printf("%d", s.s[s.s.size() - 1]);
	for (int i = s.s.size() - 2; i >= 0; i--)
		printf("%07d", s.s[i]);
}
BigInt operator +(const BigInt &a, const BigInt &b)
{
	BigInt c;
	c.s.clear();
	int alen = a.s.size(), blen = b.s.size();
	for (int i = 0, g = 0;; i++)
	{
		if (g == 0&&i >= alen && i >= blen)break;
		int x = g;
		if (i < alen)x += a.s[i];
		if (i < blen)x += b.s[i];
		c.s.push_back(x % BASE);
		g = x / BASE;
	}
	return c;
}

BigInt operator *(const BigInt &a, const BigInt &b)
{
	BigInt c;
	c.s.clear();
	int alen = a.s.size(), blen = b.s.size();
	for (int i = 0, g = 0;; i++)
	{
		if (i >= alen + blen-1&&g==0)break;
		long long sum = 0;
		for (int j = max(0,i-blen+1);j<=i&&j<alen; j++) {
			sum += (long long)(a.s[j])*(long long)(b.s[i - j]);
		}
		sum += g;
		c.s.push_back(sum%BASE);
		g = sum / BASE;
	}
	return c;
}
int main() {
	int n;
	cin >> n;
	BigInt res = 1;
	clock_t s = clock();
	for (int i = 2; i <= n; i++)
	{
		BigInt k = i;
		res = res * k;
	}
	print(res);
	clock_t e = clock();
	cout << endl << e - s;
	return 0;
}